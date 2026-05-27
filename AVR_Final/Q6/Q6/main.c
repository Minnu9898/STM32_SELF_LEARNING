// 7. Objective: Write a program that manages two independent timing tasks simultaneously using the 16-bit Timer1 and the 8-bit Timer2.
//Requirements: The system must control two different LEDs. Timer1 must be configured to toggle a Status LED on PORTB Pin 1 exactly every 2 seconds. Simultaneously, Timer2 must be configured to toggle a Heartbeat LED on PORTB Pin 2 every 500 milliseconds. The program must use the Compare Match interrupt for both timers to ensure high precision. Each LED's timing logic must reside in its respective Interrupt Service Routine, allowing both sequences to run independently without interfering with each other.


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

// Counters for timing
volatile unsigned int t1_count = 0;
volatile unsigned int t2_count = 0;

// Timer1 Compare Match ISR (for 2 sec)
ISR(TIMER1_COMPA_vect)
{
	t1_count++;

	if(t1_count >= 2)   // 2 × 1 sec = 2 sec
	{
		PORTB ^= (1 << PB1); // Toggle LED
		t1_count = 0;
	}
}

// Timer2 Compare Match ISR (for 500 ms)
ISR(TIMER2_COMPA_vect)
{
	t2_count++;

	if(t2_count >= 50)   // 50 × 10 ms = 500 ms
	{
		PORTB ^= (1 << PB2); // Toggle LED
		t2_count = 0;
	}
}

int main()
{
	DDRB |= (1 << PB1) | (1 << PB2);
	TCCR1B |= (1 << WGM12);   // CTC mode
	OCR1A = 15624;            // 1 sec (16MHz, 1024 prescaler)
	TIMSK1 |= (1 << OCIE1A);  // Enable interrupt
	TCCR1B |= (1 << CS12) | (1 << CS10); // Start timer


	TCCR2A |= (1 << WGM21);   // CTC mode
	OCR2A = 155;              // ~10 ms (16MHz, 1024 prescaler)
	TIMSK2 |= (1 << OCIE2A);  // Enable interrupt
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Start timer

	sei(); // Enable global interrupts

	while(1)
	{
		
	}
}

