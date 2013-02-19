/*
 * interrupts.c
 *
 *  Created on: 22 เม.ย. 2553
 *      Author: Embedded
 */
#include "lpc214x.h"
void IRQ_Routine (void)   __attribute__ ((interrupt("IRQ")));
void FIQ_Routine (void)   __attribute__ ((interrupt("FIQ")));
void SWI_Routine (void)   __attribute__ ((interrupt("SWI")));
void UNDEF_Routine (void) __attribute__ ((interrupt("UNDEF")));
/*  Stubs for various interrupts (may be replaced later)  */
/*  ----------------------------------------------------  */
void IRQ_Routine (void) {
	while (1) ;
}

void FIQ_Routine (void)  {
	while (1) ;
}

void SWI_Routine (void)  {
	while (1) ;
}

void UNDEF_Routine (void) {
	while (1) ;
}
