/*
 * kpsedgeavoider.c
 *
 * Created: 08-05-2015 23:10:30
 *  Author: RAVI SHARMA
 */ 


#define F_CPU 1000000UL // define cpu frequency for delay function
#include <avr/io.h> // includes input/output header file
#include <util/delay.h> // includes delay header file

//connect the left sensor on PC3 and right one on PC0.


int main(void)
{
	DDRB=0b11111111; //PORTB as output Port connected to motors
	DDRC=0b0000000; //PORTC Input port connected to Sensors

	int left_sensor=0, right_sensor=0;
	while(1) // infinite loop
	{
		left_sensor=PINC&0b0001000; // mask PC3 bit of Port C
		right_sensor=PINC&0b0000001;// mask PC0 bit of Port C
		
		if((left_sensor==0b0001000)&&(right_sensor==0b0000001))
		{
			PORTB=0b00010010; // move forward
		}
		else
		{	if((left_sensor==0b0000000)&&(right_sensor==0b0000001))
			{	PORTB=0b00010100; }// turn right
			else
			{
				if((left_sensor==0b0001000)&&(right_sensor==0b0000000))
				{	PORTB=0b00001010; }						// turn left
				else
				{
					PORTB=0b00001100;  // move backward
				}
			}
			
		}
	}
}