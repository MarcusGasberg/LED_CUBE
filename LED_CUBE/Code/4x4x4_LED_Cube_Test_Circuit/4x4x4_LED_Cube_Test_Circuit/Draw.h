/*
 * Draw.h
 *
 * Created: 8/17/2018 12:23:05 PM
 *  Author: Marcus Gasberg
 */ 


#ifndef DRAW_H_
#define DRAW_H_

#define CUBE_SIZE 4

//The buffer to simulate the cube
extern volatile unsigned char buffer[CUBE_SIZE][CUBE_SIZE];

//Checks if the coordinates x,y,z are within the range of the cube
unsigned char inRange(unsigned char x,unsigned char y,unsigned char z);

//Checks and sets the voxel with coordinate x,y,z
void setVoxel(unsigned char x,unsigned char y,unsigned char z);

//Checks and gets the voxel with coordinate x,y,z
unsigned char getVoxel(unsigned char x, unsigned char y, unsigned char z);

//Checks and clears the voxel with coordinate x,y,z
void clrVoxel(unsigned char x,unsigned char y,unsigned char z);

//Checks and toggles the voxel with coordinate x,y,z
void toggleVoxel(unsigned char x,unsigned char y,unsigned char z);


/**************************
Function for setting x,y or z plane for a given x,y or z coordinate.

Parameters:
xyz:		Takes the values 'x','y' and 'z'. Chooses between which plane you want to set.
			if 'x' is chosen it sets the LEDs on y and z for the givens xyzValue. 

xyzValue:	The value for which x,y or z coordinate you want to set the plane.
**************************/
void setPlane(unsigned char xyz, unsigned char xyzValue);


/**************************
Function for clearing x,y or z plane for a given x,y or z coordinate.

Parameters:
xyz:		Takes the values 'x','y' and 'z'. Chooses between which plane you want to set.
			if 'x' is chosen it sets the leds on y and z for the givens xyzValue. 

xyzValue:	The value for which x,y or z coordinate you want to set the plane.
**************************/
void clrPlane(unsigned char xyz, unsigned char xyzValue);

//Fills the cube with either 1's (ON) or 0's (OFF)
void fill(unsigned char val);


#endif /* DRAW_H_ */