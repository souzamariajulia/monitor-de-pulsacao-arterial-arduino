#include "battle_logic.h"
#include <Arduino.h>

int calculateDamage(pokemon_t* attacker) {
  if (attacker == NULL) return 0;
  
  // Pokéwalker-style: random damage within range
  // random(min, max+1) gives inclusive range
  int damage = random(attacker->attackMin, attacker->attackMax + 1);
  return damage;
}

void applyDamage(pokemon_t* target, int damage) {
  if (target == NULL) return;
  
  target->currentHP -= damage;
  if (target->currentHP < 0) {
    target->currentHP = 0;
  }
}

int checkBattleEnd(pokemon_t* player, pokemon_t* enemy) {
  if (player == NULL || enemy == NULL) return 0;
  
  if (player->currentHP <= 0) {
    return STATE_DEFEAT;
  }
  
  if (enemy->currentHP <= 0) {
    return STATE_VICTORY;
  }
  
  return 0; // Battle continues
}
