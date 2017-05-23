/*
* Stanley Cohen
* UCR CS120B Winter 2016
* arduino.h
* 
* Controls the sending of commands to the Arduino
*/

#ifndef __ARDUINO__
#define __ARDUINO__

#include <avr/io.h>
#include "usart_ATmega1284.h"
#include "levels.h"

//First byte sent is color (C) and command (K):
//  CCC0KKKK
//Commands:
//  0000 --Clear Screen
//  0001 --Draw Pixel
//  0010 --Draw 2x2 Box
//  0100 --Draw the loss ripples
//  0101 --Draw win ripples
//Colors:
//  000 --Blank
//  001 --Green Finish
//  010 --Purple Asteroid
//  011 --Blue Ship
//  100 --Upwards Spike
//  101 --Right Facing Spike
//  110 --Down Facing Spike
//  111 --Left Facing Spike

//Next two bytes are x and then y coordinates of the pixel to modify

void sendArduino(unsigned char val) {
	while(!USART_IsSendReady(0));
	USART_Send(val, 0);
	while(!USART_HasTransmitted(0));
	asm("nop"); //Add a delay before trying to send more
}

void drawPixel(unsigned char x, unsigned char y, enum Piece p) {
	sendArduino((p << 5) | 0x01);
	sendArduino(y);
	sendArduino(x);
}

void clearScreen() {
	sendArduino(0x00);
}

void drawBox(unsigned char x, unsigned char y, enum Piece p) {
	sendArduino((p << 5) | 0x02);
	sendArduino(y);
	sendArduino(x);
}

void sendWin(unsigned char x, unsigned char y) {
	sendArduino(0x05);
	sendArduino(y);
	sendArduino(x);
}

void sendLoss(unsigned char x, unsigned char y) {
	sendArduino(0x04);
	sendArduino(y);
	sendArduino(x);
}

#endif