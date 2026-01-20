#ifndef POKEMON_TYPES_H
#define POKEMON_TYPES_H

// Pokémon type enumeration
typedef enum {
  TYPE_NORMAL,
  TYPE_GRASS,
  TYPE_FIRE,
  TYPE_WATER,
  TYPE_BUG,
  TYPE_FLYING,
  TYPE_POISON,
  TYPE_ELECTRIC,
  TYPE_GROUND,
  TYPE_FIGHTING,
  TYPE_PSYCHIC,
  TYPE_ICE,
  TYPE_GHOST,
  TYPE_ROCK,
  TYPE_DRAGON
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
