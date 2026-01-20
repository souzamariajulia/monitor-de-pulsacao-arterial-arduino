#ifndef DISPLAY_H
#define DISPLAY_H
#include "../controller/ctrDrv.h"

void displayMessage(const char* line1, const char* line2);
void displayPokemonInfo(const char* name, int currentHP, int maxHP);

#endif
