/*
4. Objective: Write a program that uses four LEDs to display a 4-bit binary count triggered by a switch.
Requirements: Four LEDs must be connected to PORTB (Pins 0 through 3) and a push-button must be connected to PORTD Pin 2. Every time the switch is pressed, the value displayed by the LEDs must increment by one in binary format (from 0000 to 1111). When the count reaches 15 (all LEDs ON), the next press must reset the counter back to 0. The program should use a dedicated function to update the LED states based on the current counter variable. Module 3: Timers
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Function to display count on LEDs
void display(unsigned char count)
{
	PORTB = count & 0x0F;   // Show only lower 4 bits (PB0–PB3)
}

int main()
{
	DDRB = 0x0F;   // PB0–PB3 as output (4 LEDs)
	DDRD &= ~(1 << PD2);  // PD2 as input (button)

	PORTD |= (1 << PD2);  // Enable pull-up resistor

	unsigned char count = 0;

	display(count);   // Initial display = 0000

	while(1)
	{
		// Check button press (active LOW)
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(50);   // Debounce

			if(!(PIND & (1 << PD2)))  // Confirm press
			{
				count++;   // Increment

				if(count > 15)   // If exceeds 1111
				{
					count = 0;   // Reset
				}

				display(count);  // Update LEDs

				// Wait until button release
				while(!(PIND & (1 << PD2)));

				_delay_ms(50);   // Debounce release
			}
		}
	}
}

