
/*LED in Board is  connected to PA5 based on Manual
 * Port=A
 * PIN=5
 *
 */
/*
 * REFERENCE MANUAL - SEARCH MEMORY MAP - BASE ADDRESS OF PERIPHERAL
 * THEN AS WE NEED PORT A, PORT A must have connected to GPIOA
 * For every Peripheral a clock is needed, Clock activates based with the help of BUS
 * Find to which bus GPIOA is connected = AHB1
 * So Base address of AHB1
 * Base address of GPIOA
 * I need to enable AHB1 bus - so search AHB1EN  - will reach at RCC_AHB1EN (add offset and base address)
 * Navigate to RCC_AHB1EN register (Analyse bits ) Its zeroth bit is used to enable GPIOA
 *
 * Now come to Moder -First register of GPIOA  - set offset and base address of that
 * Moder Register has 0 -31 bit - Each 2 bit shows each Pin
 * I want to set PIN =5  - It is written  0 1 , that is set bit no 11 to 0 and bit no 10 to 1
 * Now we set the Pin as Output
 * Now we need to turn On and OFF - manipulation of output mode
 * So go to Output Data register
 * (Mode and Data Registers is needed for sure)
 *
 * Set 5 th bit of ODR to turn On
 * Now Type cast and Dereference all the registers
 *
 */

#include <stdint.h>

#define Peripher_Base_Addr 				(0x40000000UL)
#define AHB1_OFFSET						(0x20000UL)
#define AHB1_Base						(Peripher_Base_Addr + AHB1_OFFSET)
#define GPIOA_OFFSET					(0x00UL)
#define GPIOA_Base						(AHB1_Base + 0x00UL)

#define RCC_OFFSET						(0x3800UL)
#define RCC_Base						(AHB1_Base +RCC_OFFSET)

#define RCC_AHB1ENR_R_OFFSET			(0x30UL)
#define RCC_AHB1ENR_R					(*(volatile unsigned int *)(RCC_Base + RCC_AHB1ENR_R_OFFSET))

#define GPIOAEN							(1U<<0) // 0000 0000 0000 0000 0000 0000 0000 0001

#define GPIOA_MODE_R_OFFSET 			(0x00UL)
#define GPIOA_MODER_R_BASE				(*(volatile unsigned int *)(GPIOA_Base + GPIOA_MODE_R_OFFSET))

#define GPIOA_ODR_R_OFFSET				(0x14UL)
#define GPIOA_ODR_R_BASE 				(*(volatile unsigned int *)(GPIOA_Base + GPIOA_ODR_R_OFFSET))


#define Pin5							(1U<<5) //5 th bit of ODR register
#define LED_PIN							(Pin5)
/*
 * (1U<<10) //SET 10 TH BIT AS 1
 * &=~(1U<<11) //SET 11 TH BIT AS 0
 */
int main(void)
{
	/*
	 * 1. Enable clock access to GPIOA
	 * 2. Set PA5 as output
	 * 3.Inside While - need to Set PA5 as high to turn on LED
	 *
	 */

	RCC_AHB1ENR_R |= GPIOAEN;           // RCC_AHB1ENR_R |= 1<<0
	GPIOA_MODER_R_BASE |= (1U << 10) ; //SET 10 TH BIT AS 1
	GPIOA_MODER_R_BASE &= ~(1U << 11); //SET 11 TH BIT AS 0

    while (1)
    {
    	 // GPIOA_ODR_R_BASE |=LED_PIN;  //Turn On LED
    		//Toggle PA5
    	GPIOA_ODR_R_BASE ^=LED_PIN;
    	for(int i=0; i<100000; i++) {}

    }
}
