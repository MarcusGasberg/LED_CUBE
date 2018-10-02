/*
 * Draw.c
 *
 * Created: 8/17/2018 12:07:09 PM
 *  Author: Marcus Gasberg
 */ 

#include "Draw.h"


//Checks if the coordinates are within the range of the cube
unsigned char inRange(unsigned char x,unsigned char y,unsigned char z)
{
	if(x>=0 && x<CUBE_SIZE && y>=0 && y<CUBE_SIZE && z>=0 && z<CUBE_SIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Sets a voxel/LED in the cube
void setVoxel(unsigned char x,unsigned char y,unsigned char z)
{
	if(inRange(x,y,z))
	{
		buffer[y][z] |=(1<<x);
	}
}

//Gets the status of a voxel/LED in the cube
unsigned char getVoxel(unsigned char x, unsigned char y, unsigned char z)
{
	if (inRange(x,y,z))
	{
		if ((buffer[y][z] & (1<<x)))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

//Clears a voxel in the cube
void clrVoxel(unsigned char x,unsigned char y,unsigned char z)
{
	if(inRange(x,y,z))
	{
		buffer[y][z] &= ~(1<<x);
	}
}

//Toggles the state of a voxel in the cube
void toggleVoxel(unsigned char x,unsigned char y,unsigned char z)
{
	if(inRange(x,y,z))
	{
		buffer[y][z] ^= (1<<x);
	}
}

/**************************
Function for setting x,y or z plane for a given x,y or z coordinate.

Parameters:
xyz:		Takes the values 'x','y' and 'z'. Chooses between which plane you want to set.
			if 'x' is chosen it sets the LEDs on y and z for the givens xyzValue. 

xyzValue:	The value for which x,y or z coordinate you want to set the plane.
**************************/
void setPlane(unsigned char xyz, unsigned char xyzValue)
{
	if (xyzValue < CUBE_SIZE)
	{
		
		switch (xyz)
		{
			case 'x':
			for (unsigned char iy = 0 ; iy < CUBE_SIZE ; iy++)
			{
				for (unsigned char iz = 0; iz < CUBE_SIZE ; iz++)
				{
					buffer[iy][iz] |= (1<<xyzValue);
				}
			}
			break;
			
			case 'y':
			for (unsigned char iz = 0 ; iz < 4 ; iz++)
			{
				buffer[xyzValue][iz] = 0xFF;
			}
			
			break;
			
			case 'z':
			for (unsigned char iy = 0; iy < 4 ; iy++)
			{
				buffer[iy][xyzValue] = 0xFF;
			}
			
			break;
			default:
			break;
		}
	}
}

/**************************
Function for clearing x,y or z plane for a given x,y or z coordinate.

Parameters:
xyz:		Takes the values 'x','y' and 'z'. Chooses between which plane you want to set.
			if 'x' is chosen it sets the leds on y and z for the givens xyzValue. 

xyzValue:	The value for which x,y or z coordinate you want to set the plane.
**************************/
void clrPlane(unsigned char xyz, unsigned char xyzValue)
{
	if (xyzValue < CUBE_SIZE)
	{
		switch (xyz)
		{
			case 'x':
			for (unsigned char iy = 0 ; iy < 4 ; iy++)
			{
				for (unsigned char iz = 0; iz < 4 ; iz++)
				{
					buffer[iy][iz] &= ~(1<<xyzValue);
				}
			}
			break;
			
			case 'y':
			for (unsigned char iz = 0 ; iz < 4 ; iz++)
			{
				buffer[xyzValue][iz] = 0x00;
			}
			break;
			
			case 'z':
			for (unsigned char iy = 0; iy < 4 ; iy++)
			{
				buffer[iy][xyzValue] = 0x00;
			}
			break;
			default:
			break;
		}
	}
}


//Fills the cube with either 1's (0xFF) or 0's (0x00)
void fill(unsigned char pattern)
{
	for (unsigned char i = 0 ; i < CUBE_SIZE ; i++)
	{
		for (unsigned char j = 0 ; j < CUBE_SIZE ; j++)
		{
			buffer[i][j] = pattern;
		}
	}
}