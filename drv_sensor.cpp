#include "drv_sensor.h"
#define TRIG_PIN 4
#define ECHO_PIN 3

static driver meu_cartao;

static ptrFuncDrv my_funcs[SENSOR_END];

char leitura(void * parameters){
	if (parameters == NULL) return FAIL;

  float *dist = (float *)parameters;

  // Gera pulso no TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Mede duração do ECHO (coloque um timeout para não travar)
  unsigned long duracao = pulseIn(ECHO_PIN, HIGH, 30000UL); // ~30 ms ≈ até ~5m

  if (duracao == 0) {
    return FAIL; // sem eco (fora de alcance, ruído, etc.)
  }

  float distancia = (float)duracao * 0.034f / 2.0f; // cm

  *dist = distancia;
  
  return SUCCESS;
}


char initGenericoSensor(void * parameters){
	pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
	meu_cartao.id = (char) parameters;
	return SUCCESS;
}

driver * getSensorDriver(void){
	meu_cartao.initFunc = initGenericoSensor;
	my_funcs[SENSOR_LEITURA] = leitura;
	meu_cartao.funcoes = my_funcs;
	return &meu_cartao;
}