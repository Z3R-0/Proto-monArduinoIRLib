// Protomon.h

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
	void decypher();

	private:
	char data[12];
	
};

#endif
