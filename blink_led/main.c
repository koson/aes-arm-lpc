#include "lowlevel.h"
#include "lpc23xx.h"

#define LED1  1<<25
#define LED2  1<<26
#define LED3  1<<29


#define  LED1_ON()  FIO3CLR = LED1 | LED2   						// LED1 Pin = 0 (ON LED)
#define  LED1_OFF() FIO3SET = LED1 | LED2						// LED1 Pin = 1 (OFF LED)

#define  LED2_ON()  FIO3CLR =  LED2   						// LED1 Pin = 0 (ON LED)
#define  LED2_OFF() FIO3SET =  LED2						// LED1 Pin = 1 (OFF LED)

#define  LED3_ON()  FIO4CLR = LED3   						// LED1 Pin = 0 (ON LED)
#define  LED3_OFF() FIO4SET = LED3						// LED1 Pin = 1 (OFF LED)

/***********************/
/* Delay Time Function */
/*    1-4294967296     */
/***********************/
void delay(unsigned long int count1)
{
  while(count1 > 0) {count1--;}								// Loop Decrease Counter
}

int	main (void)
{
	
	long j;  // loop counter (stack variable)

	  // Config Pin GPIO4[29]
	  //PINSEL9  &= 0xF3FFFFFF;  									// P4[29] = GPIO Function(xxxx 00xx xxxx xxxx xxxx xxxx xxxx xxxx)
		//PINSEL9  &= 0xF3FFFFFF;
	//PINMODE9 &= 0xF3FFFFFF;									// Enable Puul-Up on P3[26:25]

	  FIO3DIR  |= LED1 |  LED2;  						         		// Set GPIO-4[29] = Output(xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx)
	  FIO4DIR  |= LED3;  						         		// Set GPIO-4[29] = Output(xx1x xxxx xxxx xxxx xxxx xxxx xxxx xxxx)
	  LED1_OFF();
	  LED3_OFF();
	  // Default LED Status

	  // Loop Test LED Output on GPIO3[26],GPIO3[25]
	  while(1)													// Loop Continue
	  {
		LED1_ON();												// ON  LED1
		LED3_ON();

		delay(50000);											// Display Delay

		LED1_OFF();	                              	 			// OFF LED1
		LED3_OFF();	                              	 			// OFF LED1
 		delay(50000);											// Display Delay
	  }
}
