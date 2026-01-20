#include "state_machine.h"
#include <Arduino.h>

static gameState_t gameState;

char initStateMachine(void) {
  gameState.currentState = STATE_START;
  gameState.previousState = STATE_START;
  gameState.stateEntryTime = millis();
  return 0; // SUCCESS
}

void changeState(int newState) {
  gameState.previousState = gameState.currentState;
  gameState.currentState = newState;
  gameState.stateEntryTime = millis();
}

int getCurrentState(void) {
  return gameState.currentState;
}

char isStateTimeout(unsigned long timeout) {
  unsigned long currentTime = millis();
  if ((currentTime - gameState.stateEntryTime) >= timeout) {
    return 1; // True
  }
  return 0; // False
}
