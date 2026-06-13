#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_usart_driver.h"

USART_Handle_t USART2Handle;

/* Simple delay */
void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

/* USART2 TX on PA2 */
void USART2_Init(void)
{
	GPIO_Handle_t USARTPins;

	USARTPins.pGPIOx = GPIOA;
	USARTPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	USARTPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	USARTPins.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	USARTPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	USARTPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	USARTPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Init(&USARTPins);

	USART2Handle.pUSARTx = USART2;

	USART2Handle.USART_Config.USART_Baud = USART_STD_BAUD_115200;
	USART2Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	USART2Handle.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	USART2Handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	USART2Handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	USART2Handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;

	USART_Init(&USART2Handle);

	USART_PeripheralControl(USART2, ENABLE);
}

int main(void)
{
	GPIO_Handle_t GpioLed;

	/* PA5 LED */
	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Init(&GpioLed);

	USART2_Init();

	uint8_t msg[] = "LED Blinked\r\n";

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

		USART_SendData(&USART2Handle,
					   msg,
					   sizeof(msg)-1);

		delay();
	}
}
