//14. Objective: Write a program to regulate the rotational speed of a DC motor by mapping an analog input signal to a Pulse Width Modulation (PWM) output.
//Requirements: The system must interface a potentiometer with ADC Channel 0 and a DC motor via a motor driver connected to the OC0A pin (PORTD Pin 6). The program must configure Timer0 in Fast PWM mode to drive the motor. A dedicated function should be used to read the 10-bit analog value from the potentiometer and scale it to an 8-bit value suitable for the Output Compare Register (OCR0A). The motor speed must respond linearly to the potentiometer position, reaching maximum speed at the highest voltage input and stopping at the lowest.


#define F_CPU 16000000UL
#include <avr/io.h>

// -------- ADC INIT --------
void ADC_init()
{
	ADMUX = (1 << REFS0); // AVcc reference, ADC0
	ADCSRA = (1 << ADEN)  // Enable ADC
	| (1 << ADPS2) | (1 << ADPS1); // Prescaler 64
}

// -------- READ ADC --------
unsigned int read_ADC()
{
	ADCSRA |= (1 << ADSC); // Start conversion
	while (ADCSRA & (1 << ADSC)); // Wait
	return ADC; // 10-bit value (0–1023)
}

// -------- PWM INIT --------
void PWM_init()
{
	DDRD |= (1 << PD6); // OC0A output

	TCCR0A |= (1 << WGM00) | (1 << WGM01); // Fast PWM
	TCCR0A |= (1 << COM0A1);               // Non-inverting
	TCCR0B |= (1 << CS01) | (1 << CS00);   // Prescaler 64
}

// -------- SCALE ADC TO PWM --------
unsigned char scale_to_pwm(unsigned int adc_val)
{
	return (adc_val * 255) / 1023; // Convert 10-bit ? 8-bit
}

int main()
{
	ADC_init();
	PWM_init();

	while(1)
	{
		unsigned int adc_val = read_ADC();       // Read potentiometer
		unsigned char pwm_val = scale_to_pwm(adc_val); // Scale

		OCR0A = pwm_val; // Control motor speed
	}
}

