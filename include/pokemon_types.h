#ifndef POKEMON_TYPES_H
#define POKEMON_TYPES_H

// Pokémon type enumeration
typedef enum {
  TYPE_NORMAL,
  TYPE_GRASS,
  TYPE_FIRE,
  TYPE_WATER
} pokemon_type_t;

// Pokémon structure
typedef struct {
  char name[16];
  int maxHP;
  int currentHP;
  int attackMin;
  int attackMax;
  pokemon_type_t type;
} pokemon_t;

#endif
