#include <TimerOne.h>
#include "src/kernel/kernel.h"
#include "src/controller/ctrDrv.h"


void setup() {
  // put your setup code here, to run once:
  process p1 = {tst1, 1, 0};
  
  initCtrDrv();
  initDriver(DRV_LED);
  initDriver(DRV_SENSOR);

  Serial.begin(9600);

  kernelInit();

  if(kernelAddProc(&p1) == SUCCESS){
    Serial.println("1st process added\n");
  }

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(tick);

  kernelLoop();
}

void tick(){
  kernelTick();
}

float leitura;
char tst1(void){
  callDriver(DRV_SENSOR, SENSOR_LEITURA,&leitura);

  if(leitura>40)
    callDriver(DRV_LED, LED_VERDE, 0);
  else
    callDriver(DRV_LED, LED_VERMELHO, 0);
  
  Serial.println("Distancia: ");
  Serial.println(leitura);
  return REPEAT;
}

void loop() {
  // put your main code here, to run repeatedly:


}
