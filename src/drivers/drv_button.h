#ifndef DRV_BUTTON_H
	#define DRV_BUTTON_H
	#include "../include/dd_types.h"
	#include "../kernel/kernel.h"
	#include <Arduino.h>
	
	//lista de funções do driver
	enum {
		
		BUTTON_UP, BUTTON_DOWN, BUTTON_SELECT, BUTTON_A, BUTTON_B, BUTTON_END
	};
	
	//função de acesso ao driver
	
	driver * getButtonDriver(void);
		
	
#endif
