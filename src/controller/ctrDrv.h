#ifndef CTRDRV_H
#define CTRDRV_H
#define QNTD_DRV 20
#include "../include/dd_types.h"
#include "../drivers/drv_led.h"
#include "../drivers/drv_sensor.h"

#define DRV_FUNC_NOT_FOUND 42

//Funções disponibilizadas pela controladora

char initCtrDrv();	
char initDriver(char newDriver);	
char callDriver(char drv_id, char func_id, void *parameters);

enum {
  DRV_LED,
  DRV_SENSOR,
  DRV_END // DRV_END deve sempre ser o último , para facilitar o controle da quantidade de drivers
};

static ptrGetDrv drvGetFunc[DRV_END] = {
getLedDriver,
getSensorDriver};
//vetor com as funções para retorno das estruturas dos drivers. 
//Deve estar na mesma ordem que o enumerador acima

#endif
