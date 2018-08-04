/*
 * 4x4x4_LED_Cube_Test_Circuit.c
 *
 * Created: 8/4/2018 5:00:35 PM
 * Author : Marcus Gasberg
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timers.h"

//Shift register pins
#define SHIFTREG_SRCLK 0b10000000
#define SHIFTREG_SER1 0b00000001
#define SHIFTREG_SER2 0b00000010
#define SHIFTREG_RCLK 0b01000000
#define SHIFTREG_PORT PORTB

volatile unsigned char buffer[2];

int main(void)
{
	DDRB = 0xFF;
	initFrameBufferTimer();
	sei();
    while (1) 
    {
    }
}

ISR(TIMER2_COMPA_vect)
{
	for (int i = 0; i<2; i++)
	{
		for (int j = 0 ; j < 8 ; j++)
		{
			SHIFTREG_PORT |= buffer[i] 
		}
	}
}