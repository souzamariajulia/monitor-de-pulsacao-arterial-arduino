#include "drv_button.h"

#define BUTTON_UP_PIN 22
#define BUTTON_DOWN_PIN 23
#define BUTTON_SELECT_PIN 24
#define BUTTON_A_PIN 25
#define BUTTON_B_PIN 26

#define DEBOUNCE_DELAY 50

static driver meu_cartao;
static ptrFuncDrv my_funcs[BUTTON_END];

// Button state for debouncing
static unsigned long lastDebounceTime[BUTTON_END];
static int lastButtonState[BUTTON_END];
static int buttonState[BUTTON_END];
static int reading[BUTTON_END];

// Helper function to read button state
static char readButtonState(int buttonIndex, int *result) {
  if (buttonIndex < 0 || buttonIndex >= BUTTON_END) return FAIL;
  
  // Read the button pin state
  int pin;
  switch(buttonIndex) {
    case BUTTON_UP:
      pin = BUTTON_UP_PIN;
      break;
    case BUTTON_DOWN:
      pin = BUTTON_DOWN_PIN;
      break;
    case BUTTON_SELECT:
      pin = BUTTON_SELECT_PIN;
      break;
    case BUTTON_A:
      pin = BUTTON_A_PIN;
      break;
    case BUTTON_B:
      pin = BUTTON_B_PIN;
      break;
    default:
      return FAIL;
  }
  
  // Read current state
  reading[buttonIndex] = digitalRead(pin);
  
  // Debounce logic
  if (reading[buttonIndex] != lastButtonState[buttonIndex]) {
    lastDebounceTime[buttonIndex] = millis();
  }
  
  if ((millis() - lastDebounceTime[buttonIndex]) > DEBOUNCE_DELAY) {
    if (reading[buttonIndex] != buttonState[buttonIndex]) {
      buttonState[buttonIndex] = reading[buttonIndex];
    }
  }
  
  lastButtonState[buttonIndex] = reading[buttonIndex];
  
  // Return inverted state (LOW = pressed due to pull-up)
  *result = (buttonState[buttonIndex] == LOW) ? 1 : 0;
  
  return SUCCESS;
}

char readButtonUp(void * parameters) {
  int buttonIndex = BUTTON_UP;
  if (parameters == NULL) return FAIL;
  return readButtonState(buttonIndex, (int *)parameters);
}

char readButtonDown(void * parameters) {
  int buttonIndex = BUTTON_DOWN;
  if (parameters == NULL) return FAIL;
  return readButtonState(buttonIndex, (int *)parameters);
}

char readButtonSelect(void * parameters) {
  int buttonIndex = BUTTON_SELECT;
  if (parameters == NULL) return FAIL;
  return readButtonState(buttonIndex, (int *)parameters);
}

char readButtonA(void * parameters) {
  int buttonIndex = BUTTON_A;
  if (parameters == NULL) return FAIL;
  return readButtonState(buttonIndex, (int *)parameters);
}

char readButtonB(void * parameters) {
  int buttonIndex = BUTTON_B;
  if (parameters == NULL) return FAIL;
  return readButtonState(buttonIndex, (int *)parameters);
}

char initGenericoButton(void * parameters){
	pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
	pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);
	pinMode(BUTTON_SELECT_PIN, INPUT_PULLUP);
	pinMode(BUTTON_A_PIN, INPUT_PULLUP);
	pinMode(BUTTON_B_PIN, INPUT_PULLUP);
	
	meu_cartao.id = (char) parameters;
	
	// Initialize debounce variables
	for(int i = 0; i < BUTTON_END; i++) {
		lastDebounceTime[i] = 0;
		lastButtonState[i] = HIGH;
		buttonState[i] = HIGH;
		reading[i] = HIGH;
	}
	
	return SUCCESS;
}

driver * getButtonDriver(void){
	meu_cartao.initFunc = initGenericoButton;
	my_funcs[BUTTON_UP] = readButtonUp;
	my_funcs[BUTTON_DOWN] = readButtonDown;
	my_funcs[BUTTON_SELECT] = readButtonSelect;
	my_funcs[BUTTON_A] = readButtonA;
	my_funcs[BUTTON_B] = readButtonB;
	meu_cartao.funcoes = my_funcs;
	return &meu_cartao;
}
