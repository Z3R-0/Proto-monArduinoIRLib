// Protomon.h
/*
	Name: Brian Kamperveen
	Date: 24 november 2017
	Description: header file for receive function of Protomon-protocol
*/
#ifndef _PROTOMON_h
#define _PROTOMON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ProtomonReceive: public ProtomonReceive {
	public:
	int receive();
	void decypher(char bits[10]);
	void read(char bits[5]);

	private:
	char dataFirst[13];
	char bits[10];
	char data[5];	
};

#endif
