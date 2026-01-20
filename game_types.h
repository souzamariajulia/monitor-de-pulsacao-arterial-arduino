#ifndef GAME_TYPES_H
#define GAME_TYPES_H
#include "pokemon_types.h"

// Game state enumeration
enum {
  STATE_START,
  STATE_SELECT_POKEMON,
  STATE_EXPLORING,
  STATE_POKEMON_FOUND,
  STATE_CAPTURING,
  STATE_CAPTURE_SUCCESS,
  STATE_CAPTURE_FAILED,
  STATE_ROUTE_COMPLETE,
  STATE_POKEDEX,
  STATE_VICTORY
};

// Game state structure
typedef struct {
  int currentState;
  int previousState;
  unsigned long stateEntryTime;
} gameState_t;

// Route structure
typedef struct {
  int id;
  char name[16];
  int pokemonIds[20];  // Array of pokemon IDs available in this route
  int pokemonCount;    // Number of pokemon in this route
} route_t;

// Pokedex structure (bitfield)
#define POKEDEX_SIZE ((151 / 8) + 1)  // 19 bytes for 151 pokemon

#endif
