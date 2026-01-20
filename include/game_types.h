#ifndef GAME_TYPES_H
#define GAME_TYPES_H

// Game state enumeration
enum {
  STATE_START,
  STATE_SELECT_POKEMON,
  STATE_BATTLE,
  STATE_VICTORY,
  STATE_DEFEAT
};

// Game state structure
typedef struct {
  int currentState;
  int previousState;
  unsigned long stateEntryTime;
} gameState_t;

// Battle state structure
typedef struct {
  char playerTurn;
  int turnCount;
  pokemon_t* player;
  pokemon_t* enemy;
} battle_t;

#endif
