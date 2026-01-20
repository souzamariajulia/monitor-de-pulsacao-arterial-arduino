#ifndef DRV_SENSOR_H
	#define DRV_SENSOR_H
	#include "../include/dd_types.h"
	#include "../kernel/kernel.h"
	#include <Arduino.h>
	
	//lista de fun��es do driver
	enum {
		
		SENSOR_LEITURA, SENSOR_END
	};
	
	//fun��o de acesso ao driver
	
	driver * getSensorDriver(void);
		
	
#endif
