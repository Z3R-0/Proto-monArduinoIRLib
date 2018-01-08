/*
Name: Tim Meermans
Date: 24 November 2017
Description: This class is for the transmit function. It includes all required functions for transmit() to work properly.
*/
#include "IRTransmit.h"
extern "C" {
	#include <string.h>
};

void IRTransmit::setFreq(uint16_t freq) {
	this->freq = freq;
}

int IRTransmit::transmit() {
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

//void IRTransmit::ISR(TIMER1_COMPA_vect) {
	//DDRB |= (1 << DDB5);
	//uint8_t oneOrZero, repeat, x, i;
	////Set oneOrZero to initial value
	//oneOrZero = 0;
//
	////Check if next bit is a 1 or not. If it is set oneOrZero to 1
	//if(data[x] == '1') {
		//oneOrZero = 1;
	//}
	//else if(data[x] == '\0') {
		//TIMSK1 &= ~(1 << OCIE1A);	//If data char array has ended, turn off interrupt
		//PORTB &= ~(1 << PORTB5);	//Turn off led
		//x = 0;						//Reset counter
		//return;
	//}
	//
	//if(i >= 50){
		//if(oneOrZero) {
			////Second 1 pulse
			//PORTB |= (1 << PORTB5);
			//i++;
			//} else {
			////Second 0 pulse
			//PORTB &= ~(1 << PORTB5);
			//i++;
		//}
		//if(i == 100) {
			//i = 0;
			//x++;
		//}
	//} else {
		////First 50 pulses
		//PORTB |= (1 << PORTB5);
		//i++;
	//}
	//
//}

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
	//Add inverse of downmon ID:
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
