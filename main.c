/************************************
 * #pragma directives...
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL     //
#pragma config WDTE = OFF               //set watchdog

/************************************
 * #include directives...
 ************************************/
#include <xc.h>                     //getting function from library

/************************************
 * #define directives...
 ************************************/
#define _XTAL_FREQ 64000000 
#define LED_LEFT LATDbits.LATD7         //define names so that its more readable
/************************************
/ main function
 * ...
************************************/
void main(void) {    
    // setup pin for output (connected to LED)
    LATDbits.LATD7=0;   //set initial output state
    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
    
    LATHbits.LATH3=1;   //set initial output state
    TRISHbits.TRISH3=0; //set TRIS value for pin (output)
    
    // setup pin for input (connected to button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin  
    
    TRISFbits.TRISF3=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin  
    
    while (1) { //infinite while loop - repeat forever
        
        while (PORTFbits.RF2 == 1 && PORTFbits.RF3 ==1); //if both buttons state do not change
        
        if (!PORTFbits.RF2) {                   // if the button is pressed
            LATDbits.LATD7 = !LATDbits.LATD7; //toggle LED
        }
        
        if (!PORTFbits.RF3) {                   // if the button is pressed or not 1 anymore
            LATHbits.LATH3 = !LATHbits.LATH3; //toggle RH3 LED
        }
        
        __delay_ms(200); // call built in delay function 
    }
}