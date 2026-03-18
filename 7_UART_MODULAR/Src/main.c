
#include <stdio.h>
#include "stm32f4xx.h"
#include <stdint.h>
#include "uart.h"

int main(void)
{
	UART2_tx_init();



	while (1)
	{
		printf("Hello from Stm32F4 \n");
	}
}
