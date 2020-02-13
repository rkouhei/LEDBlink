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
	LPC_GPIO_PORT->DIR0 |= (1<<4);

	// Force the counter to be placed into memory
	volatile static int i = 0 ;
	volatile static int x = 0 ;
	// Enter an infinite loop, just incrementing a counter
	while(1) {
		LPC_GPIO_PORT->NOT0 = 1<<2;
		for (x = 0; x < 1000000; x++);
		LPC_GPIO_PORT->NOT0 = 1<<2;
		for (x = 0; x < 10; x++) {
			LPC_GPIO_PORT->NOT0 = 1<<2;
			for (i=0; i<100000; i++);
		}
		LPC_GPIO_PORT->NOT0 = 1<<4;
		for (x = 0; x < 1000000; x++);
		LPC_GPIO_PORT->NOT0 = 1<<4;
	}
	return 0 ;
}
