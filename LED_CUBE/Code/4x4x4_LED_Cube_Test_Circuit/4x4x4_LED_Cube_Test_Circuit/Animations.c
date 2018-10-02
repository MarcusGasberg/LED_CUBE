/*
 * Animations.c
 *
 * Created: 9/26/2018 4:07:48 PM
 *  Author: Marcus Gasberg
 */ 
#include "Animations.h"

void rain(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed)
{
	fill(0x00);
	for (unsigned int i = 0; i < iterations ; i++)
	{
		unsigned int numDrops = rand()%6;
		
		for (unsigned drops = 0; drops < numDrops; drops++)
		{
			setVoxel(rand()%CUBE_SIZE,rand()%CUBE_SIZE,CUBE_SIZE-1); //Set random voxel in the top of the cube
		}
		
		delay_ms(holdDelay);
		for (unsigned int j = 0; j < CUBE_SIZE-1 ; j++)
		{
			//Shift layer down once
			for (unsigned int z = 0; z < CUBE_SIZE-1; z++)
			{
				for (unsigned int y = 0; y < CUBE_SIZE; y++)
				{
					buffer[y][z] = buffer[y][z+1];
				}
			}
			//Clear top layer
			clrPlane('z',CUBE_SIZE-1);
			
			//Accelerate the raindrop
			delay_ms(speed+(speed)/j);
		}
		fill(0x00);
		delay_ms(delay);
	}
	
}

//Planes randomly moves back and forth
void planeCollapse(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed)
{
	fill(0x00);
	for (unsigned i = 0; i < iterations ; i ++)
	{
		unsigned int plane = rand()%6;
		unsigned int j = 0;
		switch(plane)
		{
		case 0:
			setPlane('x',j);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('x',j);
				delay_ms(speed);
				clrPlane('x',j-1);
			}
			delay_ms(delay);
			break;
		
		case 1:
			setPlane('y',j);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('y',j);
				delay_ms(speed);
				clrPlane('y',j-1);
			}
			delay_ms(delay);
			break;
		case 2:
			setPlane('z',j);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('z',j);
				delay_ms(speed);
				clrPlane('z',j-1);
			}
			delay_ms(delay);
			break;
			
		case 3:
			setPlane('x',CUBE_SIZE-1);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('x',CUBE_SIZE-1-j);
				delay_ms(speed);
				clrPlane('x',CUBE_SIZE+1-j);
			}
			delay_ms(delay);
			break;
			
		case 4:
			setPlane('y',CUBE_SIZE-1);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('y',CUBE_SIZE-1-j);
				delay_ms(speed);
				clrPlane('y',CUBE_SIZE+1-j);
			}
			delay_ms(delay);
			break;
			
		case 5:
			setPlane('z',CUBE_SIZE-1);
			delay_ms(holdDelay);
			while(j++<CUBE_SIZE)
			{
				setPlane('z',CUBE_SIZE-1-j);
				delay_ms(speed);
				clrPlane('z',CUBE_SIZE+1-j);
			}
			delay_ms(delay);
			break;
			
		default:
			break;
		}
	}
}

//Planes randomly moves back and forth
void planeJump(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed)
{
	fill(0x00);
	for (unsigned i = 0; i < iterations ; i ++)
	{
		unsigned int plane = rand()%6; //Assign random side to start from (cube has 6)
		unsigned int j = 0;
		switch(plane)
		{
			case 0:
				setPlane('x',j);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('x',j);
					delay_ms(speed);
					clrPlane('x',j-1);
				}
				while(j-->0) //Rebounce
				{
					setPlane('x',j);
					delay_ms(speed);
					clrPlane('x',j+1);
					}
				delay_ms(delay);
				break;
			
			case 1:
				setPlane('y',j);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('y',j);
					delay_ms(speed);
					clrPlane('y',j-1);
				}
				
				while(j-->0) //Rebounce
				{
					setPlane('y',j);
					delay_ms(speed);
					clrPlane('y',j+1);
				}
				delay_ms(delay);
				break;
			case 2:
				setPlane('z',j);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('z',j);
					delay_ms(speed);
					clrPlane('z',j-1);
				}
				
				while(j-->0) //Rebounce
				{
					setPlane('z',j);
					delay_ms(speed);
					clrPlane('z',j+1);
				}
				delay_ms(delay);
				break;
			
			case 3:
				setPlane('x',CUBE_SIZE-1);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('x',CUBE_SIZE-j-1);
					delay_ms(speed);
					clrPlane('x',CUBE_SIZE-j);
				}
				
				while(j-->0) //Rebounce
				{
					setPlane('x',CUBE_SIZE-j);
					delay_ms(speed);
					clrPlane('x',CUBE_SIZE-j-1);
				}
				delay_ms(delay);
				break;
			case 4:
				setPlane('y',CUBE_SIZE-1);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('y',CUBE_SIZE-j-1);
					delay_ms(speed);
					clrPlane('y',CUBE_SIZE-j);
				}
				
				while(j-->0) //Rebounce
				{
					setPlane('y',CUBE_SIZE-j);
					delay_ms(speed);
					clrPlane('y',CUBE_SIZE-j-1);
				}
				delay_ms(delay);
				break;
			case 5:
				setPlane('z',CUBE_SIZE-1);
				delay_ms(holdDelay);
				while(j++<CUBE_SIZE) //Move this side to the other side
				{
					setPlane('z',CUBE_SIZE-j-1);
					delay_ms(speed);
					clrPlane('z',CUBE_SIZE-j);
				}
				
				while(j-->0) //Rebounce
				{
					setPlane('z',CUBE_SIZE-j);
					delay_ms(speed);
					clrPlane('z',CUBE_SIZE-j-1);
				}
				delay_ms(delay);
				break;
			
			
			default:
				break;
		}
	}
}

// Delay function used in graphical animations.
void delay_ms(unsigned int x)
{
	unsigned int y, z;
	for ( ; x > 0 ; x--){
		for ( y = 0 ; y < 90 ; y++){
			for ( z = 0 ; z < 6 ; z++){
				asm volatile ("nop");
			}
		}
	}
}