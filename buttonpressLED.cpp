
#include <msp430.h> 


#define button1 0x02 //sets buttons 1 high
#define LED1 0x01//Set LED1 to Pin 0
#define ENABLE_PINS 0xFFFE

int i;
int r;
int t;

int main()
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 = ENABLE_PINS; //You need for every program

    /*************Configure button 1 and LED1***********/

    P1DIR = LED1; //Set Pin1 to output for LED1.
    P1REN = button1;//This sets the Button with a Pull up resistor
    P1OUT = 0x02;//This says the Button is activated
while(1)
{
    if((button1 & P1IN))//If the button is press P1IN=0 if it is not Press P1IN=1, this checks the button
    {
        P1OUT = 0x02;//This says the LED is off
    }
    else
    {
        P1OUT = 0x03;//This says the LED is on
    }
}
}
