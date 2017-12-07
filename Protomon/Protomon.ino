#include "ProtomonReceive.h"
#include "ProtomonTransmit.h"
int main(){
	uint16_t frequency;
	char dataForTransmitTest[7] = "10011";

	ProtomonTransmit transmitter = new ProtomonTransmit();
	transmitter.setFreq(40);
	frequency = transmitter.getFreq();

	transmitter.cypherBits(dataForTransmitTest);
}