/*
Name: Tim Meermans
Date: 24 November 2017
Description: This class is for the transmit function. It includes all required functions for transmit() to work properly.
*/
#include "ProtomonTransmit.h"
extern "C" {
	#include <string.h>
};

ProtomonTransmit::ProtomonTransmit(uint16_t freq){
	this->freq = freq;
}

int ProtomonTransmit::transmit(){
	//Set up timer and interrupts on 15.92 MHz (in which one 38 kHz tick is 42 15.92MHz ticks)
	TCCR1B |= (1 << CS10);    //Set clock without pre-scaling (16 MHz)
	TCCR1A |= (1 << COM1A1);  //Set timer clear on compare match

	//Initialize counter
	TCNT1 = 0;

	//Compare value and initialization of interrupt
	OCR1A = 40;
	TIMSK1 |= (1 << OCIE1A);


	//enable global interrupts
	sei();
}

void ProtomonTransmit::ISR(TIMER1_COMPA_vect){
	DDRB |= (1 << DDB5);
	uint8_t oneOrZero, x, i;
	//Set oneOrZero to initial value
	oneOrZero = 0;

	//Check if next bit is a 1 or not. If it is set oneOrZero to 1
	if(data[x] == '1'){
		oneOrZero = 1;
	}
	else if(data[x] == '\0'){
		TIMSK1 &= ~(1 << OCIE1A);	//If data char array has ended, turn off interrupt
		PORTB &= ~(1 << PORTB5);	//Turn off led
		x = 0;						//Reset counter
		return;
	}
	
	if(i >= 50){
		if(oneOrZero){
			//Second 1 pulse
			PORTB |= (1 << PORTB5);
			i++;
			} else {
			//Second 0 pulse
			PORTB &= ~(1 << PORTB5);
			i++;
		}
		if(i == 100) {
			i = 0;
			x++;
		}
	} else {
		//First 50 pulses
		PORTB |= (1 << PORTB5);
		i++;
	}
	
}

void ProtomonTransmit::setFreq(uint8_t freq){
	this->freq = freq;
}

uint16_t ProtomonTransmit::getFreq(){
	return freq;
}

void ProtomonTransmit::cypherBits(char downID[4]){
	//Extern C code for string functions and looping
	extern "C" {
		char notDownID[10];
		int i = 0;
		//Add start bit
		strcpy(data, "1");
		//Add downmon IDs
		strcat(data, downID);
		//Add inverse of downmon ID:
		//If loop so first character of inverse downID is copied to string not concatenated (random memory issues)
		if(downID[i] == '1'){
			strcpy(notDownID, "0");
			} else {
			strcpy(notDownID, "1");
		}
		//While loop: Check if char on position i is 1 or 0 and invert
		while(i < strlen(downID)){
			//Second till last characters are all concatenated into data
			if(downID[i] == '1' && i != 0){
				strcat(notDownID, "0");
				} else if(downID[i] == '0' && i != 0){
				strcat(notDownID, "1");
			}
			i++;
		}
		strcat(data, notDownID);
		
		//Add parity bit
		strcat(data,"1");
		//Add stop bit
		strcat(data,"1");
	}
}