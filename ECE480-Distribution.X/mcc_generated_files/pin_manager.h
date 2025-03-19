/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F04Q40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSELA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set L3 aliases
#define L3_TRIS                 TRISAbits.TRISA2
#define L3_LAT                  LATAbits.LATA2
#define L3_PORT                 PORTAbits.RA2
#define L3_WPU                  WPUAbits.WPUA2
#define L3_OD                   ODCONAbits.ODCA2
#define L3_ANS                  ANSELAbits.ANSELA2
#define L3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define L3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define L3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define L3_GetValue()           PORTAbits.RA2
#define L3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define L3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define L3_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define L3_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define L3_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define L3_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define L3_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define L3_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set L2 aliases
#define L2_TRIS                 TRISAbits.TRISA4
#define L2_LAT                  LATAbits.LATA4
#define L2_PORT                 PORTAbits.RA4
#define L2_WPU                  WPUAbits.WPUA4
#define L2_OD                   ODCONAbits.ODCA4
#define L2_ANS                  ANSELAbits.ANSELA4
#define L2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define L2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define L2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define L2_GetValue()           PORTAbits.RA4
#define L2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define L2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define L2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define L2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define L2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define L2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define L2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define L2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set L0 aliases
#define L0_TRIS                 TRISAbits.TRISA5
#define L0_LAT                  LATAbits.LATA5
#define L0_PORT                 PORTAbits.RA5
#define L0_WPU                  WPUAbits.WPUA5
#define L0_OD                   ODCONAbits.ODCA5
#define L0_ANS                  ANSELAbits.ANSELA5
#define L0_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define L0_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define L0_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define L0_GetValue()           PORTAbits.RA5
#define L0_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define L0_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define L0_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define L0_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define L0_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define L0_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define L0_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define L0_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set C0 aliases
#define C0_TRIS                 TRISCbits.TRISC0
#define C0_LAT                  LATCbits.LATC0
#define C0_PORT                 PORTCbits.RC0
#define C0_WPU                  WPUCbits.WPUC0
#define C0_OD                   ODCONCbits.ODCC0
#define C0_ANS                  ANSELCbits.ANSELC0
#define C0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define C0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define C0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define C0_GetValue()           PORTCbits.RC0
#define C0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define C0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define C0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define C0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define C0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define C0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define C0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define C0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set C1 aliases
#define C1_TRIS                 TRISCbits.TRISC1
#define C1_LAT                  LATCbits.LATC1
#define C1_PORT                 PORTCbits.RC1
#define C1_WPU                  WPUCbits.WPUC1
#define C1_OD                   ODCONCbits.ODCC1
#define C1_ANS                  ANSELCbits.ANSELC1
#define C1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define C1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define C1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define C1_GetValue()           PORTCbits.RC1
#define C1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define C1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define C1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define C1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define C1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define C1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define C1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define C1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set C2 aliases
#define C2_TRIS                 TRISCbits.TRISC2
#define C2_LAT                  LATCbits.LATC2
#define C2_PORT                 PORTCbits.RC2
#define C2_WPU                  WPUCbits.WPUC2
#define C2_OD                   ODCONCbits.ODCC2
#define C2_ANS                  ANSELCbits.ANSELC2
#define C2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define C2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define C2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define C2_GetValue()           PORTCbits.RC2
#define C2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define C2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define C2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define C2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define C2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define C2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define C2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define C2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set C3 aliases
#define C3_TRIS                 TRISCbits.TRISC3
#define C3_LAT                  LATCbits.LATC3
#define C3_PORT                 PORTCbits.RC3
#define C3_WPU                  WPUCbits.WPUC3
#define C3_OD                   ODCONCbits.ODCC3
#define C3_ANS                  ANSELCbits.ANSELC3
#define C3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define C3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define C3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define C3_GetValue()           PORTCbits.RC3
#define C3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define C3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define C3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define C3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define C3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define C3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define C3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define C3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set C4 aliases
#define C4_TRIS                 TRISCbits.TRISC4
#define C4_LAT                  LATCbits.LATC4
#define C4_PORT                 PORTCbits.RC4
#define C4_WPU                  WPUCbits.WPUC4
#define C4_OD                   ODCONCbits.ODCC4
#define C4_ANS                  ANSELCbits.ANSELC4
#define C4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define C4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define C4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define C4_GetValue()           PORTCbits.RC4
#define C4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define C4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define C4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define C4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define C4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define C4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define C4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define C4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set L1 aliases
#define L1_TRIS                 TRISCbits.TRISC5
#define L1_LAT                  LATCbits.LATC5
#define L1_PORT                 PORTCbits.RC5
#define L1_WPU                  WPUCbits.WPUC5
#define L1_OD                   ODCONCbits.ODCC5
#define L1_ANS                  ANSELCbits.ANSELC5
#define L1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define L1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define L1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define L1_GetValue()           PORTCbits.RC5
#define L1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define L1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define L1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define L1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define L1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define L1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define L1_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define L1_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/