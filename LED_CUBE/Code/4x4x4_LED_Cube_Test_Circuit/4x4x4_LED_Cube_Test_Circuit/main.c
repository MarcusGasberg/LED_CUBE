/*
 * 4x4x4_LED_Cube_Test_Circuit.c
 *
 * Created: 8/4/2018 5:00:35 PM
 * Author : Marcus Gasberg
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "Timers.h"
#include "Draw.h"

#define F_CPU 16000000

//Shift register pins
#define SHIFTREG_SERPORT PORTB
#define SHIFTREG_CLKPORT PORTA
#define LAYER_PORT PORTC
#define SHIFT_PIN 0
#define LATCH_PIN 1
#define SER_PIN 0

void updateCube();

volatile unsigned char buffer[4][4];
volatile unsigned char currentLayer;

int main(void)
{
	currentLayer = 0;
	initFrameBufferTimer();
	DDRA = 0xFF; //Set clkport Output
	DDRB = 0xFF; //Set serport Output
	DDRD = 0xFF; //set layerport Output
	SHIFTREG_CLKPORT = 0x00; //Clear clkport
	SHIFTREG_SERPORT = 0x00; //Clear Serport
	LAYER_PORT = 0x00; //Clear Layerport
	
	srand((unsigned) time(0)); //Seed random number generator for effects
	
	sei();
    while (1) 
    {
		rain(10,2000,1000,600);
		//planeCollapse(10,2000,1000,600);
		//planeJump(10,2000,1000,1500);
	}
}

ISR(TIMER2_COMPA_vect)
{
	//Turn of all layers
	LAYER_PORT = 0;
	
	//Update the cube
	updateCube();
	
	//Enable the layer
	LAYER_PORT |= (1<<currentLayer);
	
	//Increment the layer value
	//If we are currently updating layer 3, goto layer 0
	if (currentLayer++ == 3)
	{
		currentLayer = 0;
	}
}



void updateCube()
{
	//Send each 8 bits serially
	//Order is MSB first
	for(unsigned char i=0;i<8;i++)
	{
		for (unsigned char j = 0; j<4; j++)
		{
			//Output the data on DS line according to the
			//Value of MSB
			if((buffer[j][currentLayer] & (1<<7-i)) == 0 )
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

void updateCube1()
{
	//Sen address
	for (unsigned char i = 0; i < 8; i++)
	{
		
		//Output the data on DS line according to the
		//Value of MSB
		if((currentLayer & (1<<7-i)) == 0 )
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
	//Send each 8 bits serially
	//Order is MSB first
	for(unsigned char i=0;i<8;i++)
	{
		for (unsigned char j = 0; j<4; j++)
		{
			//Output the data on DS line according to the
			//Value of MSB
			if((buffer[j][currentLayer] & (1<<7-i)) == 0 )
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