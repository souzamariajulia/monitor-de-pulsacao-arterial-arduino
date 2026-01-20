#include "../include/dd_types.h"
#include "ctrDrv.h"
#include "../kernel/kernel.h"

static driver * drivers[QNTD_DRV];
static char dLoaded;

char initCtrDrv(void) {//incializa sem drivers carregados
  dLoaded = 0;
  return SUCCESS;
}

char initDriver(char newDriver) {
  char resp = FAIL;
  if(dLoaded < QNTD_DRV){
    drivers[dLoaded] = drvGetFunc[newDriver]();
    resp = drivers[dLoaded]->initFunc(newDriver);
    dLoaded++;
  }
  return resp;
}

char callDriver(char drv_id, char func_id, void *parameters) {
  for(int i = 0; i < dLoaded; i++){
    if(drv_id == drivers[i]->id){
      return drivers[i]->funcoes[func_id](parameters);
    }
  }
  return DRV_FUNC_NOT_FOUND;
}
