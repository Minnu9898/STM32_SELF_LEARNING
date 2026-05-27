//13. Objective: Write a program to manage an LED’s state and intensity through a serial terminal while providing real-time status updates back to the user.
//Requirements: The system must use UART communication at a 9600 baud rate to receive instructions. An LED must be connected to a pin capable of hardware PWM. If the user sends the command ON, the LED must turn on and the system should send back the message LED is now ON. If the user sends OFF, the LED must turn off and the system should reply with LED is now OFF. If the user sends a number between 0 and 100, the program must adjust the LED brightness to that percentage and reply with Brightness set to [Value]%. Student Instruction: You are responsible for selecting the most appropriate Timer (Timer0, Timer1, or Timer2) and the best PWM mode (Fast PWM or Phase Correct PWM) based on the hardware pins available and the precision required for smooth brightness control. The program must be structured using modular functions for UART communication and PWM updates.


#define F_CPU 16000000UL
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>

// -------- UART INIT --------
void UART_init()
{
	UBRR0H = 0;
	UBRR0L = 103; // 9600 baud for 16MHz

	UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Enable RX, TX
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

// -------- UART SEND --------
void UART_send_char(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void UART_send_string(char *str)
{
	while (*str)
	{
		UART_send_char(*str++);
	}
}

// -------- UART RECEIVE --------
void UART_receive_string(char *buffer)
{
	char c;
	int i = 0;

	while (1)
	{
		while (!(UCSR0A & (1 << RXC0)));
		c = UDR0;

		if (c == '\n' || c == '\r')
		{
			buffer[i] = '\0';
			return;
		}

		buffer[i++] = c;
	}
}

// -------- PWM INIT --------
void PWM_init()
{
	DDRD |= (1 << PD6); // OC0A output

	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Fast PWM
	TCCR0A |= (1 << COM0A1);               // Non-inverting
	TCCR0B |= (1 << CS01) | (1 << CS00);   // Prescaler 64
}

// -------- SET BRIGHTNESS --------
void set_brightness(int percent)
{
	if (percent < 0) percent = 0;
	if (percent > 100) percent = 100;

	OCR0A = (percent * 255) / 100;
}

int main()
{
	char buffer[20];
	int value;

	UART_init();
	PWM_init();

	UART_send_string("System Ready\r\n");

	while (1)
	{
		UART_receive_string(buffer);

		if (strcmp(buffer, "ON") == 0)
		{
			set_brightness(100);
			UART_send_string("LED is now ON\r\n");
		}
		else if (strcmp(buffer, "OFF") == 0)
		{
			set_brightness(0);
			UART_send_string("LED is now OFF\r\n");
		}
		else
		{
			value = atoi(buffer);

			if (value >= 0 && value <= 100)
			{
				set_brightness(value);

				UART_send_string("Brightness set to ");
				
				char temp[5];
				itoa(value, temp, 10);
				UART_send_string(temp);
				UART_send_string("%\r\n");
			}
			else
			{
				UART_send_string("Invalid command\r\n");
			}
		}
	}
}

