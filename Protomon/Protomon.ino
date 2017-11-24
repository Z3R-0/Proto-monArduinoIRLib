#include "Protomon.h"
int main(){
	DDRB |= (1<<DDB5);
	DDRB &= ~(1<<DDB0);
	//Initialize int i
	int i = 0;
	for(;;){
		PORTB |= (1<<PORTB5);
		_delay_ms(20);


		PORTB &= ~(1<<PORTB5);
		_delay_ms(10);

		PORTB |= (1<<PORTB5);
		_delay_ms(10);


		PORTB &= ~(1<<PORTB5);
		_delay_ms(20);


		_delay_ms(100);
	}
}
