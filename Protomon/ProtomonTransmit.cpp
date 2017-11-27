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
	
}

void ProtomonTransmit::setFreq(uint8_t freq){
	this->freq = freq;
}

void ProtomonTransmit::cypherBits(char downID[4]){
	//Extern C code for string functions and looping
	extern "C" {
		char notDownID[10]
		int i = 0;
		//Add start bit
		strcpy(data, "1");
		//Add downmon IDs
		strcat(data, downID);
		//Add inverse of downmon ID:
		if(downID[i] == '1'){
			strcpy(notDownID, "0");
			} else {
			strcpy(notDownID, "1");
		}
		//While loop: Check if char on position i is 1 or 0 and invert  
		while(i < strlen(downID)){
			if(downID[i] == '1' && i != 0){
				strcat(notDownID, "0");
				} else if(downID[i] == '0' && i != 0) {
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