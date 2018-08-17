/*
 * 4x4x4_LED_Cube_Test_Circuit.c
 *
 * Created: 8/4/2018 5:00:35 PM
 * Author : Marcus Gasberg
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include "Timers.h"
#include "Draw.h"

#define F_CPU 16000000

//Shift register pins
#define SHIFTREG_SERPORT PORTB
#define SHIFTREG_CLKPORT PORTA
#define SHIFT_PIN 0
#define LATCH_PIN 1
#define SER_PIN 0

void updateCube();

volatile unsigned char buffer[4][4];
volatile unsigned int z;

int main(void)
{
	unsigned char i,j = 0;
	z = 0;
	initFrameBufferTimer();
	DDRA = 0xFF; //Set PORTA Output
	DDRB = 0xFF; //Set PORTB Output
	PORTA = 0x00; //Clear PORTA
	PORTB = 0x00; //Clear PORTB
	sei();
    while (1) 
    {
		for (unsigned char i = 0; i < 4; i++)
		{
			for (unsigned char j = 0; j<4; j++)
			{
				toggleVoxel(i,j,0);
				_delay_ms(1000);
			}
		}
	}
}

ISR(TIMER2_COMPA_vect)
{
	updateCube();
	
}



void updateCube()
{
	//Send each 8 bits serially
	cli();
	//Order is MSB first
	for(unsigned char i=0;i<8;i++)
	{
		for (unsigned char j = 0; j<4; j++)
		{
			//Output the data on DS line according to the
			//Value of MSB
			if((buffer[3-j][0] & (1<<7-i)) == 0 )
			{
				//MSB is 0 so output low
				SHIFTREG_SERPORT &= ~(1<<SER_PIN);
			}
			else
			{
				//MSB is 1 so output high
				SHIFTREG_SERPORT |= (1<<SER_PIN);
			}
			SHIFTREG_CLKPORT &= ~(1<< SHIFT_PIN);
			SHIFTREG_CLKPORT |= (1<< SHIFT_PIN);//Pulse the Shift Clock line
		}
	}

	//Now all 8 bits have been transferred to shift register
	//Move them to output latch at one
	SHIFTREG_CLKPORT |= (1<<LATCH_PIN);//Set the pin high to enable on output
	SHIFTREG_CLKPORT &= ~(1<<LATCH_PIN);//Set RCLK pin Low

}
