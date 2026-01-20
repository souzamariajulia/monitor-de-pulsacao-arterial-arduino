#include "pokedex.h"
#include <string.h>

void initPokedex(char* pokedex) {
  memset(pokedex, 0, POKEDEX_SIZE);
}

void markPokemonCaptured(int id, char* pokedex) {
  if(id < 1 || id > 151) {
    return; // Invalid pokemon ID
  }
  
  // Convert to 0-based index
  int index = id - 1;
  
  // Calculate byte and bit positions
  int byteIndex = index / 8;
  int bitIndex = index % 8;
  
  // Set the bit
  pokedex[byteIndex] |= (1 << bitIndex);
}

char isPokemonCaptured(int id, char* pokedex) {
  if(id < 1 || id > 151) {
    return 0; // Invalid pokemon ID
  }
  
  // Convert to 0-based index
  int index = id - 1;
  
  // Calculate byte and bit positions
  int byteIndex = index / 8;
  int bitIndex = index % 8;
  
  // Check the bit
  return (pokedex[byteIndex] & (1 << bitIndex)) != 0;
}

int countCapturedPokemon(char* pokedex) {
  int count = 0;
  
  // Count bits set in all bytes (for first 151 pokemon)
  for(int i = 0; i < 151; i++) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      count++;
    }
  }
  
  return count;
}

int getNextCapturedPokemon(int currentId, char* pokedex) {
  // Start searching from the next pokemon
  for(int i = currentId; i < 151; i++) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      return i + 1;
    }
  }
  // Wrap around to beginning
  for(int i = 0; i < currentId; i++) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      return i + 1;
    }
  }
  return 0; // No captured pokemon found
}

int getPreviousCapturedPokemon(int currentId, char* pokedex) {
  // Start searching from the previous pokemon
  for(int i = currentId - 2; i >= 0; i--) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      return i + 1;
    }
  }
  // Wrap around to end
  for(int i = 150; i >= currentId; i--) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      return i + 1;
    }
  }
  return 0; // No captured pokemon found
}

int getFirstCapturedPokemon(char* pokedex) {
  for(int i = 0; i < 151; i++) {
    if(isPokemonCaptured(i + 1, pokedex)) {
      return i + 1;
    }
  }
  return 0; // No captured pokemon found
}