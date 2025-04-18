/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F04Q40
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/**
 * I2C receive interrupt handler
 */
static void I2C_Receive(void)
{
    uint8_t i;
    uint8_t data = I2C1_Read();
    // Push the value to the data bus
    LATC = data & 0x1F;
    // Wait for a period of time
    for (i = 0; i < 200; i++);
    // Send the right latch pulse
    switch (data >> 5) {
        case 0:
            // Pulse L0
            L0_SetHigh();
            for (i = 0; i < 200; i++);
            L0_SetLow();
            break;
        case 1:
            // Pulse L1
            L1_SetHigh();
            for (i = 0; i < 200; i++);
            L1_SetLow();
            break;
        case 2:
            // Pulse L2
            L2_SetHigh();
            for (i = 0; i < 200; i++);
            L2_SetLow();
            break;
        case 3:
            // Pulse L3
            L3_SetHigh();
            for (i = 0; i < 200; i++);
            L3_SetLow();
            break;
    }
    // Send an acknowledgement to the host
    I2C1_SendAck();
}

/**
 * I2C address interrupt handler
 */
static void I2C_Addr(void)
{
    // Read the address to reset the register and stop clock stretching
    I2C1_ReadAddr();
    // Set the byte count register to 1
    I2C1CNTL = 1;
    // Send an acknowledgement to the host
    I2C1_SendAck();
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    I2C1_Open();
    I2C1_SlaveSetReadIntHandler(I2C_Receive);
    I2C1_SlaveSetAddrIntHandler(I2C_Addr);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    while (1)
    {
        SLEEP();
    }
}
/**
 End of File
*/