#ifndef DRV_LED_H
	#define DRV_LED_H
	#include "../include/dd_types.h"
	#include "../kernel/kernel.h"
	#include <Arduino.h>
	
	//lista de fun��es do driver
	enum {
		
		LED_VERDE, LED_VERMELHO, LED_END
	};
	
	//fun��o de acesso ao driver
	
	driver * getLedDriver(void);
		
	
#endif
