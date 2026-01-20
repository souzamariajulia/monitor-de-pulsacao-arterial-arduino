#ifndef DRV_LCD_H
	#define DRV_LCD_H
	#include "../include/dd_types.h"
	#include "../kernel/kernel.h"
	#include <Arduino.h>
	#include <LiquidCrystal.h>
	
	//lista de funções do driver
	enum {
		
		LCD_INIT, LCD_CLEAR, LCD_PRINT, LCD_SET_CURSOR, LCD_END
	};
	
	//função de acesso ao driver
	
	driver * getLCDDriver(void);
		
	
#endif
