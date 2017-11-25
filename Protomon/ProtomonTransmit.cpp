// 
// 
// 

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
	//invert the downmon ID
}