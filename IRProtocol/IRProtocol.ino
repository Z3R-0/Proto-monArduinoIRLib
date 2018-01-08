#include "IRReceive.h"
#include "IRTransmit.h"

IRTransmit transmitter;

int main(){
	Serial.begin(9600);
	uint16_t frequency;
	char testData[7] = "100110";

	transmitter.setFreq(40);
	frequency = transmitter.getFreq();

	transmitter.cypherBits(testData);
	for(int i=0;i<7;i++) {
		Serial.println(testData[i]);
	}
}
