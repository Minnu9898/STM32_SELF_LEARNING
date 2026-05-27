//12. Objective: Write a program to show a 9-digit number on an LCD screen that increases with a quick button press and resets to zero with a long press.
//Requirements: The system must use a 16x2 LCD and one push-button. On the screen, the counter should start at 000000000. When you press and let go of the button quickly, the count should go up by 1. If you hold the button down for 2 seconds or more, the counter must clear and go back to 0. The program needs to use functions to check how long the button is held and to update the number on the LCD screen.
//
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

// -------- LCD FUNCTIONS (4-bit basic) --------
void lcd_cmd(char cmd)
{
	PORTB = (cmd & 0xF0);
	PORTB &= ~(1<<PB0); // RS = 0
	PORTB |= (1<<PB1);  // EN = 1
	_delay_ms(2);
	PORTB &= ~(1<<PB1);

	PORTB = (cmd << 4);
	PORTB &= ~(1<<PB0);
	PORTB |= (1<<PB1);
	_delay_ms(2);
	PORTB &= ~(1<<PB1);
}

void lcd_data(char data)
{
	PORTB = (data & 0xF0);
	PORTB |= (1<<PB0); // RS = 1
	PORTB |= (1<<PB1);
	_delay_ms(2);
	PORTB &= ~(1<<PB1);

	PORTB = (data << 4);
	PORTB |= (1<<PB0);
	PORTB |= (1<<PB1);
	_delay_ms(2);
	PORTB &= ~(1<<PB1);
}

void lcd_init()
{
	DDRB = 0xFF;
	_delay_ms(20);

	lcd_cmd(0x28); // 4-bit, 2 line
	lcd_cmd(0x0C); // display ON
	lcd_cmd(0x06); // increment
	lcd_cmd(0x01); // clear
}

// -------- DISPLAY FUNCTION --------
void display_number(unsigned long num)
{
	char buffer[10];
	lcd_cmd(0x80); // first line

	sprintf(buffer, "%09lu", num); // 9-digit format

	for(int i = 0; i < 9; i++)
	{
		lcd_data(buffer[i]);
	}
}

// -------- CHECK PRESS TYPE --------
unsigned char check_button()
{
	unsigned int time = 0;

	if(!(PIND & (1 << PD2))) // pressed
	{
		_delay_ms(20);

		while(!(PIND & (1 << PD2)))
		{
			_delay_ms(10);
			time += 10;

			if(time >= 2000)
			return 2; // long press
		}

		return 1; // short press
	}

	return 0;
}

int main()
{
	// Button setup
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);

	lcd_init();

	unsigned long count = 0;

	display_number(count);

	while(1)
	{
		unsigned char press = check_button();

		if(press == 1) // short press
		{
			count++;
			if(count > 999999999)
			count = 0;

			display_number(count);
		}
		else if(press == 2) // long press
		{
			count = 0;
			display_number(count);
		}
	}
}

