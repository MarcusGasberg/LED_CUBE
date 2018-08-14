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

#define F_CPU 16000000

//Shift register pins
#define SHIFTREG_SERPORT PORTB
#define SHIFTREG_CLKPORT PORTA
#define SRCLK_PIN 0
#define RCLK_PIN 1
#define SER1_PIN 0
#define SER2_PIN 1

void setVoxel(int x,int y,int z);
void clrVoxel(int x,int y,int z);
unsigned char inRange(int x,int y,int z);

volatile unsigned char buffer[4][4];
volatile unsigned char y,z = 0;

int main(void)
{	
	DDRA = 0xFF; //Set PORTA Output
	DDRB = 0xFF; //Set PORTB Output
	PORTA = 0x00; //Clear PORTA
	PORTB = 0x00; //Clear PORTB
	SHIFTREG_CLKPORT |= (1<<RCLK_PIN);//Set the pin high to enable on output
	SHIFTREG_CLKPORT &= ~(1<<RCLK_PIN);//Set the pin Low again
	
	initFrameBufferTimer();
	sei();
    while (1) 
    {
		setVoxel(0,0,0);
		_delay_ms(5000);
		setVoxel(1,0,0);
		_delay_ms(5000);
		setVoxel(2,0,0);
		_delay_ms(5000);
		setVoxel(3,0,0);
		_delay_ms(5000);
		setVoxel(0,1,0);
		_delay_ms(5000);
		setVoxel(1,1,0);
		_delay_ms(5000);
		setVoxel(2,1,0);
		_delay_ms(5000);
		setVoxel(3,1,0);
		_delay_ms(5000);
    }
}

ISR(TIMER2_COMPA_vect)
{
	SHIFTREG_CLKPORT &= ~(1<<SRCLK_PIN); //Set SRCLK Low
	SHIFTREG_CLKPORT &= ~(1<<RCLK_PIN);//Set RCLK pin Low 
	for (unsigned char j = 0; j < 8; j++)
	{
		if ((buffer[z][y] & (1<<j)) == 0 )
		{
			SHIFTREG_SERPORT &= ~(1<<y);
		}
		else
		{
			SHIFTREG_SERPORT |= (1<<y);
		}
		SHIFTREG_CLKPORT |= (1<<SRCLK_PIN); //Set SRCLK High to store the values
		SHIFTREG_CLKPORT &= ~(1<<SRCLK_PIN); //Set SRCLK Low
	}
	
	SHIFTREG_CLKPORT |= (1<<RCLK_PIN);//Set the pin high to enable on output
	
	if (y++ == 3)
	{
		y = 0;
	}
}

void setVoxel(int x,int y,int z)
{
	if(inRange(x,y,z))
	{
		buffer[z][y] |=(1<<x);
	}
}
void clrVoxel(int x,int y,int z)
{
	if(inRange(x,y,z))
	{
		buffer[z][y] &= ~(1<<x);
	}
}
unsigned char inRange(int x,int y,int z)
{
	if(x>=0 && x<4 && y>=0 && y<4 && z>=0 && z<4)
	{
		return 0x01;
	}
	else
	{
		return 0x00;
	}
}