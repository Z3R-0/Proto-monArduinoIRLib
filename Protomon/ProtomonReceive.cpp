/*
	Name: Brian Kamperveen
	Date: 24 November 2017
	Description: This class is for the receive function. It includes all required functions for receive() to work properly.
*/
#include "ProtomonTransmit.h"
extern "C" {
	#include <string.h>
};

void introutine() {
	if(two interrupts in two ticks) {
		add 1 to data;
	} else if(one interrupt in two ticks) {
		add 0 to data;
	}
}

//Read and process PokeShow data
int ProtomonReceive::read(char data[5]) {
	char action[3];
	strncpy(action, data, 3);
	action[3] = '\0';
}

void ProtomonReceive::ISR(PCINT0_vect) {
	//Initiate local variables
	char start, stop;

	//Make variables for start- and stop bit
	start = dataFirst[0];
	stop = dataFirst[12];

	//Check if start-, stop bit have correct values if yes remove them and decypher the data
	if(start!=1 && stop!=1) {
		/*incorrect data received;*/
		} else if(start==1 && stop==1) {
		memmove(data, bits+1, strlen(data+1) + 1);
		data[10] = '\0';
		decypher(data);
		} else {
		/*Error;*/
	}
};

int ProtomonReceive::receive() {
	//Set digital pin 2 to input
	DDRD &= ~(1<<DDB2);

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

	//Loop forever to receive data
	while(1) {
	}
}

//This function decyphers the incoming data and checks if it is correct
void ProtomonReceive::decypher(char bits[10]) {
	//Initiate local variables and scan first and last five data bits into different variables
	int i=0;
	int firstOrElse=0;
	char dataBits[5], notData[5], newNotData[5], newDataBits[5];
	sscanf(bits,"%5c%5c",dataBits,notData);

	//Remove random data from dataBits
	strncpy(newDataBits, dataBits, 5);
	newDataBits[6] = '\0';

	//Remove random data from notData
	strncpy(newNotData, notData, 5);
	newNotData[6] = '\0';

	//Empty notData variable
	notData[0] = '\0';

	//Flip first bit of newNotData and put in emptied notData variable
	if(newNotData[i] == '1') {
		strcpy(notData, "0");
	} else {
		strcpy(notData, "1");
	}

	//Flip other bits of newNotData and put in emptied notData variable
	for(i=0;i<=4;i++) {
		if(newNotData[i] == '0' && i != 0) {
			strcat(notData, "1");
		} else if(newNotData[i] == '1' && i != 0) {
			strcat(notData, "0");
		}
	}

	//Compare first five bits and inverted last five bits of data if they are equal use them if not give an error
	if(strcmp(notData, newDataBits)==0) {
		strcpy(data, newDataBits);
		//If it is the first time transmitting data readPreShow else readPokeShow
		if(firstOrElse) {
			readPokeShow(data);
		} else {
			readPreShow(data);
		}
	} else {
		//Incorrect data error message maybe?
	}
}
