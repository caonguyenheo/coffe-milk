/* 
 * Copyright (c) 2012 Texas Instruments Incorporated.  
 * Except for those rights granted to you in your license from TI, all rights
 * reserved.
 *
 * Software License Agreement
 * Texas Instruments (TI) is supplying this software for use solely and
 * exclusively on TI devices. The software is owned by TI and/or its suppliers,
 * and is protected under applicable patent and copyright laws.  You may not
 * combine this software with any open-source software if such combination
 * would cause this software to become subject to any of the license terms
 * applicable to such open source software.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
 * NO WARRANTIES APPLY TO THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY.
 * EXAMPLES OF EXCLUDED WARRANTIES ARE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE AND WARRANTIES OF NON-INFRINGEMENT,
 * BUT ALL OTHER WARRANTY EXCLUSIONS ALSO APPLY. FURTHERMORE, TI SHALL NOT,
 * UNDER ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, CONSEQUENTIAL
 * OR PUNITIVE DAMAGES, FOR ANY REASON WHATSOEVER.
 */


#define AIC3204_I2C_ADDR 0x18

#include "evm5515.h"
#include "evm5515_gpio.h"
#include "evm5515_i2c.h"
#include "evm5515_i2cgpio.h"
#include "stdio.h"

extern Int16 aic3204_tone_headphone( );
extern Int16 aic3204_tone_stereo_out( );
extern Int16 aic3204_loop_stereo_in1( );
extern Int16 aic3204_loop_stereo_in2( );
extern Int16 aic3204_loop_mic_in( );

/*
 *
 *   AIC3204_rget( regnum, regval )
 *
 *      Return value of codec register regnum
 *
 */
Int16 AIC3204_rget(  Uint16 regnum, Uint16* regval )
{
    Int16 retcode = 0;
    Uint8 cmd[2];

    cmd[0] = regnum & 0x007F;       // 7-bit Device Address
    cmd[1] = 0;

    retcode |= EVM5515_I2C_write( AIC3204_I2C_ADDR, cmd, 1 );
    retcode |= EVM5515_I2C_read( AIC3204_I2C_ADDR, cmd, 1 );

    *regval = cmd[0];
    EVM5515_wait( 10 );
    return retcode;
}

/*
 *
 *   AIC3204_rset( regnum, regval )
 *
 *      Set codec register regnum to value regval
 *
 */
Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint8 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = regval;                // 8-bit Register Data

    return EVM5515_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
}

/*
 *
 *  aic3204_test( )
 *
 */
Int16 aic3204_test( )
{

    /* Test Instructions */
//	UART_PRINT("For this test, make sure J27 (1-3=Off, 2-4=Off)\r\n");
//	UART_PRINT("J28 (1-3=Off, 2-4=Off)\r\n");
//	UART_PRINT("J29 (1-3=On,  2-4=On)\r\n");
//	UART_PRINT("J30 (1-3=On,  2-4=On)\r\n");

    /* Configure Serial Port 0 */
    SYS_EXBUSSEL &= ~0x0300;   // 
    SYS_EXBUSSEL |=  0x0100;   // Serial Port mode 1 (I2S1 and GP[11:10]).

    /* Configure I2C mux for AIC3204-1 */	
    EVM5515_I2CGPIO_configLine(  2, 0 );
    EVM5515_I2CGPIO_writeLine(  2, 0 );  // SEL_I2C_S0 = 0

    EVM5515_I2CGPIO_configLine(  3, 0 );
    EVM5515_I2CGPIO_writeLine(  3, 0 );  // SEL_I2C_S1 = 0

    /* Set AIC_MCBSP_MODE to I2S (disable McBSP) */	
    EVM5515_I2CGPIO_configLine(  1, 0 );
    EVM5515_I2CGPIO_writeLine(  1, 1 );  // AIC_MCBSP_MODE = 1

    /* Set SEL_MMC0_I2S to I2S */	
    EVM5515_I2CGPIO_configLine(  8, 0 );
    EVM5515_I2CGPIO_writeLine(  8, 1 );  // SEL_MMC0_I2S = 1
    
    /* Release AIC3204 reset */
    EVM5515_I2CGPIO_configLine(  0, 0 );
    EVM5515_I2CGPIO_writeLine(  0, 0 );  // AIC_RST = 0
#if MODE_AUDIO_TONE
    /* Codec tests */
    UART_PRINT( "\r\n-> 1 KHz Tone on Headphone.\r\n" );
    if ( aic3204_tone_headphone( ) )
        return 1;
       
    EVM5515_wait( 10 );  // Wait
    UART_PRINT( "\r\n-> 1 KHz Tone on Stereo OUT.\r\n" );
    if ( aic3204_tone_stereo_out( ) )
        return 1;
       
    EVM5515_wait( 10 );  // Wait
    UART_PRINT( "\r\n<-> Audio Loopback from Stereo IN 1 --> to HP\r\n" );
    if ( aic3204_loop_stereo_in1( ) )
        return 1;
        
    EVM5515_wait( 10 );  // Wait
    UART_PRINT( "\r\n<-> Audio Loopback from Stereo IN 2 --> to Stereo OUT\r\n" );
    if ( aic3204_loop_stereo_in2( ) )
        return 1;
#endif
#if MODE_MICROPHONE
   EVM5515_wait( 5 );  // Wait
    UART_PRINT( "\r\n<-> Microphone --> to HP\r\n" );
    if ( aic3204_loop_mic_in() )
    {
//        return 1;
    }
#endif

	EVM5515_GPIO_setOutput( GPIO26, 0 );
    return 0;
}
