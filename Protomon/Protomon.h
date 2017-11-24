// Protomon.h

#ifndef _PROTOMON_h
#define _PROTOMON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
	
	class Protomon: public Protomon
	{
	public:
		int transmit();
		void setFreq(uint8_t freq);
		void setBits(uint8_t data[12]);
		void receive();
	private:
		char data[12];
		uint8_t freq;
	};

#endif

