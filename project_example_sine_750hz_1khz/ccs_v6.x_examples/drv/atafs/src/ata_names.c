/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/********************************************************************************/
/* $Id: ata_names.c,2.4+ $													    */
/*										    									*/
/* This is proprietary information, not to be published -- TI INTERNAL DATA   	*/
/* Copyright (C) 2000, Texas Instruments, Inc.  All Rights Reserved.		  	*/
/*																				*/
/* Author: Susmit Pal													  		*/
/* Date: November 6, 2002														*/
/* Modified Date: November 28, 2002												*/
/* Last Modified Date: February 11, 2003										*/
/* April 26, 2010 - added check for NULL pointer KR042610                       */
/********************************************************************************/

#include <string.h>
#include <ctype.h>
#include "ata.h"
#include "ata_.h"

AtaError ATA_setFileName(AtaFile *pAtaFile, char *name, char *ext)
{

  int i=0;

  if (pAtaFile==NULL) return(ATA_ERROR_INVALID_PARAM); //KR042610

  for(i=0;i<strlen(name);i++) name[i]=toupper(name[i]);
  for(i=0;i<strlen(ext);i++) ext[i]=toupper(ext[i]);
  memmove((char *)pAtaFile->Filename, "        ",9);
  memmove((char *)pAtaFile->Filename, name,strlen(name));
  memmove((char *)pAtaFile->Ext,"   ",4);
  memmove((char *)pAtaFile->Ext,ext,strlen(ext));

  pAtaFile->Attributes = ATA_ATTR_ARCHIVE;
  pAtaFile->Time = pAtaFile->pDrive->get_time();
  pAtaFile->Date = pAtaFile->pDrive->get_date();
  pAtaFile->reserved1 = 0x0BAD;
  return(ATA_ERROR_NONE);
}

AtaError ATA_setDirectoryName(AtaFile *pAtaFile, char *dirname)
{
  int i=0;

  if (pAtaFile==NULL) return(ATA_ERROR_INVALID_PARAM); //KR042610

  for(i=0;i<strlen(dirname);i++) dirname[i]=toupper(dirname[i]);
  memmove((char *)pAtaFile->Filename, "        ",9);
  memmove((char *)pAtaFile->Filename, dirname,strlen(dirname));
  memmove((char *)pAtaFile->Ext,"   ",4); /*SUSMIT - Long Directory with Ext Creation Bugfix*/

  pAtaFile->Attributes = ATA_ATTR_DIRECTORY;
  pAtaFile->Time = pAtaFile->pDrive->get_time();
  pAtaFile->Date = pAtaFile->pDrive->get_date();
  pAtaFile->reserved1 = 0x0BAD;
  return(ATA_ERROR_NONE);
}

AtaError ATA_setDateTime(AtaFile *pAtaFile)
{
  AtaUint16 jj;
  AtaUint32 ll;
  AtaState *pAtaDrive=pAtaFile->pDrive;
  AtaError ret_stat = ATA_ERROR_NONE;
  AtaUint16 *_AtaWriteBuffer = pAtaDrive->_AtaWriteBuffer;

  if (pAtaFile==NULL) return(ATA_ERROR_INVALID_PARAM); //KR042610

  ll = _AtaCalculatePhySectorAndOffsetFromDirEntry((AtaUint32)pAtaFile->CurrentDirEntry, (AtaUint16 *)&jj, pAtaFile, &ret_stat);
  if(ret_stat) return(ret_stat);
  ret_stat = _AtaReadSector(ll, pAtaDrive, &_AtaWriteBuffer[0], 0);
  if(ret_stat) return(ret_stat);

  /*  Update directory entry*/
  jj+=11;
  _AtaWriteBuffer[jj++] = pAtaFile->Time = pAtaDrive->get_mod_time();
  _AtaWriteBuffer[jj] = pAtaFile->Date = pAtaDrive->get_mod_date();

  /*  Commit replacement directory entry sector to disk*/
  ret_stat = _AtaFlush(pAtaDrive);
  if(ret_stat) return(ret_stat);
  ret_stat = pAtaDrive->AtaWriteSector(ll, pAtaDrive->pAtaMediaState, &_AtaWriteBuffer[0], 0);
  if(ret_stat) return(ret_stat);
  ret_stat = pAtaDrive->AtaWriteSectorFlush(pAtaDrive->pAtaMediaState);
  return(ret_stat);
}

AtaError ATA_setAttr(AtaFile *pAtaFile, AtaUint16 Attr)
{
  AtaUint16 jj;
  AtaUint32 ll;
  AtaState *pAtaDrive=pAtaFile->pDrive;
  AtaError ret_stat = ATA_ERROR_NONE;
  AtaUint16 *_AtaWriteBuffer = pAtaDrive->_AtaWriteBuffer;

  if (pAtaFile==NULL) return(ATA_ERROR_INVALID_PARAM); //KR042610

  ll = _AtaCalculatePhySectorAndOffsetFromDirEntry((AtaUint32)pAtaFile->CurrentDirEntry, (AtaUint16 *)&jj, pAtaFile, &ret_stat);
  if(ret_stat) return(ret_stat);
  ret_stat = _AtaReadSector(ll, pAtaDrive, &_AtaWriteBuffer[0], 0);
  if(ret_stat) return(ret_stat);

  /*  Update directory entry*/
  jj+=5;
/*  _AtaWriteBuffer[jj] |= Attr << 8;*/  /*SUSMIT - Absolute attribute setting BUGGIX*/
  _AtaWriteBuffer[jj] &= 0x00ff;
  _AtaWriteBuffer[jj] |= Attr << 8;
  pAtaFile->Attributes = Attr;

  /*  Commit replacement directory entry sector to disk*/
  ret_stat = _AtaFlush(pAtaDrive);
  if(ret_stat) return(ret_stat);
  ret_stat = pAtaDrive->AtaWriteSector(ll, pAtaDrive->pAtaMediaState, &_AtaWriteBuffer[0], 0);
  if(ret_stat) return(ret_stat);
  ret_stat = pAtaDrive->AtaWriteSectorFlush(pAtaDrive->pAtaMediaState);
  return(ret_stat);
}

