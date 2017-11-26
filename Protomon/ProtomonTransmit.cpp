/*
	Name: Tim Meermans
	Date: 24 November 2017
	Description: This class is for the transmit function. It includes all required functions for transmit() to work properly.
*/
#include "ProtomonTransmit.h"
extern "C" {
	#include <string.h>
};

ProtomonTransmit::ProtomonTransmit(uint8_t freq){
	this->freq = freq;
}

int ProtomonTransmit::transmit(){
	//Do things here with PWM pin
}

void ProtomonTransmit::setFreq(uint8_t freq){
	this->freq = freq;
}

void ProtomonTransmit::cypherBits(char downID[4]){
	//Extern C code for string functions and looping
	extern "C" {
		int i = 0;
		//Add start bit
		strcpy(data, "1");
		//Add downmon ID
		strcat(data, downID);
		//Add inverse of downmon ID:
	
	
		//While loop: Check if char on position i is 1 or 0 and invert  
		while(downID[i] != '\0'){
			if(downID[i] = '1'){
				i = 0;
			} else {
				i = 1;
			}
		}
	
		//Add parity bit
		strcat(data,"1");
		//Add stop bit
		strcat(data,"1");
	}
}