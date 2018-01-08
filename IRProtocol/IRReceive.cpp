/*
	Name: Brian Kamperveen
	Date: 24 November 2017
	Description: This class is for the receive function. It includes all required functions for receive() to work properly.
*/
#include "IRReceive.h"
extern "C" {
	#include <string.h>
};

//Read and process PokeShow data
int IRReceive::read(char bits[6]) {
	char action[3];
	strncpy(action, bits, 3);
	action[3] = '\0';
}

//void IRReceive::ISR(PCINT2_vect) {
	////Initiate local variables
	//char start, stop;
	//int amountOfOne, i;
//
	//if(amountOfOne>80) {
		//data[i]==1;
	//} else if(amountOfOne>=40||amountOfOne<=60) {
		//data[i]==0;
	//} else {
		////Error?
	//}
//
	////Make variables for start- and stop bit
	//start = dataFirst[0];
	//stop = dataFirst[12];
//
	////Check if start-, stop bit have correct values if yes remove them and decypher the data
	//if(start!=1 && stop!=1) {
		///*incorrect data received;*/
	//} else if(start==1 && stop==1) {
		//memmove(data, bits+1, strlen(data+1) + 1);
		//data[10] = '\0';
		//decypher(data);
	//} else {
		///*Error;*/
	//}
//}

int IRReceive::receive() {
	//Set digital pin 2 to input
	DDRD &= ~(1<<DDB2);

	//Initialize interrupt
	PCMSK2 |= (1 << PCINT18);

	//Turn on interrupt flag
	PCICR |= (1 << PCIE2);
	PCIFR |= (1 << PCIF2);

	//enable global interrupts
	sei();

	//Loop forever to receive data
	while(1) {
	}
}

//This function decyphers the incoming data and checks if it is correct
void IRReceive::decypher(char bits[12]) {
	//Initiate local variables and scan first and last five data bits into different variables
	int i=0;
	int firstOrElse=0;
	char dataBits[6], notData[6], invNotData[6], invDataBits[6], upDownR[2], spawnR[3];
	sscanf(bits,"%5c%5c",dataBits,notData);

	//Remove random data from dataBits
	strncpy(invDataBits, dataBits, 6);
	invDataBits[7] = '\0';

	//Remove random data from notData
	strncpy(invNotData, notData, 6);
	invNotData[7] = '\0';

	//Empty notData variable
	notData[0] = '\0';

	//Flip first bit of newNotData and put in emptied notData variable
	if(invNotData[i] == '1') {
		strcpy(notData, "0");
	} else {
		strcpy(notData, "1");
	}

	//Flip other bits of newNotData and put in emptied notData variable
	for(i=0;i<=5;i++) {
		if(invNotData[i] == '0' && i != 0) {
			strcat(notData, "1");
		} else if(invNotData[i] == '1' && i != 0) {
			strcat(notData, "0");
		}
	}

	//Compare first five bits and inverted last five bits of data if they are equal use them if not give an error
	if(strcmp(notData, invDataBits)==0) {
		strcpy(data, invDataBits);
	} else {
		//Incorrect data error message maybe?
	}

	strncpy(upDownR, data, 2);
	upDownR[3] = '\0';

	shoot = data[3]-'0';

	memmove(spawnR, data+3, 3);
	spawnR[4] ='\0';

	if(strcmp(upDownR,"00")==0) {
		upDown=0;
	} else if(strcmp(upDownR,"01")==0) {
		upDown=1;
	} else {
		upDown=2;
	}

	if(strcmp(spawnR,"001")==0) {
		spawn=1;
	} else if(strcmp(spawnR,"010")==0) {
		spawn=2;
	}  else if(strcmp(spawnR,"011")==0) {
		spawn=3;
	} else if(strcmp(spawnR,"100")==0) {
		spawn=4;
	} else if(strcmp(spawnR,"101")==0) {
		spawn=5;
	} else if(strcmp(spawnR,"110")==0) {
		spawn=6;
	} else {
		spawn=7;
	}
}
