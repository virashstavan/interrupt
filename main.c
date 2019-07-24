/*
 * GccApplication1.c
 *
 * Created: 23-07-2019 21:46:08
 * Author : steve
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
int count=0;
int main(void)
{
    DDRD |= (1<<PD7);	//output A normal //CURRENTLY FOR LED 
	//DDRD &= ~(1<<PD0);//	output B	interrupt	
	PORTD |= (1<<PD7);	//LED HIGH
	EIMSK |= (1<<INT0);	//enabling interrupt 0
	
	EICRA |= (1<<ISC01) | (1<<ISC00);		//rising edge 
	
	sei();
	
	//PORTE &= ~(1<<PE1);
		//pd1 input and pd0 input
	/* Replace with your application code */
    while (1) 
    {
		PORTD |= (1<<PD7);
    }
}
ISR(INT0_vect)
{
	/*if(bit_is_clear(PIND,1))	//if output A is low and output B is rising edge then clockwise
		count++;
	else 
		count--;
	*/
	PORTD &= ~(1<<PD7);
	_delay_ms(2000);
}
