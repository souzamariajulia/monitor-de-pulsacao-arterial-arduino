#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "game_types.h"

char initStateMachine(void);
void changeState(int newState);
int getCurrentState(void);
char isStateTimeout(unsigned long timeout);

#endif
