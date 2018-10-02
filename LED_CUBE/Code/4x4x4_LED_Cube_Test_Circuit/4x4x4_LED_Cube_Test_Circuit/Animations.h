/*
 * Animations.h
 *
 * Created: 9/26/2018 4:08:08 PM
 *  Author: Marcus Gasberg
 */ 


#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_
#include <stdlib.h>
#include "Draw.h"

//Animation simulating rain
//iterations: iterations of this animation
//delay: delay between raindrops
//holdDelay: delay on the initial raindrop before falling
//speed: speed of raindrops
void rain(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed);

//Planes randomly moves to the other side
void planeCollapse(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed);

//Planes randomly moves back and forth
void planeJump(unsigned int iterations, unsigned int delay,unsigned int holdDelay, unsigned int speed);

//Delay function used by animations
void delay_ms(unsigned int x);


#endif /* ANIMATIONS_H_ */