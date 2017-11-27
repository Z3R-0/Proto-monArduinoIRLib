#include "ProtomonTransmit.h"
#include <string.h>

ProtomonReceive::ProtomonReceive(){
	
}

int ProtomonReceive::receive(){
	//Receive and return values
}

void ProtomonReceive::decypher(char data[12]){
	char str1[] = "1dtdtdtdtdt10";
	char str2[sizeof(str1)-5][6];
	const size_t N = sizeof(str1)-5;
	int i;

	for(i=0;i<N;i++) {
		strncpy(str2[i],data+i,5);
		str2[i][5] = '\0';
	}
}

void ProtomonTransmit::cypherBits(char downID[4]){
	int i = 0;
	//Add start bit
	strcpy(data, "1");
	//Add downmon ID
	strcat(data, downID);
	//Add inverse of downmon ID:
		
	//While loop: Check if char on position i is 1 or 0 and invert
	while(downID[i] != '\0') {
		if(downID[i] = '1') {
				i = 0;
			} else {
				i = 1;
			}
		}
	//Add parity bit
	strcat(data,"1");
	//Add stop bit
	strcat(data,"1");
}
