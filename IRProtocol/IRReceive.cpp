#include "IRReceive.h"
extern "C" {
	#include <string.h>
};

//Read and process data
int IRReceive::read(char bits[6]) {
	char action[3];
	strncpy(action, bits, 3);
	action[3] = '\0';
}

//This function deciphers the incoming data and checks if it is correct
void IRReceive::decypher(char bits[12]) {
	//Initiate local variables and scan first and last five data bits into different variables
	int i=0;
	int firstOrElse=0;
	char dataBits[6], notData[6], invNotData[6], invDataBits[6], upDownRec[2], spawnRec[3];
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

	/*The following code is for reading and deciphering the data*/
	//Get first 2 bits from data which are the upDown bits
	strncpy(upDownRec, data, 2);
	upDownRec[3] = '\0';

	//Get the 3rd bit which is the shoot bit from data
	shoot = data[3]-'0';

	//Get the last 3 bits from data which are the spawn grid bits
	memmove(spawnRec, data+3, 3);
	spawnRec[4] ='\0';

	//Compare upDownRec bits with certain strings and set upDown variable which will be used to move the other persons tank on your screen
	if(strcmp(upDownRec,"00")==0) {
		upDown=0;
	} else if(strcmp(upDownRec,"01")==0) {
		upDown=1;
	} else {
		upDown=2;
	}

	//Compare spawnRec bits with certain strings and set spawn variable which will be used to move the other persons tank on your screen
	if(strcmp(spawnRec,"001")==0) {
		spawn=1;
	} else if(strcmp(spawnRec,"010")==0) {
		spawn=2;
	}  else if(strcmp(spawnRec,"011")==0) {
		spawn=3;
	} else if(strcmp(spawnRec,"100")==0) {
		spawn=4;
	} else if(strcmp(spawnRec,"101")==0) {
		spawn=5;
	} else if(strcmp(spawnRec,"110")==0) {
		spawn=6;
	} else {
		spawn=7;
	}
}
