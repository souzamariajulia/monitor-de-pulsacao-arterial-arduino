#ifndef POKEMON_DB_H
#define POKEMON_DB_H
#include "pokemon_types.h"
#include "game_types.h"

pokemon_t getStarter(int index); // 0=Bulbasaur, 1=Charmander, 2=Squirtle
pokemon_t getPokemonById(int id); // Returns pokemon by ID (1-151)
route_t getRoute(int routeId); // Returns route data
int getRoutePokemonCount(int routeId); // Number of pokemon in route
int* getRoutePokemonList(int routeId); // Returns pointer to array of pokemon IDs in route
int getRandomPokemonFromRoute(int routeId, char* pokedex); // Random pokemon from route (only uncaptured)
int getTotalRoutes(void); // Total number of routes available
char isRouteComplete(int routeId, char* pokedex); // Check if all pokemon in route are captured

#endif
