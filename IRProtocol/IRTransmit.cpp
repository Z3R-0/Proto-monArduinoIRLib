#include "IRTransmit.h"
extern "C" {
	#include <string.h>
};

void IRTransmit::setFreq(uint16_t freq) {
	this->freq = freq;
}

uint16_t IRTransmit::getFreq() {
	return freq;
}

void IRTransmit::cypherBits(char dataC[6]) {
	char invData[6];
	int i = 0;
	//Add start bit
	strcpy(data, "1");

	//Translate uints to bits
	//Translate upDown
	if (upDown=0) {
		//Go up
		strcat(dataC,"0");
		strcat(dataC,"0");
	} else if(upDown=1) {
		//Go down
		strcat(dataC,"0");
		strcat(dataC,"1");
	} else {
		//Don't move
		strcat(dataC,"1");
		strcat(dataC,"0");
	}

	//Translate shoot
	if(shoot=1) {
		//Shoot
		strcat(dataC,"1");
	} else {
		//Don't shoot
		strcat(dataC,"0");
	}

	//Translate spawn
	if(spawn=1) {
		//Spawn jeep at first coordinate
		strcat(dataC,"0");
		strcat(dataC,"0");
		strcat(dataC,"1");
	} else if(spawn=2) {
		//Spawn jeep at second coordinate
		strcat(dataC,"0");
		strcat(dataC,"1");
		strcat(dataC,"0");		
	}  else if(spawn=3) {
		//Spawn jeep at third coordinate
		strcat(dataC,"0");
		strcat(dataC,"1");
		strcat(dataC,"1");		
	}  else if(spawn=4) {
		//Spawn jeep at fourth coordinate
		strcat(dataC,"1");
		strcat(dataC,"0");
		strcat(dataC,"0");		
	}  else if(spawn=5) {
		//Spawn jeep at fifth coordinate
		strcat(dataC,"1");
		strcat(dataC,"0");
		strcat(dataC,"1");
	} else if(spawn=6) {
		//Spawn jeep at sixth coordinate
		strcat(dataC,"1");
		strcat(dataC,"1");
		strcat(dataC,"0");
	} else {
		//Spawn jeep at seventh coordinate
		strcat(dataC,"0");
		strcat(dataC,"0");
		strcat(dataC,"0");
	}

	//Add downmon IDs
	strcat(data, dataC);

	//If loop so first character of inverse downID is copied to string not concatenated (random memory issues)
	if(dataC[i] == '1') {
		strcpy(invData, "0");
		} else {
		strcpy(invData, "1");
	}
	//While loop: Check if char on position i is 1 or 0 and invert
	while(i < strlen(dataC)) {
		//Second till last characters are all concatenated into data
		if(dataC[i] == '1' && i != 0) {
			strcat(invData, "0");
			} else if(dataC[i] == '0' && i != 0) {
			strcat(invData, "1");
		}
		i++;
	}
	strcat(data, invData);
		
	//Add stop bit
	strcat(data,"1");
}
