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


#ifndef _CSLR__MMCSD_1_H_
#define _CSLR__MMCSD_1_H_

#include <cslr.h>
/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 MMCCTL;
    volatile Uint16 RSVD0[3];
    volatile Uint16 MMCCLK;
    volatile Uint16 RSVD1[3];
    volatile Uint16 MMCST0;
    volatile Uint16 RSVD2[3];
    volatile Uint16 MMCST1;
    volatile Uint16 RSVD3[3];
    volatile Uint16 MMCIM;
    volatile Uint16 RSVD4[3];
    volatile Uint16 MMCTOR;
    volatile Uint16 RSVD5[3];
    volatile Uint16 MMCTODL;
    volatile Uint16 MMCTODH;
    volatile Uint16 RSVD6[2];
    volatile Uint16 MMCBLEN;
    volatile Uint16 RSVD7[3];
    volatile Uint16 MMCNBLK;
    volatile Uint16 RSVD8[3];
    volatile Uint16 MMCNBLC;
    volatile Uint16 RSVD9[3];
    volatile Uint16 MMCDRRL;
    volatile Uint16 MMCDRRH;
    volatile Uint16 RSVD10[2];
    volatile Uint16 MMCDXRL;
    volatile Uint16 MMCDXRH;
    volatile Uint16 RSVD11[2];
    volatile Uint16 MMCCMDL;
    volatile Uint16 MMCCMDH;
    volatile Uint16 RSVD12[2];
    volatile Uint16 MMCARGL;
    volatile Uint16 MMCARGH;
    volatile Uint16 RSVD13[2];
    volatile Uint16 MMCRSP0;
    volatile Uint16 MMCRSP1;
    volatile Uint16 RSVD14[2];
    volatile Uint16 MMCRSP2;
    volatile Uint16 MMCRSP3;
    volatile Uint16 RSVD15[2];
    volatile Uint16 MMCRSP4;
    volatile Uint16 MMCRSP5;
    volatile Uint16 RSVD16[2];
    volatile Uint16 MMCRSP6;
    volatile Uint16 MMCRSP7;
    volatile Uint16 RSVD17[2];
    volatile Uint16 MMCDRSP;
    volatile Uint16 RSVD18[3];
    volatile Uint16 MMCETOK;
    volatile Uint16 RSVD19[3];
    volatile Uint16 MMCCIDX;
    volatile Uint16 RSVD20[3];
    volatile Uint16 MMCCKC;
    volatile Uint16 RSVD21[3];
    volatile Uint16 MMCTORC;
    volatile Uint16 RSVD22[3];
    volatile Uint16 MMCTODC;
    volatile Uint16 RSVD23[3];
    volatile Uint16 MMCBLNC;
    volatile Uint16 RSVD24[3];
    volatile Uint16 SDIOCTL;
    volatile Uint16 RSVD25[3];
    volatile Uint16 SDIOST0;
    volatile Uint16 RSVD26[3];
    volatile Uint16 SDIOIEN;
    volatile Uint16 RSVD27[3];
    volatile Uint16 SDIOIST ;
    volatile Uint16 RSVD28[3];
    volatile Uint16 MMCFIFOCTL;
} CSL_MmcsdDrvRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* MMCCTL */


#define CSL_MMCSD_MMCCTL_PERMDX_MASK (0x0400u)
#define CSL_MMCSD_MMCCTL_PERMDX_SHIFT (0x000Au)
#define CSL_MMCSD_MMCCTL_PERMDX_RESETVAL (0x0000u)
/*----PERMDX Tokens----*/
#define CSL_MMCSD_MMCCTL_PERMDX_LEND (0x0000u)
#define CSL_MMCSD_MMCCTL_PERMDX_BEND (0x0001u)

#define CSL_MMCSD_MMCCTL_PERMDR_MASK (0x0200u)
#define CSL_MMCSD_MMCCTL_PERMDR_SHIFT (0x0009u)
#define CSL_MMCSD_MMCCTL_PERMDR_RESETVAL (0x0000u)
/*----PERMDR Tokens----*/
#define CSL_MMCSD_MMCCTL_PERMDR_LEND (0x0000u)
#define CSL_MMCSD_MMCCTL_PERMDR_BEND (0x0001u)


#define CSL_MMCSD_MMCCTL_DATEG_MASK (0x00C0u)
#define CSL_MMCSD_MMCCTL_DATEG_SHIFT (0x0006u)
#define CSL_MMCSD_MMCCTL_DATEG_RESETVAL (0x0000u)
/*----DATEG Tokens----*/
#define CSL_MMCSD_MMCCTL_DATEG_DISABLE (0x0000u)
#define CSL_MMCSD_MMCCTL_DATEG_R_EDGE (0x0001u)
#define CSL_MMCSD_MMCCTL_DATEG_F_EDGE (0x0002u)
#define CSL_MMCSD_MMCCTL_DATEG_RF_EDGE (0x0003u)


#define CSL_MMCSD_MMCCTL_WIDTH_MASK (0x0004u)
#define CSL_MMCSD_MMCCTL_WIDTH_SHIFT (0x0002u)
#define CSL_MMCSD_MMCCTL_WIDTH_RESETVAL (0x0000u)
/*----WIDTH Tokens----*/
#define CSL_MMCSD_MMCCTL_WIDTH_BIT1 (0x0000u)
#define CSL_MMCSD_MMCCTL_WIDTH_BIT4 (0x0001u)

#define CSL_MMCSD_MMCCTL_CMDRST_MASK (0x0002u)
#define CSL_MMCSD_MMCCTL_CMDRST_SHIFT (0x0001u)
#define CSL_MMCSD_MMCCTL_CMDRST_RESETVAL (0x0000u)
/*----CMDRST Tokens----*/
#define CSL_MMCSD_MMCCTL_CMDRST_ENABLE (0x0000u)
#define CSL_MMCSD_MMCCTL_CMDRST_DISABLE (0x0001u)

#define CSL_MMCSD_MMCCTL_DATRST_MASK (0x0001u)
#define CSL_MMCSD_MMCCTL_DATRST_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCTL_DATRST_RESETVAL (0x0000u)
/*----DATRST Tokens----*/
#define CSL_MMCSD_MMCCTL_DATRST_ENABLE (0x0000u)
#define CSL_MMCSD_MMCCTL_DATRST_DISABLE (0x0001u)

#define CSL_MMCSD_MMCCTL_RESETVAL (0x0000u)

/* MMCCLK */


#define CSL_MMCSD_MMCCLK_CLKEN_MASK (0x0100u)
#define CSL_MMCSD_MMCCLK_CLKEN_SHIFT (0x0008u)
#define CSL_MMCSD_MMCCLK_CLKEN_RESETVAL (0x0000u)
/*----CLKEN Tokens----*/
#define CSL_MMCSD_MMCCLK_CLKEN_DISABLE (0x0000u)
#define CSL_MMCSD_MMCCLK_CLKEN_ENABLE (0x0001u)

#define CSL_MMCSD_MMCCLK_CLKRT_MASK (0x00FFu)
#define CSL_MMCSD_MMCCLK_CLKRT_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCLK_CLKRT_RESETVAL (0x00FFu)

#define CSL_MMCSD_MMCCLK_RESETVAL (0x00FFu)

/* MMCST0 */


#define CSL_MMCSD_MMCST0_TRNDNE_MASK (0x1000u)
#define CSL_MMCSD_MMCST0_TRNDNE_SHIFT (0x000Cu)
#define CSL_MMCSD_MMCST0_TRNDNE_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_DATED_MASK (0x0800u)
#define CSL_MMCSD_MMCST0_DATED_SHIFT (0x000Bu)
#define CSL_MMCSD_MMCST0_DATED_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_DRRDY_MASK (0x0400u)
#define CSL_MMCSD_MMCST0_DRRDY_SHIFT (0x000Au)
#define CSL_MMCSD_MMCST0_DRRDY_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_DXRDY_MASK (0x0200u)
#define CSL_MMCSD_MMCST0_DXRDY_SHIFT (0x0009u)
#define CSL_MMCSD_MMCST0_DXRDY_RESETVAL (0x0001u)


#define CSL_MMCSD_MMCST0_CRCRS_MASK (0x0080u)
#define CSL_MMCSD_MMCST0_CRCRS_SHIFT (0x0007u)
#define CSL_MMCSD_MMCST0_CRCRS_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_CRCRD_MASK (0x0040u)
#define CSL_MMCSD_MMCST0_CRCRD_SHIFT (0x0006u)
#define CSL_MMCSD_MMCST0_CRCRD_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_CRCWR_MASK (0x0020u)
#define CSL_MMCSD_MMCST0_CRCWR_SHIFT (0x0005u)
#define CSL_MMCSD_MMCST0_CRCWR_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_TOUTRS_MASK (0x0010u)
#define CSL_MMCSD_MMCST0_TOUTRS_SHIFT (0x0004u)
#define CSL_MMCSD_MMCST0_TOUTRS_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_TOUTRD_MASK (0x0008u)
#define CSL_MMCSD_MMCST0_TOUTRD_SHIFT (0x0003u)
#define CSL_MMCSD_MMCST0_TOUTRD_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_RSPDNE_MASK (0x0004u)
#define CSL_MMCSD_MMCST0_RSPDNE_SHIFT (0x0002u)
#define CSL_MMCSD_MMCST0_RSPDNE_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_BSYDNE_MASK (0x0002u)
#define CSL_MMCSD_MMCST0_BSYDNE_SHIFT (0x0001u)
#define CSL_MMCSD_MMCST0_BSYDNE_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_DATDNE_MASK (0x0001u)
#define CSL_MMCSD_MMCST0_DATDNE_SHIFT (0x0000u)
#define CSL_MMCSD_MMCST0_DATDNE_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST0_RESETVAL (0x0200u)

/* MMCST1 */


#define CSL_MMCSD_MMCST1_FIFOFUL_MASK (0x0040u)
#define CSL_MMCSD_MMCST1_FIFOFUL_SHIFT (0x0006u)
#define CSL_MMCSD_MMCST1_FIFOFUL_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_FIFOEMP_MASK (0x0020u)
#define CSL_MMCSD_MMCST1_FIFOEMP_SHIFT (0x0005u)
#define CSL_MMCSD_MMCST1_FIFOEMP_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_DAT3ST_MASK (0x0010u)
#define CSL_MMCSD_MMCST1_DAT3ST_SHIFT (0x0004u)
#define CSL_MMCSD_MMCST1_DAT3ST_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_DRFUL_MASK (0x0008u)
#define CSL_MMCSD_MMCST1_DRFUL_SHIFT (0x0003u)
#define CSL_MMCSD_MMCST1_DRFUL_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_DXEMP_MASK (0x0004u)
#define CSL_MMCSD_MMCST1_DXEMP_SHIFT (0x0002u)
#define CSL_MMCSD_MMCST1_DXEMP_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_CLKSTP_MASK (0x0002u)
#define CSL_MMCSD_MMCST1_CLKSTP_SHIFT (0x0001u)
#define CSL_MMCSD_MMCST1_CLKSTP_RESETVAL (0x0001u)

#define CSL_MMCSD_MMCST1_BUSY_MASK (0x0001u)
#define CSL_MMCSD_MMCST1_BUSY_SHIFT (0x0000u)
#define CSL_MMCSD_MMCST1_BUSY_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCST1_RESETVAL (0x0002u)

/* MMCIM */


#define CSL_MMCSD_MMCIM_ETRNDNE_MASK (0x1000u)
#define CSL_MMCSD_MMCIM_ETRNDNE_SHIFT (0x000Cu)
#define CSL_MMCSD_MMCIM_ETRNDNE_RESETVAL (0x0000u)
/*----ETRNDNE Tokens----*/
#define CSL_MMCSD_MMCIM_ETRNDNE_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ETRNDNE_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_EDATED_MASK (0x0800u)
#define CSL_MMCSD_MMCIM_EDATED_SHIFT (0x000Bu)
#define CSL_MMCSD_MMCIM_EDATED_RESETVAL (0x0000u)
/*----EDATED Tokens----*/
#define CSL_MMCSD_MMCIM_EDATED_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_EDATED_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_EDRRDY_MASK (0x0400u)
#define CSL_MMCSD_MMCIM_EDRRDY_SHIFT (0x000Au)
#define CSL_MMCSD_MMCIM_EDRRDY_RESETVAL (0x0000u)
/*----EDRRDY Tokens----*/
#define CSL_MMCSD_MMCIM_EDRRDY_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_EDRRDY_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_EDXRDY_MASK (0x0200u)
#define CSL_MMCSD_MMCIM_EDXRDY_SHIFT (0x0009u)
#define CSL_MMCSD_MMCIM_EDXRDY_RESETVAL (0x0000u)
/*----EDXRDY Tokens----*/
#define CSL_MMCSD_MMCIM_EDXRDY_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_EDXRDY_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ESPIERR_MASK (0x0100u)
#define CSL_MMCSD_MMCIM_ESPIERR_SHIFT (0x0008u)
#define CSL_MMCSD_MMCIM_ESPIERR_RESETVAL (0x0000u)
/*----ESPIERR Tokens----*/
#define CSL_MMCSD_MMCIM_ESPIERR_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ESPIERR_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ECRCRS_MASK (0x0080u)
#define CSL_MMCSD_MMCIM_ECRCRS_SHIFT (0x0007u)
#define CSL_MMCSD_MMCIM_ECRCRS_RESETVAL (0x0000u)
/*----ECRCRS Tokens----*/
#define CSL_MMCSD_MMCIM_ECRCRS_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ECRCRS_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ECRCRD_MASK (0x0040u)
#define CSL_MMCSD_MMCIM_ECRCRD_SHIFT (0x0006u)
#define CSL_MMCSD_MMCIM_ECRCRD_RESETVAL (0x0000u)
/*----ECRCRD Tokens----*/
#define CSL_MMCSD_MMCIM_ECRCRD_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ECRCRD_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ECRCWR_MASK (0x0020u)
#define CSL_MMCSD_MMCIM_ECRCWR_SHIFT (0x0005u)
#define CSL_MMCSD_MMCIM_ECRCWR_RESETVAL (0x0000u)
/*----ECRCWR Tokens----*/
#define CSL_MMCSD_MMCIM_ECRCWR_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ECRCWR_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ETOUTRS_MASK (0x0010u)
#define CSL_MMCSD_MMCIM_ETOUTRS_SHIFT (0x0004u)
#define CSL_MMCSD_MMCIM_ETOUTRS_RESETVAL (0x0000u)
/*----ETOUTRS Tokens----*/
#define CSL_MMCSD_MMCIM_ETOUTRS_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ETOUTRS_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ETOUTRD_MASK (0x0008u)
#define CSL_MMCSD_MMCIM_ETOUTRD_SHIFT (0x0003u)
#define CSL_MMCSD_MMCIM_ETOUTRD_RESETVAL (0x0000u)
/*----ETOUTRD Tokens----*/
#define CSL_MMCSD_MMCIM_ETOUTRD_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ETOUTRD_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_ERSPDNE_MASK (0x0004u)
#define CSL_MMCSD_MMCIM_ERSPDNE_SHIFT (0x0002u)
#define CSL_MMCSD_MMCIM_ERSPDNE_RESETVAL (0x0000u)
/*----ERSPDNE Tokens----*/
#define CSL_MMCSD_MMCIM_ERSPDNE_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_ERSPDNE_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_EBSYDNE_MASK (0x0002u)
#define CSL_MMCSD_MMCIM_EBSYDNE_SHIFT (0x0001u)
#define CSL_MMCSD_MMCIM_EBSYDNE_RESETVAL (0x0000u)
/*----EBSYDNE Tokens----*/
#define CSL_MMCSD_MMCIM_EBSYDNE_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_EBSYDNE_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_EDATDNE_MASK (0x0001u)
#define CSL_MMCSD_MMCIM_EDATDNE_SHIFT (0x0000u)
#define CSL_MMCSD_MMCIM_EDATDNE_RESETVAL (0x0000u)
/*----EDATDNE Tokens----*/
#define CSL_MMCSD_MMCIM_EDATDNE_PROHIBIT (0x0000u)
#define CSL_MMCSD_MMCIM_EDATDNE_PERMIT (0x0001u)

#define CSL_MMCSD_MMCIM_RESETVAL (0x0000u)

/* MMCTOR */


#define CSL_MMCSD_MMCTOR_TOD_20_16_MASK (0x1F00u)
#define CSL_MMCSD_MMCTOR_TOD_20_16_SHIFT (0x0008u)
#define CSL_MMCSD_MMCTOR_TOD_20_16_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTOR_TOR_MASK (0x00FFu)
#define CSL_MMCSD_MMCTOR_TOR_SHIFT (0x0000u)
#define CSL_MMCSD_MMCTOR_TOR_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTOR_RESETVAL (0x0000u)

/* MMCTODL */

#define CSL_MMCSD_MMCTODL_TOD_15_0_MASK (0xFFFFu)
#define CSL_MMCSD_MMCTODL_TOD_15_0_SHIFT (0x0000u)
#define CSL_MMCSD_MMCTODL_TOD_15_0_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTODL_RESETVAL (0x0000u)

/* MMCTODH */


#define CSL_MMCSD_MMCTODH_TOD_23_15_MASK (0x00FFu)
#define CSL_MMCSD_MMCTODH_TOD_23_15_SHIFT (0x0000u)
#define CSL_MMCSD_MMCTODH_TOD_23_15_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTODH_RESETVAL (0x0000u)

/* MMCBLEN */


#define CSL_MMCSD_MMCBLEN_BLEN_MASK (0x0FFFu)
#define CSL_MMCSD_MMCBLEN_BLEN_SHIFT (0x0000u)
#define CSL_MMCSD_MMCBLEN_BLEN_RESETVAL (0x0200u)

#define CSL_MMCSD_MMCBLEN_RESETVAL (0x0200u)

/* MMCNBLK */

#define CSL_MMCSD_MMCNBLK_NBLK_MASK (0xFFFFu)
#define CSL_MMCSD_MMCNBLK_NBLK_SHIFT (0x0000u)
#define CSL_MMCSD_MMCNBLK_NBLK_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCNBLK_RESETVAL (0x0000u)

/* MMCNBLC */

#define CSL_MMCSD_MMCNBLC_NBLC_MASK (0xFFFFu)
#define CSL_MMCSD_MMCNBLC_NBLC_SHIFT (0x0000u)
#define CSL_MMCSD_MMCNBLC_NBLC_RESETVAL (0xFFFFu)

#define CSL_MMCSD_MMCNBLC_RESETVAL (0xFFFFu)

/* MMCDRRL */

#define CSL_MMCSD_MMCDRRL_DRRL_MASK (0xFFFFu)
#define CSL_MMCSD_MMCDRRL_DRRL_SHIFT (0x0000u)
#define CSL_MMCSD_MMCDRRL_DRRL_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCDRRL_RESETVAL (0x0000u)

/* MMCDRRH */

#define CSL_MMCSD_MMCDRRH_DRRH_MASK (0xFFFFu)
#define CSL_MMCSD_MMCDRRH_DRRH_SHIFT (0x0000u)
#define CSL_MMCSD_MMCDRRH_DRRH_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCDRRH_RESETVAL (0x0000u)

/* MMCDXRL */

#define CSL_MMCSD_MMCDXRL_DXRL_MASK (0xFFFFu)
#define CSL_MMCSD_MMCDXRL_DXRL_SHIFT (0x0000u)
#define CSL_MMCSD_MMCDXRL_DXRL_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCDXRL_RESETVAL (0x0000u)

/* MMCDXRH */

#define CSL_MMCSD_MMCDXRH_DXRH_MASK (0xFFFFu)
#define CSL_MMCSD_MMCDXRH_DXRH_SHIFT (0x0000u)
#define CSL_MMCSD_MMCDXRH_DXRH_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCDXRH_RESETVAL (0x0000u)

/* MMCCMDL */

#define CSL_MMCSD_MMCCMDL_DCLR_MASK (0x8000u)
#define CSL_MMCSD_MMCCMDL_DCLR_SHIFT (0x000Fu)
#define CSL_MMCSD_MMCCMDL_DCLR_RESETVAL (0x0000u)
/*----DCLR Tokens----*/
#define CSL_MMCSD_MMCCMDL_DCLR_NO (0x0000u)
#define CSL_MMCSD_MMCCMDL_DCLR_CLEAR (0x0001u)

#define CSL_MMCSD_MMCCMDL_INITCK_MASK (0x4000u)
#define CSL_MMCSD_MMCCMDL_INITCK_SHIFT (0x000Eu)
#define CSL_MMCSD_MMCCMDL_INITCK_RESETVAL (0x0000u)
/*----INITCK Tokens----*/
#define CSL_MMCSD_MMCCMDL_INITCK_NO (0x0000u)
#define CSL_MMCSD_MMCCMDL_INITCK_INIT (0x0001u)

#define CSL_MMCSD_MMCCMDL_WDATX_MASK (0x2000u)
#define CSL_MMCSD_MMCCMDL_WDATX_SHIFT (0x000Du)
#define CSL_MMCSD_MMCCMDL_WDATX_RESETVAL (0x0000u)
/*----WDATX Tokens----*/
#define CSL_MMCSD_MMCCMDL_WDATX_NO (0x0000u)
#define CSL_MMCSD_MMCCMDL_WDATX_DATA (0x0001u)

#define CSL_MMCSD_MMCCMDL_STRMTP_MASK (0x1000u)
#define CSL_MMCSD_MMCCMDL_STRMTP_SHIFT (0x000Cu)
#define CSL_MMCSD_MMCCMDL_STRMTP_RESETVAL (0x0000u)
/*----STRMTP Tokens----*/
#define CSL_MMCSD_MMCCMDL_STRMTP_BLOCK (0x0000u)
#define CSL_MMCSD_MMCCMDL_STRMTP_STREAM (0x0001u)
#define CSL_MMCSD_MMCCMDL_STRMTP_NO (0x0000u)

#define CSL_MMCSD_MMCCMDL_DTRW_MASK (0x0800u)
#define CSL_MMCSD_MMCCMDL_DTRW_SHIFT (0x000Bu)
#define CSL_MMCSD_MMCCMDL_DTRW_RESETVAL (0x0000u)
/*----DTRW Tokens----*/
#define CSL_MMCSD_MMCCMDL_DTRW_READ (0x0000u)
#define CSL_MMCSD_MMCCMDL_DTRW_WRITE (0x0001u)
#define CSL_MMCSD_MMCCMDL_DTRW_NO (0x0000u)

#define CSL_MMCSD_MMCCMDL_RSPFMT_MASK (0x0600u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_SHIFT (0x0009u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_RESETVAL (0x0000u)
/*----RSPFMT Tokens----*/
#define CSL_MMCSD_MMCCMDL_RSPFMT_NORSP (0x0000u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R1 (0x0001u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R2 (0x0002u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R3 (0x0003u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R4 (0x0001u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R5 (0x0001u)
#define CSL_MMCSD_MMCCMDL_RSPFMT_R6 (0x0001u)

#define CSL_MMCSD_MMCCMDL_BSYEXP_MASK (0x0100u)
#define CSL_MMCSD_MMCCMDL_BSYEXP_SHIFT (0x0008u)
#define CSL_MMCSD_MMCCMDL_BSYEXP_RESETVAL (0x0000u)
/*----BSYEXP Tokens----*/
#define CSL_MMCSD_MMCCMDL_BSYEXP_NO (0x0000u)
#define CSL_MMCSD_MMCCMDL_BSYEXP_BUSY (0x0001u)

#define CSL_MMCSD_MMCCMDL_PPLEN_MASK (0x0080u)
#define CSL_MMCSD_MMCCMDL_PPLEN_SHIFT (0x0007u)
#define CSL_MMCSD_MMCCMDL_PPLEN_RESETVAL (0x0000u)
/*----PPLEN Tokens----*/
#define CSL_MMCSD_MMCCMDL_PPLEN_OD (0x0000u)
#define CSL_MMCSD_MMCCMDL_PPLEN_PP (0x0001u)


#define CSL_MMCSD_MMCCMDL_CMD_MASK (0x003Fu)
#define CSL_MMCSD_MMCCMDL_CMD_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCMDL_CMD_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCCMDL_RESETVAL (0x0000u)

/* MMCCMDH */


#define CSL_MMCSD_MMCCMDH_DMATRIG_MASK (0x0001u)
#define CSL_MMCSD_MMCCMDH_DMATRIG_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCMDH_DMATRIG_RESETVAL (0x0000u)
/*----DMATRIG Tokens----*/
#define CSL_MMCSD_MMCCMDH_DMATRIG_NO (0x0000u)

#define CSL_MMCSD_MMCCMDH_RESETVAL (0x0000u)

/* MMCARGL */

#define CSL_MMCSD_MMCARGL_ARGL_MASK (0xFFFFu)
#define CSL_MMCSD_MMCARGL_ARGL_SHIFT (0x0000u)
#define CSL_MMCSD_MMCARGL_ARGL_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCARGL_RESETVAL (0x0000u)

/* MMCARGH */

#define CSL_MMCSD_MMCARGH_ARGH_MASK (0xFFFFu)
#define CSL_MMCSD_MMCARGH_ARGH_SHIFT (0x0000u)
#define CSL_MMCSD_MMCARGH_ARGH_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCARGH_RESETVAL (0x0000u)

/* MMCRSP0 */

#define CSL_MMCSD_MMCRSP0_MMCRSP0_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP0_MMCRSP0_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP0_MMCRSP0_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP0_RESETVAL (0x0000u)

/* MMCRSP1 */

#define CSL_MMCSD_MMCRSP1_MMCRSP1_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP1_MMCRSP1_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP1_MMCRSP1_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP1_RESETVAL (0x0000u)

/* MMCRSP2 */

#define CSL_MMCSD_MMCRSP2_MMCRSP2_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP2_MMCRSP2_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP2_MMCRSP2_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP2_RESETVAL (0x0000u)

/* MMCRSP3 */

#define CSL_MMCSD_MMCRSP3_MMCRSP3_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP3_MMCRSP3_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP3_MMCRSP3_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP3_RESETVAL (0x0000u)

/* MMCRSP4 */

#define CSL_MMCSD_MMCRSP4_MMCRSP4_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP4_MMCRSP4_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP4_MMCRSP4_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP4_RESETVAL (0x0000u)

/* MMCRSP5 */

#define CSL_MMCSD_MMCRSP5_MMCRSP5_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP5_MMCRSP5_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP5_MMCRSP5_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP5_RESETVAL (0x0000u)

/* MMCRSP6 */

#define CSL_MMCSD_MMCRSP6_MMCRSP6_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP6_MMCRSP6_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP6_MMCRSP6_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP6_RESETVAL (0x0000u)

/* MMCRSP7 */

#define CSL_MMCSD_MMCRSP7_MMCRSP7_MASK (0xFFFFu)
#define CSL_MMCSD_MMCRSP7_MMCRSP7_SHIFT (0x0000u)
#define CSL_MMCSD_MMCRSP7_MMCRSP7_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCRSP7_RESETVAL (0x0000u)

/* MMCDRSP */


#define CSL_MMCSD_MMCDRSP_DRSP_MASK (0x00FFu)
#define CSL_MMCSD_MMCDRSP_DRSP_SHIFT (0x0000u)
#define CSL_MMCSD_MMCDRSP_DRSP_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCDRSP_RESETVAL (0x0000u)

/* MMCETOK */


#define CSL_MMCSD_MMCETOK_RESETVAL (0x0000u)

/* MMCCIDX */


#define CSL_MMCSD_MMCCIDX_STRT_MASK (0x0080u)
#define CSL_MMCSD_MMCCIDX_STRT_SHIFT (0x0007u)
#define CSL_MMCSD_MMCCIDX_STRT_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCCIDX_XMIT_MASK (0x0040u)
#define CSL_MMCSD_MMCCIDX_XMIT_SHIFT (0x0006u)
#define CSL_MMCSD_MMCCIDX_XMIT_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCCIDX_CIDX_MASK (0x003Fu)
#define CSL_MMCSD_MMCCIDX_CIDX_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCIDX_CIDX_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCCIDX_RESETVAL (0x0000u)

/* MMCCKC */


#define CSL_MMCSD_MMCCKC_CPHA_MASK (0x00FFu)
#define CSL_MMCSD_MMCCKC_CPHA_SHIFT (0x0000u)
#define CSL_MMCSD_MMCCKC_CPHA_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCCKC_RESETVAL (0x0000u)

/* MMCTORC */


#define CSL_MMCSD_MMCTORC_TODC_20_16_MASK (0x1F00u)
#define CSL_MMCSD_MMCTORC_TODC_20_16_SHIFT (0x0008u)
#define CSL_MMCSD_MMCTORC_TODC_20_16_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTORC_TORC_MASK (0x00FFu)
#define CSL_MMCSD_MMCTORC_TORC_SHIFT (0x0000u)
#define CSL_MMCSD_MMCTORC_TORC_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTORC_RESETVAL (0x0000u)

/* MMCTODC */

#define CSL_MMCSD_MMCTODC_TODC_15_0_MASK (0xFFFFu)
#define CSL_MMCSD_MMCTODC_TODC_15_0_SHIFT (0x0000u)
#define CSL_MMCSD_MMCTODC_TODC_15_0_RESETVAL (0x0000u)

#define CSL_MMCSD_MMCTODC_RESETVAL (0x0000u)

/* MMCBLNC */


#define CSL_MMCSD_MMCBLNC_BLNC_MASK (0x00FFu)
#define CSL_MMCSD_MMCBLNC_BLNC_SHIFT (0x0000u)
#define CSL_MMCSD_MMCBLNC_BLNC_RESETVAL (0x0001u)

#define CSL_MMCSD_MMCBLNC_RESETVAL (0x0001u)

/* SDIOCTL */


#define CSL_MMCSD_SDIOCTL_RDWTCR_MASK (0x0002u)
#define CSL_MMCSD_SDIOCTL_RDWTCR_SHIFT (0x0001u)
#define CSL_MMCSD_SDIOCTL_RDWTCR_RESETVAL (0x0000u)
/*----RDWTCR Tokens----*/
#define CSL_MMCSD_SDIOCTL_RDWTCR_ENABLE (0x0001u)

#define CSL_MMCSD_SDIOCTL_RDWTRQ_MASK (0x0001u)
#define CSL_MMCSD_SDIOCTL_RDWTRQ_SHIFT (0x0000u)
#define CSL_MMCSD_SDIOCTL_RDWTRQ_RESETVAL (0x0000u)

#define CSL_MMCSD_SDIOCTL_RESETVAL (0x0000u)

/* SDIOST0 */


#define CSL_MMCSD_SDIOST0_RDWTST_MASK (0x0004u)
#define CSL_MMCSD_SDIOST0_RDWTST_SHIFT (0x0002u)
#define CSL_MMCSD_SDIOST0_RDWTST_RESETVAL (0x0000u)

#define CSL_MMCSD_SDIOST0_INTPRD_MASK (0x0002u)
#define CSL_MMCSD_SDIOST0_INTPRD_SHIFT (0x0001u)
#define CSL_MMCSD_SDIOST0_INTPRD_RESETVAL (0x0000u)

#define CSL_MMCSD_SDIOST0_DAT1_MASK (0x0001u)
#define CSL_MMCSD_SDIOST0_DAT1_SHIFT (0x0000u)
#define CSL_MMCSD_SDIOST0_DAT1_RESETVAL (0x0001u)

#define CSL_MMCSD_SDIOST0_RESETVAL (0x0001u)

/* SDIOIEN */


#define CSL_MMCSD_SDIOIEN_RWSEN_MASK (0x0002u)
#define CSL_MMCSD_SDIOIEN_RWSEN_SHIFT (0x0001u)
#define CSL_MMCSD_SDIOIEN_RWSEN_RESETVAL (0x0000u)
/*----RWSEN Tokens----*/
#define CSL_MMCSD_SDIOIEN_RWSEN_DISABLE (0x0000u)
#define CSL_MMCSD_SDIOIEN_RWSEN_ENABLE (0x0001u)

#define CSL_MMCSD_SDIOIEN_IOINTEN_MASK (0x0001u)
#define CSL_MMCSD_SDIOIEN_IOINTEN_SHIFT (0x0000u)
#define CSL_MMCSD_SDIOIEN_IOINTEN_RESETVAL (0x0000u)
/*----IOINTEN Tokens----*/
#define CSL_MMCSD_SDIOIEN_IOINTEN_DISABLE (0x0000u)
#define CSL_MMCSD_SDIOIEN_IOINTEN_ENABLE (0x0001u)

#define CSL_MMCSD_SDIOIEN_RESETVAL (0x0000u)

/* SDIOIST  */


#define CSL_MMCSD_SDIOIST_RWS_MASK (0x0002u)
#define CSL_MMCSD_SDIOIST_RWS_SHIFT (0x0001u)
#define CSL_MMCSD_SDIOIST_RWS_RESETVAL (0x0000u)

#define CSL_MMCSD_SDIOIST_IOINT_MASK (0x0001u)
#define CSL_MMCSD_SDIOIST_IOINT_SHIFT (0x0000u)
#define CSL_MMCSD_SDIOIST_IOINT_RESETVAL (0x0000u)

#define CSL_MMCSD_SDIOIST_RESETVAL (0x0000u)

/* MMCFIFOCTL */


#define CSL_MMCSD_MMCFIFOCTL_ACCWD_MASK (0x0018u)
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_SHIFT (0x0003u)
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_RESETVAL (0x0000u)
/*----ACCWD Tokens----*/
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_4BYTES (0x0000u)
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_3BYTES (0x0001u)
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_2BYTES (0x0002u)
#define CSL_MMCSD_MMCFIFOCTL_ACCWD_1BYTE (0x0003u)

#define CSL_MMCSD_MMCFIFOCTL_FIFOLEV_MASK (0x0004u)
#define CSL_MMCSD_MMCFIFOCTL_FIFOLEV_SHIFT (0x0002u)
#define CSL_MMCSD_MMCFIFOCTL_FIFOLEV_RESETVAL (0x0000u)
/*----FIFOLEV Tokens----*/
#define CSL_MMCSD_MMCFIFOCTL_FIFOLEV_128BIT (0x0000u)
#define CSL_MMCSD_MMCFIFOCTL_FIFOLEV_256BIT (0x0001u)

#define CSL_MMCSD_MMCFIFOCTL_FIFODIR_MASK (0x0002u)
#define CSL_MMCSD_MMCFIFOCTL_FIFODIR_SHIFT (0x0001u)
#define CSL_MMCSD_MMCFIFOCTL_FIFODIR_RESETVAL (0x0000u)
/*----FIFODIR Tokens----*/
#define CSL_MMCSD_MMCFIFOCTL_FIFODIR_READ (0x0000u)
#define CSL_MMCSD_MMCFIFOCTL_FIFODIR_WRITE (0x0001u)

#define CSL_MMCSD_MMCFIFOCTL_FIFORST_MASK (0x0001u)
#define CSL_MMCSD_MMCFIFOCTL_FIFORST_SHIFT (0x0000u)
#define CSL_MMCSD_MMCFIFOCTL_FIFORST_RESETVAL (0x0000u)
/*----FIFORST Tokens----*/
#define CSL_MMCSD_MMCFIFOCTL_FIFORST_RESET (0x0001u)

#define CSL_MMCSD_MMCFIFOCTL_RESETVAL (0x0000u)

#endif
