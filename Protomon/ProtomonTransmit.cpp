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
	//Do things here
}

void ProtomonTransmit::setFreq(uint8_t freq){
	this->freq = freq;
}

void ProtomonTransmit::cypherBits(char downID[4]){
	strcpy(data, "1");
	strcat(data, downID);
	//For loop: invert the downmonID
	for(;;){
		//make un-infinite
	}
}