
//10. Objective: Write a program to create an automated cooling system using an LM35 sensor and a DC motor with manual power control.
//Requirements: The system must interface with an LM35 temperature sensor and a DC motor. A push-button must be used to toggle the entire system ON and OFF. When the system is ON, it should read the temperature and adjust the motor speed accordingly. At lower temperatures, the motor should run at a reduced speed, and at higher temperatures, the motor should automatically switch to a higher speed. The program logic for sensor reading, speed calculation, and motor control must be implemented using separate functions.


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// -------- ADC INIT --------
void ADC_init()
{
	ADMUX = (1 << REFS0); // AVcc reference, ADC0
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Enable ADC
}

// -------- READ TEMPERATURE --------
unsigned int read_ADC()
{
	ADCSRA |= (1 << ADSC); // Start conversion
	while (ADCSRA & (1 << ADSC)); // Wait
	return ADC;
}

// Convert ADC value to temperature (approx)
unsigned int get_temperature()
{
	unsigned int adc_val = read_ADC();
	unsigned int temp = adc_val / 2; // approx for LM35
	return temp;
}

// -------- MOTOR SPEED CONTROL --------
void set_speed(unsigned int temp)
{
	if(temp < 25)
	OCR0A = 64;    // low speed
	else if(temp < 35)
	OCR0A = 128;   // medium
	else
	OCR0A = 200;   // high speed
}

// -------- PWM INIT --------
void PWM_init()
{
	DDRD |= (1 << PD6); // OC0A output

	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Fast PWM
	TCCR0A |= (1 << COM0A1);               // Non-inverting
	TCCR0B |= (1 << CS01) | (1 << CS00);   // Prescaler 64
}

int main()
{
	// Button setup
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2); // pull-up

	ADC_init();
	PWM_init();

	unsigned char system_on = 0;

	while(1)
	{
		// Button toggle
		if(!(PIND & (1 << PD2)))
		{
			_delay_ms(50);

			if(!(PIND & (1 << PD2)))
			{
				system_on ^= 1; // toggle ON/OFF

				while(!(PIND & (1 << PD2)));
				_delay_ms(50);
			}
		}

		if(system_on)
		{
			unsigned int temp = get_temperature();
			set_speed(temp);
		}
		else
		{
			OCR0A = 0; // motor OFF
		}
	}
}
