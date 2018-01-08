/*
	Naam: Tim Meermans
	Date: 23-November-2017
	Description: header file for the Transmit functions of the IR protocol
*/

#ifndef _IRTRANSMIT_h
#define _IRTRANSMIT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
	
class IRTransmit{
	public:
		int transmit();
		void setFreq(uint16_t freq);
		void cypherBits(char dataC[6]);
		uint16_t getFreq();
		uint8_t upDown;
		uint8_t shoot;
		uint8_t spawn;

	private:
		//void ISR(TIMER1_COMPA_vect);
		char data[12];
		uint16_t freq;
	};

#endif

