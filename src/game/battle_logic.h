#ifndef BATTLE_LOGIC_H
#define BATTLE_LOGIC_H
#include "../../include/pokemon_types.h"
#include "../../include/game_types.h"

int calculateDamage(pokemon_t* attacker);
void applyDamage(pokemon_t* target, int damage);
int checkBattleEnd(pokemon_t* player, pokemon_t* enemy);

#endif
