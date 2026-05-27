// 2. Objective: Write a program to toggle between a Red LED and a Green LED using a momentary push-button switch. Requirements: The system must interface with a Red LED, a Green LED, and a push-button switch. When the switch is pressed, the program must toggle the current active LED state. If the Red LED is currently ON, it must be turned OFF while the Green LED is turned ON. Conversely, if the Green LED is currently ON, it must be turned OFF while the Red LED is turned ON. Each individual press of the switch should trigger exactly one transition between the two LEDs.

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Set LED pins as output
	DDRD |= (1 << PD5) | (1 << PD6);

	// Set button pin as input
	DDRD &= ~(1 << PD2);

	// Enable internal pull-up resistor
	PORTD |= (1 << PD2);

	uint8_t state = 0; // 0 = Red ON, 1 = Green ON

	// Initial condition = Red ON
	PORTD |= (1 << PD5);
	PORTD &= ~(1 << PD6);

	while (1)
	{
		// Check button press
		if (!(PIND & (1 << PD2)))
		{
			_delay_ms(50); 

			if (!(PIND & (1 << PD2))) //  press
			{
				// Toggle state
				state ^= 1;

				if (state == 0)
				{
					// Red ON, Green OFF
					PORTD |= (1 << PD5);
					PORTD &= ~(1 << PD6);
				}
				else
				{
					// Green ON, Red OFF
					PORTD |= (1 << PD6);
					PORTD &= ~(1 << PD5);
				}

				// Wait until button release
				while (!(PIND & (1 << PD2)));
				_delay_ms(50);
			}
		}
	}
}


