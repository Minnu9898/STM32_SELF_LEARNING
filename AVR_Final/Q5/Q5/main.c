//5. Objective: Write a program to simulate a basic one-way traffic light controller using three LEDs to represent the Green, Orange, and Red signals without using inbuilt _delay() function.
//Requirements: The system must control three LEDs connected to any three available GPIO pins on PORTB. Upon system start, the Green LED must turn ON for a duration of 10 seconds. After this period, the Green LED must turn OFF and the Orange LED must turn ON for 3 seconds. Once the Orange duration ends, it must turn OFF and the Red LED must turn ON for 10 seconds. The program must be designed to continuously cycle through this Green-Orange-Red sequence indefinitely.

#define F_CPU 16000000UL
#include <avr/io.h>

// Function to create 1 second delay using Timer1
void delay_1s()
{
	TCCR1B |= (1 << WGM12);  // CTC mode
	OCR1A = 15624;           // 1 sec (16MHz, prescaler 1024)

	TCCR1B |= (1 << CS12) | (1 << CS10); // Start timer

	while(!(TIFR1 & (1 << OCF1A))); // Wait till flag set

	TIFR1 |= (1 << OCF1A);  // Clear flag
	TCCR1B = 0;             // Stop timer
}

int main()
{
	DDRB = 0x07;   // PB0, PB1, PB2 as output

	while(1)
	{
		// GREEN ON (10 sec)
		PORTB = (1 << PB0);
		for(int i = 0; i < 10; i++)
		{
			delay_1s();
		}

		// ORANGE ON (3 sec)
		PORTB = (1 << PB1);
		for(int i = 0; i < 3; i++)
		{
			delay_1s();
		}

		// RED ON (10 sec)
		PORTB = (1 << PB2);
		for(int i = 0; i < 10; i++)
		{
			delay_1s();
		}
	}
}
