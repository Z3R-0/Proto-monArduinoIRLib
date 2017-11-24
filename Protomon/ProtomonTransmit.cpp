// 
// 
// 

#include "ProtomonTransmit.h"

ProtomonTransmit::ProtomonTransmit(uint8_t freq){
	this->freq = freq;
}

ProtomonTransmit::ProtomonTransmit(){
	
}

int ProtomonTransmit::transmit(){
	//Do things here
}

void ProtomonTransmit::setFreq(uint8_t freq){
	this->freq = freq;
}

void ProtomonTransmit::setData(char data[12]){
	this->data = data;
}