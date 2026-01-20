#include "pokemon_db.h"
#include "pokedex.h"
#include <string.h>
#include <Arduino.h>

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

pokemon_t getPokemonById(int id) {
  pokemon_t pokemon;
  
  // Initialize with default values
  pokemon.maxHP = 50;
  pokemon.currentHP = 50;
  pokemon.attackMin = 4;
  pokemon.attackMax = 7;
  pokemon.type = TYPE_NORMAL;
  
  // Pokemon IDs 1-151 (Kanto)
  switch(id) {
    // Route 1 Pokemon
    case 19: // Rattata
      strcpy(pokemon.name, "RATTATA");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 16: // Pidgey
      strcpy(pokemon.name, "PIDGEY");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
      
    // Route 2 & Viridian Forest
    case 10: // Caterpie
      strcpy(pokemon.name, "CATERPIE");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 2;
      pokemon.attackMax = 5;
      pokemon.type = TYPE_GRASS;
      break;
    case 13: // Weedle
      strcpy(pokemon.name, "WEEDLE");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 2;
      pokemon.attackMax = 5;
      pokemon.type = TYPE_GRASS;
      break;
    case 11: // Metapod
      strcpy(pokemon.name, "METAPOD");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 2;
      pokemon.attackMax = 4;
      pokemon.type = TYPE_GRASS;
      break;
    case 14: // Kakuna
      strcpy(pokemon.name, "KAKUNA");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 2;
      pokemon.attackMax = 4;
      pokemon.type = TYPE_GRASS;
      break;
    case 25: // Pikachu
      strcpy(pokemon.name, "PIKACHU");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_NORMAL;
      break;
      
    // Route 3
    case 56: // Mankey
      strcpy(pokemon.name, "MANKEY");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 39: // Jigglypuff
      strcpy(pokemon.name, "JIGGLYPUFF");
      pokemon.maxHP = 115;
      pokemon.currentHP = 115;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 21: // Spearow
      strcpy(pokemon.name, "SPEAROW");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 29: // Nidoran♀
      strcpy(pokemon.name, "NIDORANF");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 32: // Nidoran♂
      strcpy(pokemon.name, "NIDORANM");
      pokemon.maxHP = 46;
      pokemon.currentHP = 46;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
      
    // Route 4
    case 20: // Raticate
      strcpy(pokemon.name, "RATICATE");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_NORMAL;
      break;
      
    // Starters
    case 1: // Bulbasaur
      strcpy(pokemon.name, "BULBASAUR");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
    case 4: // Charmander
      strcpy(pokemon.name, "CHARMANDER");
      pokemon.maxHP = 39;
      pokemon.currentHP = 39;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FIRE;
      break;
    case 7: // Squirtle
      strcpy(pokemon.name, "SQUIRTLE");
      pokemon.maxHP = 44;
      pokemon.currentHP = 44;
      pokemon.attackMin = 4;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_WATER;
      break;
      
    default:
      // Return a default pokemon for unknown IDs
      strcpy(pokemon.name, "UNKNOWN");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
  }
  
  return pokemon;
}

// Route data storage (static arrays)
static int route1_pokemon[] = {19, 16}; // Rattata, Pidgey
static int route2_pokemon[] = {19, 16, 10, 13}; // Rattata, Pidgey, Caterpie, Weedle
static int route3_pokemon[] = {16, 56, 39, 21, 29, 32}; // Pidgey, Mankey, Jigglypuff, Spearow, Nidoran♀, Nidoran♂
static int viridian_forest_pokemon[] = {10, 13, 11, 14, 25}; // Caterpie, Weedle, Metapod, Kakuna, Pikachu

route_t getRoute(int routeId) {
  route_t route;
  route.id = routeId;
  
  switch(routeId) {
    case 1:
      strcpy(route.name, "ROUTE 1");
      route.pokemonCount = 2;
      for(int i = 0; i < 2; i++) {
        route.pokemonIds[i] = route1_pokemon[i];
      }
      break;
      
    case 2:
      strcpy(route.name, "ROUTE 2");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = route2_pokemon[i];
      }
      break;
      
    case 3:
      strcpy(route.name, "ROUTE 3");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route3_pokemon[i];
      }
      break;
      
    case 4: // Viridian Forest
      strcpy(route.name, "VIRIDIAN F");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = viridian_forest_pokemon[i];
      }
      break;
      
    default:
      strcpy(route.name, "UNKNOWN");
      route.pokemonCount = 0;
      break;
  }
  
  return route;
}

int getRoutePokemonCount(int routeId) {
  route_t route = getRoute(routeId);
  return route.pokemonCount;
}

int* getRoutePokemonList(int routeId) {
  static int* result = NULL;
  route_t route = getRoute(routeId);
  
  // Return pointer to the appropriate static array
  switch(routeId) {
    case 1:
      result = route1_pokemon;
      break;
    case 2:
      result = route2_pokemon;
      break;
    case 3:
      result = route3_pokemon;
      break;
    case 4:
      result = viridian_forest_pokemon;
      break;
    default:
      result = NULL;
      break;
  }
  
  return result;
}

// Helper function to check if pokemon is captured (from pokedex.h)

int getRandomPokemonFromRoute(int routeId, char* pokedex) {
  route_t route = getRoute(routeId);
  
  if(route.pokemonCount == 0) {
    return 0;
  }
  
  // First, collect uncaptured pokemon
  int uncaptured[20];
  int uncapturedCount = 0;
  
  for(int i = 0; i < route.pokemonCount; i++) {
    if(!isPokemonCaptured(route.pokemonIds[i], pokedex)) {
      uncaptured[uncapturedCount] = route.pokemonIds[i];
      uncapturedCount++;
    }
  }
  
  if(uncapturedCount == 0) {
    return 0; // All pokemon in route are captured
  }
  
  // Return random uncaptured pokemon
  int randomIndex = random(0, uncapturedCount);
  return uncaptured[randomIndex];
}

int getTotalRoutes(void) {
  return 4; // Currently 4 routes (Route 1, 2, 3, and Viridian Forest)
}

char isRouteComplete(int routeId, char* pokedex) {
  route_t route = getRoute(routeId);
  
  if(route.pokemonCount == 0) {
    return 0;
  }
  
  // Check if all pokemon in route are captured
  for(int i = 0; i < route.pokemonCount; i++) {
    if(!isPokemonCaptured(route.pokemonIds[i], pokedex)) {
      return 0; // Found uncaptured pokemon
    }
  }
  
  return 1; // All pokemon captured
}