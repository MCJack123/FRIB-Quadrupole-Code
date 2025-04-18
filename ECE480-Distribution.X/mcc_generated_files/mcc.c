/**
  @Generated PIC10 / PIC12 / PIC16 / PIC18 MCUs Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F04Q40
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc.h"


void SYSTEM_Initialize(void)
{
    INTERRUPT_Initialize();
    PMD_Initialize();
    I2C1_Initialize();
    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // NOSC HFINTOSC; NDIV 4; 
    OSCCON1 = 0x62;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; PLLEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 4_MHz; 
    OSCFRQ = 0x02;
    // TUN 0; 
    OSCTUNE = 0x00;
    // ACTUD enabled; ACTEN disabled; 
    ACTCON = 0x00;
}

void PMD_Initialize(void)
{
    // CLKRMD CLKR enabled; SYSCMD SYSCLK enabled; SCANMD SCANNER disabled; LVDMD HLVD enabled; FVRMD FVR disabled; IOCMD IOC disabled; CRCMD CRC disabled; 
    PMD0 = 0x59;
    // ZCDMD ZCD disabled; TMR0MD TMR0 disabled; TMR1MD TMR1 disabled; TMR4MD TMR4 disabled; SMT1MD SMT1 disabled; TMR2MD TMR2 disabled; TMR3MD TMR3 disabled; CM1MD CM1 disabled; 
    PMD1 = 0xFF;
    // NCO1MD NCO1 disabled; ADCMD ADC disabled; DSM1MD DSM disabled; CWG1MD CWG1 disabled; ACTMD ACT disabled; CM2MD CM2 disabled; DAC1MD DAC1 disabled; 
    PMD2 = 0x7F;
    // PWM2MD PWM2 disabled; PWM1MD PWM1 disabled; PWM3MD PWM3 disabled; SPI2MD SPI2 disabled; SPI1MD SPI1 disabled; U2MD UART2 disabled; U1MD UART1 disabled; I2C1MD I2C1 enabled; 
    PMD3 = 0xF7;
    // CLC3MD CLC3 disabled; CLC4MD CLC4 disabled; DMA1MD DMA1 disabled; DMA2MD DMA2 disabled; DMA3MD DMA3 disabled; CLC1MD CLC1 disabled; CLC2MD CLC2 disabled; 
    PMD4 = 0xFE;
    // DMA4MD DMA4 disabled; DAC2MD DAC2 disabled; 
    PMD5 = 0x03;
}


/**
 End of File
*/
