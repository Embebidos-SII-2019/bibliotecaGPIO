#include <gpio.h>
#include <stdio.h>

#define ERROR -1

#define PIN1 24
#define PIN2 23
#define PIN3 16

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1

int main(){
	//habilitando los puertos
	int deb=export(PIN1), deb1=export(PIN2), deb2=export(PIN3);
	//revisando errores
	if(deb==ERROR && deb1==ERROR && deb2==ERROR ){
		return(1);
	}
	//estableciendo los puertos
	deb=pinMode(PIN1, OUT);
	deb1=pinMode(PIN2, OUT);
	deb2=pinMode(PIN3, IN);
	if(deb==ERROR && deb1==ERROR && deb2==ERROR ){
		return(1);
	}
	//ciclo para realizar todo al mismo tiempo
	for(int i=0; i<10; i++){
		//escribiendo HIGH=1 en puerto 1
		deb=digitalWrite(PIN1, HIGH);
		//parpadeando por medio segundo en un ciclo
		deb1=blink(PIN2, 500000, 1); //freq=0.5s -> duration=1 ciclo
		//escribiendo LOW=0 en puerto 1
		deb=digitalWrite(PIN1, LOW);
		//leyendo del pin3
		printf("Value of pin%d is %d\n",PIN3,digitalRead(PIN3)); 
	}
	//liberando pines
	deb=unexport(PIN1);
	deb1=unexport(PIN2);
	deb2=unexport(PIN3);
	if(deb==ERROR && deb1==ERROR && deb2==ERROR){
		return(1);
	}
	return 0;
}
