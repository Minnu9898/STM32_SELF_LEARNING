/*8. Objective: Write a program to control the brightness of an LED or the speed of a small DC motor using the hardware PWM capability of Timer0.
Requirements: The program must initialize Timer0 in Fast PWM mode with the output directed to the OC0A pin (PORTD Pin 6). The system should start with a 25% duty cycle. A push-button connected to an input pin should be used to cycle the duty cycle through four levels: 25%, 50%, 75%, and 100% OFF. Each time the button is pressed, the program should update the Output Compare Register (OCR0A) to the next level. The transition between speeds must be handled by a dedicated function that updates the timer registers.

*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Function to update duty cycle
void set_duty(unsigned char level)
{
	switch(level)
	{
		case 0: OCR0A = 64;  break;   // ~25%
		case 1: OCR0A = 128; break;   // ~50%
		case 2: OCR0A = 192; break;   // ~75%
		case 3: OCR0A = 0;   break;   // OFF (0%)
	}
}

int main()
{
	// Set PD6 as output (OC0A)
	DDRD |= (1 << PD6);

	// Button input
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);  // Pull-up

	// -------- Timer0 Fast PWM Setup --------
	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Fast PWM
	TCCR0A |= (1 << COM0A1);               // Non-inverting mode
	TCCR0B |= (1 << CS01) | (1 << CS00);   // Prescaler 64

	unsigned char level = 0;

	set_duty(level); // Start with 25%

	while(1)
	{
		// Button press check
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(50); // debounce

			if(!(PIND & (1 << PD2)))
			{
				level++;   // Next level

				if(level > 3)
				level = 0;

				set_duty(level); // Update PWM

				// Wait for release
				while(!(PIND & (1 << PD2)));
				_delay_ms(50);
			}
		}
	}
}

