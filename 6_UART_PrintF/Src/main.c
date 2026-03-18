
/*
 *           UART TX Driver for Transmitting Data
 *   1. Before Configuring - Reference Manual - page 59 There are around 6 USART
 *   	we are using UART2 cz the USB that connects to flash the program is connected to UART2
 *   2. UART2 is connected to  APB1 bus  - so need to use APB1EN Register to enable APB1 clock
 *   3. Navigate to APB1EN register - UART2 is in Bit No 17= 1U<<17
 *   4. UART has Tx and Rx  which are GPIO pins
 *   	to find which GPIO we need to find Alternative function table
 *   	In controller specific Datasheet search for "ALTERNATE FUNCTION"
 *   	Look for USART2 Tx and USART2 Rx line - so it corresponds PA2 and PA3 in table and
 *   	the colum in under AF7
 *   5. So we understood to use Tx we need to enable PA2 and for Rx we need to enable PA3
 *   6. we need to configure this Port modes to be in Alternative Function Mode then only it will work as UART
 *
 *   7. Write a function for these - void UART2_tx_init (void)
 *   8. PIN2 uses AFRL2 - we need to fill value based on AF7  as we found AF7 colum in Alternate Function Table
 *   9. For BaudRate we need an equation so we need to write a function with argument
 *   10. Read comments inside loop
 *   11. To Configure transfer direction - we just want Tx So go to Control Register 1 and
 *   	see which bit is used to enable the transmitter
 *   	USART_CR1  = bit number 3
 *   	USART ->CR1 |=(1U<<3)
 *   12. To enable UART module
 *   Go to CR1 register- bit number 13 is Uart Enable
 *
 */
#include <stdio.h>
#include "stm32f4xx.h"
#include <stdint.h>

#define SYS_FREQ 		16000000 // Needed for Baud rate
#define APB1_CLK		SYS_FREQ
#define UART_BAUDRATE   115200

#define GPIOAEN  		(1U<<0)    //IN AHB1EN register GPIOA is in Bit 0
#define UART2EN  		(1U<<17)   //IN APB1EN register UART2 is in Bit 17
#define CR1_TE			(1U<<3)	   //transfer direction
#define CR1_UE			(1U<<13)   //Uart Enable


#define SR_TXE			(1<<7)	//TXE register
#define SR_TC		    (1<<6)	//TC register

void UART2_tx_init (void);
void uart2_write(int ch);
static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate );
static uint16_t compute_uart_bd (uint32_t PeriphClk, uint32_t BaudRate);

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}
int main(void)
{
	UART2_tx_init();



	while (1)
	{
		printf("Hello from Stm32F4 \n");
	}
}

void UART2_tx_init (void)
{
		/* To Configure UART GPIO Pin
		 * 1. Enable GPIOA
		 * 2. Set PA2 Mode to work in Alternate Mode
		 * 3. SET PA2 Alternative function type to UART Tx (AF7 ) in AFRL register of GPIOx */

	/*1*/  RCC->AHB1ENR |= GPIOAEN;
   /*2*/   GPIOA->MODER |= (1<<5);
	       GPIOA->MODER &=~(1<<4);
  /*3*/    GPIOA->AFR[0]  |= (1<<8);
  	  	   GPIOA->AFR[0]  |= (1<<9);
  	  	   GPIOA->AFR[0]  |= (1<<10);
  	  	   GPIOA->AFR[0]  &= ~(1<<11);

	/* To Configure UART Module
	 * For that
	 * 1. Enable  clock to access UART2
	 * 2. Configure UART Baudrate
	 * 3. Configure transfer direction
	 * 4. Enable UART module
	*/

	/*1*/ RCC->APB1ENR |=UART2EN;
	/*2*/ uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE ); // Function call for Baud rate
	/*3*/ USART2 ->CR1 = CR1_TE; // No | because to set just bit 3 as 1 and reset all other
	/*4*/ USART2-> CR1 |=CR1_UE;

}

void uart2_write(int ch)
{
	/*Make sure Data Register is empty- TXE=1/0
	 * Write to DR
	 */
	while(!(USART2->SR & SR_TXE))
	{

	}
	USART2->DR=(ch & 0xFF);

}
static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk, uint32_t BaudRate )
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd (uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U) /BaudRate));
}
