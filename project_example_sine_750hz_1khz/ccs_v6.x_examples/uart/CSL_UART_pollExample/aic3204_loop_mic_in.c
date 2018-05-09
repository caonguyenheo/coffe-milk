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

#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "evm5515.h"

extern Int16 AIC3204_rset( Uint16 regnum, Uint16 regval);
void getLPCoefficientsButterworth2Pole();

#define Rcv 0x08
#define Xmit 0x20

#define NZEROS 10
#define NPOLES 10
#define GAIN   1.038937175e+12

float xv[NZEROS+1] = {0};
float yv[NPOLES+1] = {0};
float xv3[NZEROS+1] = {0};
float yv3[NPOLES+1] = {0};
//double xv1[3] ={0};
//double yv1[3]= {0};
#if 0
void getLPCoefficientsButterworth2Pole(const int samplerate, const double cutoff, double* const ax, double* const by)
{
    double PI      = 3.1415926535897932385;
    double sqrt2 = 1.4142135623730950488;

    double QcRaw  = (2 * PI * cutoff) / samplerate; // Find cutoff frequency in [0..PI]
    double QcWarp = tan(QcRaw); // Warp cutoff frequency

    double gain = 1 / (1+sqrt2/QcWarp + 2/(QcWarp*QcWarp));
    by[2] = (1 - sqrt2/QcWarp + 2/(QcWarp*QcWarp)) * gain;
    by[1] = (2 - 2 * 2/(QcWarp*QcWarp)) * gain;
    by[0] = 1;
    ax[0] = 1 * gain;
    ax[1] = 2 * gain;
    ax[2] = 1 * gain;
}
#endif
/*
 *
 *  aic3204_loop_mic_in( )
 *      Output the sound from the Microphone on the HEADPHONE jack
 *
 */
Int16 aic3204_loop_mic_in( )
{
    /* Pre-generated sine wave data, 16-bit signed samples */
    Int16 j = 0, i = 0;
    Int16 sample = 0, data2 = 0, data4 = 0;
    Int16  data1, data3;
    Int16 data5 = 0, data6 = 0, data7 = 0;
    float data8 = 0, data9 = 0;
//    double data5 = 0, data6 = 0, data7 = 0;
//    Int16 sinetable[48]={0};
//    Int16 sinetable1[48]={0};

     /* Configure AIC3204 */
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset(  1, 0x01 );      // Reset codec
    AIC3204_rset(  0, 0x01 );      // Point to page 1
    AIC3204_rset(  1, 0x08 );      // Disable crude AVDD generation from DVDD
    AIC3204_rset(  2, 0x00 );      // Enable Analog Blocks
    /* PLL and Clocks config and Power Up */
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 27, 0x00 );      // BCLK and WCLK is set as i/p to AIC3204(Slave)
    AIC3204_rset(  4, 0x07 );      // PLL setting: PLLCLK <- BCLK and CODEC_CLKIN <-PLL CLK
    AIC3204_rset(  6, 0x20 );      // PLL setting: J=32
    AIC3204_rset(  7, 0 );         // PLL setting: HI_BYTE(D = 0)
    AIC3204_rset(  8, 0 );         // PLL setting: LO_BYTE(D) = 0
    /* For 48 KHz sampling */
    AIC3204_rset(  5, 0x92 );      // PLL setting: Power up PLL, P=1 and R=2
    AIC3204_rset( 13, 0x00 );      // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    AIC3204_rset( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
    AIC3204_rset( 20, 0x80 );      // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    AIC3204_rset( 11, 0x88 );      // Power up NDAC and set NDAC value to 8
    AIC3204_rset( 12, 0x82 );      // Power up MDAC and set MDAC value to 2
    AIC3204_rset( 18, 0x88 );      // Power up NADC and set NADC value to 8
    AIC3204_rset( 19, 0x82 );      // Power up MADC and set MADC value to 2
    /* DAC ROUTING and Power Up */
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 12, 0x08 );      // LDAC AFIR routed to HPL
    AIC3204_rset( 13, 0x08 );      // RDAC AFIR routed to HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 64, 0x02 );      // Left vol=right vol
    AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and set channel
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 16, 0x03 );      // Unmute HPL , 6dB gain
    AIC3204_rset( 17, 0x03 );      // Unmute HPR , 6dB gain
    AIC3204_rset(  9, 0x30 );      // Power up HPL,HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    EVM5515_wait( 500 );           // Wait
    /* ADC ROUTING and Power Up */
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 51, 0x40 );      // SetMICBIAS
    AIC3204_rset( 52, 0xc0 );      // STEREO 1 Jack
		                           // IN2_L to LADC_P through 40 kohm
    AIC3204_rset( 55, 0xc0 );      // IN2_R to RADC_P through 40 kohmm
    AIC3204_rset( 54, 0x03 );      // CM_1 (common mode) to LADC_M through 40 kohm
    AIC3204_rset( 57, 0xc0 );      // CM_1 (common mode) to RADC_M through 40 kohm
    AIC3204_rset( 59, 0x5f );      // MIC_PGA_L unmute
    AIC3204_rset( 60, 0x5f );      // MIC_PGA_R unmute
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 81, 0xc0 );      // Powerup Left and Right ADC
    AIC3204_rset( 82, 0x00 );      // Unmute Left and Right ADC
    
    AIC3204_rset( 0,  0x00 );    
    EVM5515_wait( 200 );           // Wait
        
    /* I2S settings */
    I2S0_SRGR = 0x0015;
    I2S0_ICMR = 0x0028;    // Enable interrupts
    I2S0_CR   = 0x8012;    // 16-bit word, Master, enable I2S

    /* Play Tone */
//    double ax[3] = {0};
//    double by[3]= {0};
//    getLPCoefficientsButterworth2Pole(44100, 1000, ax, by);

#ifdef MODE_MICIN_BUTTERWORTHLPF_OUTSPEAKER
      for(;;)
       {
           data3 = I2S0_W0_MSW_R;
           data1 = I2S0_W0_LSW_R;
           data4 = I2S0_W1_MSW_R;
           data2 = I2S0_W1_LSW_R;

           while((Rcv & I2S0_IR) == 0);  // Wait for interrupt
               xv1[2] = xv1[1]; xv1[1] = xv1[0];
               xv1[0] = (double)data3;
               yv1[2] = yv1[1]; yv1[1] = yv1[0];

               yv1[0] =   (ax[0] * xv1[0] + ax[1] * xv1[1] + ax[2] * xv1[2] - by[1] * yv1[0] - by[2] * yv1[1]);

               data5 = yv1[0];
               I2S0_W0_MSW_W = data5;
               I2S0_W0_LSW_W = 0;
//               UART_PRINT("\r\ninfor_Value_data5:%ld\r\n",data5);
       }
/*      for ( i = 0 ; i < 10 ; i++ )
      {
          for ( j = 0 ; j < 1000 ; j++ )
          {
              for ( sample = 0; sample < 48; sample++ )
              {
                  getLPCoefficientsButterworth2Pole(48000, 1000, ax, by);
                 //  Read Digital audio input
                  while((Rcv & I2S0_IR) == 0);   // Wait for receive interrupt to be pending
                  data3 = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
                  data4 = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
                  // Write Digital audio input
                  while((Xmit & I2S0_IR) == 0);  // Wait for receive interrupt to be pending
                  xv1[2] = xv1[1]; xv1[1] = xv1[0];
                  xv1[0] = ((double) data4);
                  yv1[2] = yv1[1]; yv1[1] = yv1[0];

                  yv1[0] =   (ax[0] * xv1[0] + ax[1] * xv1[1] + ax[2] * xv1[2]
                           - by[1] * yv1[0]
                           - by[2] * yv1[1]);

                  data5 = yv1[0];
                  I2S0_W0_MSW_W = 0;
                  I2S0_W0_LSW_W = 0;
                  I2S0_W1_MSW_W = data5;
                  I2S0_W1_LSW_W = 0;
  //              I2S0_W0_MSW_W = data1;  // 16 bit left channel transmit audio data
  //              I2S0_W1_MSW_W = data2;  // 16 bit right channel transmit audio data
              }
          }
      }*/
#endif

#if 1
//      for( i = 0 ; i < 10 ; i++ )
//      {
//          for ( j = 0 ; j < 1000 ; j++ )
//          {
//              for ( sample = 0 ; sample < 48 ; sample++ )
//              {
      for(;;)
      {
                  data6 = I2S0_W0_MSW_R; // 16 bit left channel transmit audio data
                  data7 = I2S0_W0_LSW_R;
                  data4 = I2S0_W1_MSW_R; // 16 bit right channel received audio data
                  data2 = I2S0_W1_LSW_R;
                  while((Rcv & I2S0_IR) == 0);  // Wait for interrupt
//                  UART_PRINT("\r\data6:%d\r\n",data6); // printf value
//                  UART_PRINT("\r\data7:%d\r\n",data7); // printf value
                  xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4]; xv[4] = xv[5]; xv[5] = xv[6]; xv[6] = xv[7]; xv[7] = xv[8];
                  xv[8] = xv[9];xv[9] = xv[10];
                  xv[10] = (float)data6/GAIN;
                  yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; yv[4] = yv[5]; yv[5] = yv[6]; yv[6] = yv[7]; yv[7] = yv[8]; yv[8] = yv[9]; yv[9] = yv[10];
                  yv[10] =   (xv[0] + xv[10]) + 10 * (xv[1] + xv[9]) + 45 * (xv[2] + xv[8])
                           + 120 * (xv[3] + xv[7]) + 210 * (xv[4] + xv[6]) + 252 * xv[5]
                           + ( -0.4327676731 * yv[0]) + (  4.6897864353 * yv[1])
                           + ( -22.8860944020 * yv[2]) + (  66.2310069140 * yv[3])
                           + (-125.8758673700 * yv[4]) + ( 164.1710393500 * yv[5])
                           + (-148.8078582500 * yv[6]) + ( 92.5645061460 * yv[7])
                           + (-37.817021126 * yv[8]) + (  9.1632699778 * yv[9]);
                  data8 = yv[10];
                  xv3[0] = xv3[1]; xv3[1] = xv3[2]; xv3[2] = xv3[3]; xv3[3] = xv3[4]; xv3[4] = xv3[5]; xv3[5] = xv3[6]; xv3[6] = xv3[7]; xv3[7] = xv3[8];
                  xv3[8] = xv3[9];xv3[9] = xv3[10];
                  xv3[10] = (float)data4/GAIN;
                  yv3[0] = yv3[1]; yv3[1] = yv3[2]; yv3[2] = yv3[3]; yv3[3] = yv3[4]; yv3[4] = yv3[5]; yv3[5] = yv3[6]; yv3[6] = yv3[7]; yv3[7] = yv3[8]; yv3[8] = yv3[9]; yv3[9] = yv3[10];
                  yv3[10] =   (xv3[0] + xv3[10]) + 10 * (xv3[1] + xv3[9]) + 45 * (xv3[2] + xv3[8])
                           + 120 * (xv3[3] + xv3[7]) + 210 * (xv3[4] + xv3[6]) + 252 * xv3[5]
                           + ( -0.4327676731 * yv3[0]) + (  4.6897864353 * yv3[1])
                           + ( -22.8860944020 * yv3[2]) + ( 66.2310069140 * yv3[3])
                           + (-125.8758673700 * yv3[4]) + ( 164.1710393500 * yv3[5])
                           + (-148.8078582500 * yv3[6]) + ( 92.5645061460 * yv3[7])
                           + (-37.817021126 * yv3[8]) + (  9.1632699778 * yv3[9]);
                  data9 = yv3[10];
////              UART_PRINT("\r\nyv[10]:%d\r\n",yv[10]); // printf value
                  I2S0_W0_MSW_W = data8;
                  I2S0_W0_LSW_W = 0;
//                  UART_PRINT("\r\nI2S0_W0_MSW_W:%d\r\n",I2S0_W0_MSW_W);
                  I2S0_W1_MSW_W = data9;
                  I2S0_W1_LSW_W = 0;
//                  while((Xmit & I2S0_IR) == 0); // Wait for interrupt
              }
//          }
//      }
#endif

#ifdef MODE_MICIN_OUTSPEAKER
    for( i = 0 ; i < 10 ; i++ )
    {
        for ( j = 0 ; j < 1000 ; j++ )
        {
            for ( sample = 0 ; sample < 48 ; sample++ )
            {
				 //Read Digital audio input
                data3 = I2S0_W0_MSW_R;
      	        data1 = I2S0_W0_LSW_R;
      	        data4 = I2S0_W1_MSW_R;
      	        data2 = I2S0_W1_LSW_R;
//      	    sinetable1[sample] = (sin(2 * M_PI * data4 * sample / 48000) + sin(2 * M_PI * data4 * sample / 48000));
            	while((Rcv & I2S0_IR) == 0);  // Wait for interrupt

				I2S0_W0_MSW_W = data3;
      	        I2S0_W0_LSW_W = 0;
      	        I2S0_W1_MSW_W = data4;
      	        I2S0_W1_LSW_W = 0;
                while((Xmit & I2S0_IR) == 0);  // Wait for interrupt
            }
        }
    }
#endif
    UART_PRINT("\r\n***********I2S RESET***********\r\n");
    /* Disble I2S */
    I2S0_CR = 0x00;
   
    return 0;
}
