//3. Objective: Write a program to create a train animation where a single active LED appears to move across a series of connected GPIO pins.
//Requirements: The system must control a sequence of at least eight LEDs connected to PORTB. When the program starts, only the first LED should turn ON. After a short delay, the first LED must turn OFF and the second LED must turn ON. This sequential shifting must continue until the last LED in the row is reached. Once the train reaches the end of the line, the pattern should immediately reset to the first LED and repeat the sequence indefinitely to create a continuous moving light effect.


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF;   // Set all PORTB pins as output

	uint8_t led = 0x01; // Start with first LED (PB0)

	while (1)
	{
		PORTB = led;    // Turn ON only one LED
		_delay_ms(200); // Speed control

		led <<= 1;      // Shift left

		if (led == 0)   // If exceeded PB7
		{
			led = 0x01; // Reset to first LED
		}
	}
}
