#include "drv_led.h"

static driver meu_cartao;

static ptrFuncDrv my_funcs[LED_END];

char vermelho(void * parameters){
	digitalWrite(20,LOW);
	digitalWrite(21,HIGH);
	return SUCCESS;
}

char verde (void * parameters){	
	digitalWrite(20,HIGH);
	digitalWrite(21,LOW);
	return SUCCESS;
}

char initGenerico(void * parameters){
	pinMode(21, OUTPUT);
	pinMode(20, OUTPUT);
	meu_cartao.id = (char) parameters;
	return SUCCESS;
}

driver * getLedDriver(void){
	meu_cartao.initFunc = initGenerico;
	my_funcs[LED_VERDE] = verde;
	my_funcs[LED_VERMELHO] = vermelho;
	meu_cartao.funcoes = my_funcs;
	return &meu_cartao;
}