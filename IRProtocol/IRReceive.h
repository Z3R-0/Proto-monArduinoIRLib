/*
	Name: Brian Kamperveen
	Date: 24 november 2017
	Description: header file for receive function of IR-protocol
*/
#ifndef _IRRECEIVE_h
#define _IRRECEIVE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class IRReceive{
	public:
	int receive();
	void decypher(char bits[12]);
	int read(char bits[6]);
	uint8_t upDown;
	uint8_t shoot;
	uint8_t spawn;

	private:
	char dataFirst[15];
	char bits[12];
	char data[6];
	//void ISR();
};

#endif
