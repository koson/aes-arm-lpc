#include "lowlevel.h"
#include "lpc23xx.h"

#define LED1  1<<25
#define LED2  1<<26

#define  LED1_ON()  FIO3CLR = LED1    						// LED1 Pin = 0 (ON LED)
#define  LED1_OFF() FIO3SET = LED1							// LED1 Pin = 1 (OFF LED)
#define  LED2_ON()  FIO3CLR = LED2							// LED2 Pin = 0 (ON LED)
#define  LED2_OFF() FIO3SET = LED2							// LED2 Pin = 1 (OFF LED)


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

	
	// Initialize the system
	//Initialize();

	  // Config Pin GPIO3[26:25]
	  PINSEL7  &= 0xFFC3FFFF;  									// P3[26:25] = GPIO Function(xxxx xxxx xx00 00xx xxxx xxxx xxxx xxxx)
	  PINMODE7 &= 0xFFC3FFFF;									// Enable Puul-Up on P3[26:25]

	  FIO3DIR  |= LED1;  						         		// Set GPIO-3[26:25] = Output(xxxx x11x xxxx xxxx xxxx xxxx xxxx xxxx)
	  FIO3DIR  |= LED2;
	  LED1_OFF();												// Default LED Status
	  LED2_OFF();

	  // Loop Test LED Output on GPIO3[26],GPIO3[25]
	  while(1)													// Loop Continue
	  {
		LED1_ON();												// ON  LED1
		LED2_OFF();                              				// OFF LED2
	    delay(8000);											// Display Delay

		LED1_OFF();	                              	 			// OFF LED1
		LED2_ON();												// ON  LED2
		delay(8000);											// Display Delay
	  }
}
