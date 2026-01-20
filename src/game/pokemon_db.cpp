#include "pokemon_db.h"
#include <string.h>

pokemon_t getStarter(int index) {
  pokemon_t pokemon;
  
  switch(index) {
    case 0: // Bulbasaur
      strcpy(pokemon.name, "BULBASAUR");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
      
    case 1: // Charmander
      strcpy(pokemon.name, "CHARMANDER");
      pokemon.maxHP = 39;
      pokemon.currentHP = 39;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FIRE;
      break;
      
    case 2: // Squirtle
      strcpy(pokemon.name, "SQUIRTLE");
      pokemon.maxHP = 44;
      pokemon.currentHP = 44;
      pokemon.attackMin = 4;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_WATER;
      break;
      
    default: // Default to Bulbasaur
      strcpy(pokemon.name, "BULBASAUR");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
  }
  
  return pokemon;
}

pokemon_t getEnemy(void) {
  pokemon_t pokemon;
  
  // Rattata
  strcpy(pokemon.name, "RATTATA");
  pokemon.maxHP = 30;
  pokemon.currentHP = 30;
  pokemon.attackMin = 3;
  pokemon.attackMax = 6;
  pokemon.type = TYPE_NORMAL;
  
  return pokemon;
}
