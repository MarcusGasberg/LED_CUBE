/*
 * Timers.c
 *
 * Created: 7/31/2018 2:29:07 PM
 *  Author: Marcus Gasberg
 */ 


 ///*************************************************************************
 //Timer 2 initialization for the frame buffer interrupt for 8x8x8 LED CUBE
 //16000000/128/11 = 11363.63 interrupts per second
 //11363.63/8 layers = 1420 frames per second
 //*************************************************************************/
//void initFrameBufferTimer()
//{
	//OCR2A = 10; //interrupt at counter = 10
	//TCCR2A |= (1<<WGM21); //CTC mode. Reset Counter when OCR2 reached
	//TCCR2B |= (1<<CS20)|(1<<CS22); //Set prescaler = 128
	//TCNT2 = 0x00; //Set counter register = 0
	//TIMSK2 |= (1<<OCIE2A); // Compare match interrupt when OCR2A reached
//}


 /*************************************************************************
 Timer 2 initialization for the frame buffer interrupt for 4x4x4 LED CUBE
 16000000/256/11 = 56818.18 interrupts per second
 56818.18/4 layers = 1420 frames per second
 *************************************************************************/
void initFrameBufferTimer()
{
	OCR2A = 10; //interrupt at counter = 10
	TCCR2A |= (1<<WGM21); //CTC mode. Reset Counter when OCR2 reached
	TCCR2B |= (1<<CS21)|(1<<CS22); //Set prescaler = 256
	TCNT2 = 0x00; //Set counter register = 0
	TIMSK2 |= (1<<OCIE2A); // Compare match interrupt when OCR2A reached
}