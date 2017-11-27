// Protomon.h
/*
	Naam: Tim Meermans
	Date: 23-November-2017
	Description: header file for the Transmit functions of the Protomon protocol
*/

#ifndef _PROTOMON_h
#define _PROTOMON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
	
	class ProtomonTransmit: public ProtomonTransmit
	{
	public:
		int transmit();
		void setFreq(uint8_t freq);
		void cypherBits(char downID[4]);
		uint8_t getFreq();
	private:
		char data[12];
		uint8_t freq;
	};

#endif

