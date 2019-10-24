#include <msp430.h>
#include <driverlib.h>
#include "hal_LCD.h"


#define ENABLE_PINS 0xFFFE
#define baseAddress 0x05C0

#define DEVELOPMENT 0x5A80                  // Stop the watchdog timer
#define ACLK 0x0100
#define UP 0x0010
#define COUNT 3800                          // 3277 COUNT ~ .10 Seconds

#define BTN1 0x02
#define BTN2 0x04


int ANumber;
int BNumber;
int CNumber;
int i=0;
int t=0;
int lag=0;
int slow=0;
int p=0;

int main()
{
    P1REN = 0x06;//This sets button1 and button2 to pull up resistor
    P1OUT = 0x06;
    PM5CTL0 = ENABLE_PINS;                  //Enables Pins

    WDTCTL = DEVELOPMENT;                   // Stop the watchdog timer
    PM5CTL0 = ENABLE_PINS;                  // Enable inputs and outputs
    TA0CCR0 = COUNT;                        // We will count up from 0 to N
    TA0CTL = ACLK | UP;                     // Use ACLK, for UP mode



    Init_LCD();

while(1)
{
                  if(ANumber==0)
                  {
                      showChar(48,pos1);
                  }
                  if(BNumber==0)
                  {
                      showChar(48,pos2);
                  }
                  if(CNumber==0)
                  {
                      showChar(48,pos3);
                  }

                  LCDMEM[pos2+1] |= 0x01; //This place a decimal in the LCD screen

                  showChar('S',pos4);
                  showChar('E',pos5);
                  showChar('C',pos6);
    if (!(BTN1 & P1IN)) //Checks to see if the Left Button was pressed
    {
        while(i < 10)
        {
            LCDMEM[pos2+1] |= 0x01;//This place a decimal in the LCD screen
            while(p < 25000)//Time delay in between pressing and releasing button 1
            {
                p++;
            }

            /*****Checks to see if button 2 has been pressed and resets the clock and starts at counting again****/

            if(P1IN == BTN1)//Checks to see if button 2 was pressed Clears the Clock
            {
            LCDMEM[pos2+1] |= 0x01;//This place a decimal in the LCD screen
            i=0;
            t=0;
            CNumber=0;
            BNumber=0;
            ANumber=0;
            }

            /******Checks to see if button 1 has been pressed and stops the clock from counting*****/


            if(!(BTN1 & P1IN))//Checks to see if button 1 was pressed and stops the clock
            {
                lag=0;
                while(lag < 25000)//Time delay in between pressing and releasing button 1
                    {
                    lag++;
                    }
                while(t<2)//pause for until button 1 is pressed again
                    {
                    LCDMEM[pos2+1] |= 0x01; //This place a decimal in the LCD screen
                    if(!(BTN1 & P1IN))//Checks to see if button 1 was pressed and stops the clock
                        {
                        t=3;
                        }
                    if(P1IN == BTN1)//Checks to see if button 2 was pressed Clears the Clock
                    {
                    i=0;
                    t=0;
                    CNumber=0;
                    BNumber=0;
                    ANumber=0;
                    if(ANumber==0)
                    {
                        showChar(48,pos1);
                    }
                    if(BNumber==0)
                    {
                        showChar(48,pos2);
                    }
                    if(CNumber==0)
                    {
                        showChar(48,pos3);
                    }
                    }
                    }
                while(slow < 25000)//Time delay in between pressing and releasing button 1
                {
                    slow++;
                }
                slow=0;
                t=0;
                lag=0;
            }
            /*****This checks the clock and add 1 to the tenths place if it has reached its time******/

            if(TA0CTL & TAIFG)
            {
                CNumber++;
                i++;
                TA0CTL = ACLK | UP;                    //Resets the Flag, and counts again
            }


            if((ANumber==9) & (BNumber==9) & (CNumber==9))
            {
                ANumber=0;
                BNumber=0;
                CNumber=0;
            }

               if(i==10)
               {
                   i=0;
                   CNumber=0;         //Resets the tenths Place
                   BNumber++;         //Adds 1 to the Ones Place
               }

               if(BNumber==10)
               {
                   BNumber=0;         //Resets the Ones Place
                   ANumber++;         //Adds 1 to the Tens Place
               }

               if(ANumber==0)
               {
                   showChar(48,pos1);
               }
               if(BNumber==0)
               {
                   showChar(48,pos2);
               }
               if(CNumber==0)
               {
                   showChar(48,pos3);
               }
               if(ANumber > 0)
               {
                   LCDMEM[pos2+1] |= 0x01; //This place a decimal in the LCD screen
                   if(ANumber==1)
                   {showChar(49,pos1);}
                   if(ANumber==2)
                   {showChar(50,pos1);}
                   if(ANumber==3)
                   {showChar(51,pos1);}
                   if(ANumber==4)
                   {showChar(52,pos1);}
                   if(ANumber==5)
                   {showChar(53,pos1);}
                   if(ANumber==6)
                   {showChar(54,pos1);}
                   if(ANumber==7)
                   {showChar(55,pos1);}
                   if(ANumber==8)
                   {showChar(56,pos1);}
                   if(ANumber==9)
                   {showChar(57,pos1);}
               }
               if(BNumber > 0)
               {
                   LCDMEM[pos2+1] |= 0x01; //This place a decimal in the LCD screen
                   if(BNumber==1)
                   {showChar(49,pos2);}
                   if(BNumber==2)
                   {showChar(50,pos2);}
                   if(BNumber==3)
                   {showChar(51,pos2);}
                   if(BNumber==4)
                   {showChar(52,pos2);}
                   if(BNumber==5)
                   {showChar(53,pos2);}
                   if(BNumber==6)
                   {showChar(54,pos2);}
                   if(BNumber==7)
                   {showChar(55,pos2);}
                   if(BNumber==8)
                   {showChar(56,pos2);}
                   if(BNumber==9)
                   {showChar(57,pos2);}
               }
               if(CNumber > 0)
               {
                   LCDMEM[pos2+1] |= 0x01; //This place a decimal in the LCD screen
                   if(CNumber==1)
                   {showChar(49,pos3);}
                   if(CNumber==2)
                   {showChar(50,pos3);}
                   if(CNumber==3)
                   {showChar(51,pos3);}
                   if(CNumber==4)
                   {showChar(52,pos3);}
                   if(CNumber==5)
                   {showChar(53,pos3);}
                   if(CNumber==6)
                   {showChar(54,pos3);}
                   if(CNumber==7)
                   {showChar(55,pos3);}
                   if(CNumber==8)
                   {showChar(56,pos3);}
                   if(CNumber==9)
                   {showChar(57,pos3);}
               }

        }
    }
}
}













