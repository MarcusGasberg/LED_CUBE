/*
 * Draw.h
 *
 * Created: 8/17/2018 12:23:05 PM
 *  Author: Marcus Gasberg
 */ 


#ifndef DRAW_H_
#define DRAW_H_

extern volatile unsigned char buffer[4][4];

unsigned char inRange(unsigned char x,unsigned char y,unsigned char z);
void setVoxel(unsigned char x,unsigned char y,unsigned char z);
unsigned char getVoxel(unsigned char x, unsigned char y, unsigned char z);
void clrVoxel(unsigned char x,unsigned char y,unsigned char z);
void toggleVoxel(unsigned char x,unsigned char y,unsigned char z);
void setPlane(unsigned char xyz, unsigned char xyzValue);
void clrPlane(unsigned char xyz, unsigned char xyzValue);



#endif /* DRAW_H_ */