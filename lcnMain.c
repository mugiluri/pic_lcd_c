/*
 * File:   lcnMain.c
 * Author: ANTHONY
 *
 * Created on February 4, 2016, 8:44 PM
 */


#include <xc.h>
#include "lc.h"
/*------------------------------------------------------------------------*/

#pragma config CONFIG1H = 0X08;
#pragma config CONFIG2L = 0X19;
#pragma config CONFIG2H = 0X1E;
#pragma config CONFIG3H = 0X01; // MCLRE ON = 0x81, OFF = 0x01
#pragma config CONFIG4L = 0X80;


/*------------------------------------------------------------------------*/



/*------------------------------------------------------------------------*/

#define _XTAL_FREQ (4000000)    /* Not using xtal, only to make delays work as
                                    it won't compile without this */

void init_XLCD (void);
void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);

/*------------------------------------------------------------------------*/

void main (void)
{
    OSCCON = 0b01100010;            // Fosc = 4MHz (Inst. clk = 1MHz)
    ADCON1 = 0xF;                   // No analog, all digital i/o
    TRISA = 0x00;
    TRISB = 0x0;
    TRISC = 0x0;
    LATB = 0x0;  
    
    /*----------------------------------------------------------------------*/
    
    init_XLCD(); //call the init_XLCD function to initialize the lcd
    putrsXLCD("Eng Mugiluri"); //display "Eng Mugiluri"
    SetDDRamAddr(0x40); //shift cursor to the beginning of the second line
    putrsXLCD("Anthony"); //display "Anthony"
    //OSCCON = 0X76;
    
    /*---------------------------------------------------------------------*/


while(1)
    {


    } 

 }
/*------------------------------------------------------------------------*/
void DelayFor18TCY(void)
{
    __delay_us(18);

    }

/*------------------------------------------------------------------------*/
void DelayPORXLCD(void)
{
     __delay_ms(15);

    }
/*------------------------------------------------------------------------*/
void DelayXLCD(void)
{
    __delay_ms(5);

    }
/*------------------------------------------------------------------------*/
void init_XLCD (void)
{
    OpenXLCD(FOUR_BIT & LINES_5X7); //Configure lcd in 4-bit data mode
    while(BusyXLCD()); //Check if the lcd controller is not busy
    WriteCmdXLCD(0x06); //Move cursor right, don't shift display
    WriteCmdXLCD(0x0F); //Turn display ON without cursor-C/BLINKING-F
    }
/*-------------------------------------------------------------------------*/