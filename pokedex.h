#ifndef POKEDEX_H
#define POKEDEX_H

#define POKEDEX_SIZE ((151 / 8) + 1)  // 19 bytes for 151 pokemon

// Pokedex functions
void markPokemonCaptured(int id, char* pokedex);
char isPokemonCaptured(int id, char* pokedex);
int countCapturedPokemon(char* pokedex);
void initPokedex(char* pokedex); // Initialize pokedex to all zeros
int getNextCapturedPokemon(int currentId, char* pokedex); // Get next captured pokemon ID (or 0 if none)
int getPreviousCapturedPokemon(int currentId, char* pokedex); // Get previous captured pokemon ID (or 0 if none)
int getFirstCapturedPokemon(char* pokedex); // Get first captured pokemon ID (or 0 if none)
int getNextCapturedPokemon(int currentId, char* pokedex); // Get next captured pokemon ID (or 0 if none)
int getPreviousCapturedPokemon(int currentId, char* pokedex); // Get previous captured pokemon ID (or 0 if none)
int getFirstCapturedPokemon(char* pokedex); // Get first captured pokemon ID (or 0 if none)

#endif