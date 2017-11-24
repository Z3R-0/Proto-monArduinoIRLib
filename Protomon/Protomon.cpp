// 
// 
// 

#include "Protomon.h"

Protomon::Protomon(uint8_t freq){
	this->freq = freq;
}

Protomon::Protomon(){
	
}

int Protomon::transmit(){
	//Do things here
}

void Protomon::setFreq(uint8_t freq){
	this->freq = freq;
}

void Protomon::setData(char data[12]){
	this->data = data;
}