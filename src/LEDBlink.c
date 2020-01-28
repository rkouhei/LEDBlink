/*
===============================================================================
 Name        : LEDBlink.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC8xx.h"
#endif

#include <cr_section_macros.h>
#include "type.h"

void SwitchMatrix_Init();

int main(void) {
	SwitchMatrix_Init();

	// PIO0_2: output
	LPC_GPIO_PORT->DIR0 |= (1<<2);

	// Force the counter to be placed into memory
	volatile static int i = 0 ;
	// Enter an infinite loop, just incrementing a counter
	while(1) {
		for (i=0; i<100000; i++);
		// Toggle PIO0_2
		LPC_GPIO_PORT->NOT0 = 1<<2;
	}
	return 0 ;
}
