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
    case 1: // Bulbasaur
      strcpy(pokemon.name, "BULBASAUR");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
    case 2: // Ivysaur
      strcpy(pokemon.name, "IVYSAUR");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_GRASS;
      break;
    case 3: // Venusaur
      strcpy(pokemon.name, "VENUSAUR");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
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
    case 5: // Charmeleon
      strcpy(pokemon.name, "CHARMELEON");
      pokemon.maxHP = 58;
      pokemon.currentHP = 58;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_FIRE;
      break;
    case 6: // Charizard
      strcpy(pokemon.name, "CHARIZARD");
      pokemon.maxHP = 78;
      pokemon.currentHP = 78;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
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
    case 8: // Wartortle
      strcpy(pokemon.name, "WARTORTLE");
      pokemon.maxHP = 59;
      pokemon.currentHP = 59;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_WATER;
      break;
    case 9: // Blastoise
      strcpy(pokemon.name, "BLASTOISE");
      pokemon.maxHP = 79;
      pokemon.currentHP = 79;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_WATER;
      break;
    case 10: // Caterpie
      strcpy(pokemon.name, "CATERPIE");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 2;
      pokemon.attackMax = 5;
      pokemon.type = TYPE_BUG;
      break;
    case 11: // Metapod
      strcpy(pokemon.name, "METAPOD");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 2;
      pokemon.attackMax = 4;
      pokemon.type = TYPE_BUG;
      break;
    case 12: // Butterfree
      strcpy(pokemon.name, "BUTTERFREE");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 6;
      pokemon.attackMax = 10;
      pokemon.type = TYPE_BUG;
      break;
    case 13: // Weedle
      strcpy(pokemon.name, "WEEDLE");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 2;
      pokemon.attackMax = 5;
      pokemon.type = TYPE_BUG;
      break;
    case 14: // Kakuna
      strcpy(pokemon.name, "KAKUNA");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 2;
      pokemon.attackMax = 4;
      pokemon.type = TYPE_BUG;
      break;
    case 15: // Beedrill
      strcpy(pokemon.name, "BEEDRILL");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_BUG;
      break;
    case 16: // Pidgey
      strcpy(pokemon.name, "PIDGEY");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_FLYING;
      break;
    case 17: // Pidgeotto
      strcpy(pokemon.name, "PIDGEOTTO");
      pokemon.maxHP = 63;
      pokemon.currentHP = 63;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_FLYING;
      break;
    case 18: // Pidgeot
      strcpy(pokemon.name, "PIDGEOT");
      pokemon.maxHP = 83;
      pokemon.currentHP = 83;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_FLYING;
      break;
    case 19: // Rattata
      strcpy(pokemon.name, "RATTATA");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 20: // Raticate
      strcpy(pokemon.name, "RATICATE");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_NORMAL;
      break;
    case 21: // Spearow
      strcpy(pokemon.name, "SPEAROW");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_FLYING;
      break;
    case 22: // Fearow
      strcpy(pokemon.name, "FEAROW");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_FLYING;
      break;
    case 23: // Ekans
      strcpy(pokemon.name, "EKANS");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_POISON;
      break;
    case 24: // Arbok
      strcpy(pokemon.name, "ARBOK");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_POISON;
      break;
    case 25: // Pikachu
      strcpy(pokemon.name, "PIKACHU");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 26: // Raichu
      strcpy(pokemon.name, "RAICHU");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 27: // Sandshrew
      strcpy(pokemon.name, "SANDSHREW");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GROUND;
      break;
    case 28: // Sandslash
      strcpy(pokemon.name, "SANDSLASH");
      pokemon.maxHP = 75;
      pokemon.currentHP = 75;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_GROUND;
      break;
    case 29: // Nidoran♀
      strcpy(pokemon.name, "NIDORANF");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_POISON;
      break;
    case 30: // Nidorina
      strcpy(pokemon.name, "NIDORINA");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_POISON;
      break;
    case 31: // Nidoqueen
      strcpy(pokemon.name, "NIDOQUEEN");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_POISON;
      break;
    case 32: // Nidoran♂
      strcpy(pokemon.name, "NIDORANM");
      pokemon.maxHP = 46;
      pokemon.currentHP = 46;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_POISON;
      break;
    case 33: // Nidorino
      strcpy(pokemon.name, "NIDORINO");
      pokemon.maxHP = 61;
      pokemon.currentHP = 61;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_POISON;
      break;
    case 34: // Nidoking
      strcpy(pokemon.name, "NIDOKING");
      pokemon.maxHP = 81;
      pokemon.currentHP = 81;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_POISON;
      break;
    case 35: // Clefairy
      strcpy(pokemon.name, "CLEFAIRY");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 36: // Clefable
      strcpy(pokemon.name, "CLEFABLE");
      pokemon.maxHP = 95;
      pokemon.currentHP = 95;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_NORMAL;
      break;
    case 37: // Vulpix
      strcpy(pokemon.name, "VULPIX");
      pokemon.maxHP = 38;
      pokemon.currentHP = 38;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_FIRE;
      break;
    case 38: // Ninetales
      strcpy(pokemon.name, "NINETALES");
      pokemon.maxHP = 73;
      pokemon.currentHP = 73;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_FIRE;
      break;
    case 39: // Jigglypuff
      strcpy(pokemon.name, "JIGGLYPUFF");
      pokemon.maxHP = 115;
      pokemon.currentHP = 115;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 40: // Wigglytuff
      strcpy(pokemon.name, "WIGGLYTUFF");
      pokemon.maxHP = 140;
      pokemon.currentHP = 140;
      pokemon.attackMin = 6;
      pokemon.attackMax = 10;
      pokemon.type = TYPE_NORMAL;
      break;
    case 41: // Zubat
      strcpy(pokemon.name, "ZUBAT");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_FLYING;
      break;
    case 42: // Golbat
      strcpy(pokemon.name, "GOLBAT");
      pokemon.maxHP = 75;
      pokemon.currentHP = 75;
      pokemon.attackMin = 6;
      pokemon.attackMax = 10;
      pokemon.type = TYPE_FLYING;
      break;
    case 43: // Oddish
      strcpy(pokemon.name, "ODDISH");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_GRASS;
      break;
    case 44: // Gloom
      strcpy(pokemon.name, "GLOOM");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_GRASS;
      break;
    case 45: // Vileplume
      strcpy(pokemon.name, "VILEPLUME");
      pokemon.maxHP = 75;
      pokemon.currentHP = 75;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_GRASS;
      break;
    case 46: // Paras
      strcpy(pokemon.name, "PARAS");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_BUG;
      break;
    case 47: // Parasect
      strcpy(pokemon.name, "PARASECT");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_BUG;
      break;
    case 48: // Venonat
      strcpy(pokemon.name, "VENONAT");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_BUG;
      break;
    case 49: // Venomoth
      strcpy(pokemon.name, "VENOMOTH");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_BUG;
      break;
    case 50: // Diglett
      strcpy(pokemon.name, "DIGLETT");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_GROUND;
      break;
    case 51: // Dugtrio
      strcpy(pokemon.name, "DUGTRIO");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_GROUND;
      break;
    case 52: // Meowth
      strcpy(pokemon.name, "MEOWTH");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 53: // Persian
      strcpy(pokemon.name, "PERSIAN");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_NORMAL;
      break;
    case 54: // Psyduck
      strcpy(pokemon.name, "PSYDUCK");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_WATER;
      break;
    case 55: // Golduck
      strcpy(pokemon.name, "GOLDUCK");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_WATER;
      break;
    case 56: // Mankey
      strcpy(pokemon.name, "MANKEY");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 57: // Primeape
      strcpy(pokemon.name, "PRIMEAPE");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 58: // Growlithe
      strcpy(pokemon.name, "GROWLITHE");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FIRE;
      break;
    case 59: // Arcanine
      strcpy(pokemon.name, "ARCANINE");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_FIRE;
      break;
    case 60: // Poliwag
      strcpy(pokemon.name, "POLIWAG");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_WATER;
      break;
    case 61: // Poliwhirl
      strcpy(pokemon.name, "POLIWHIRL");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_WATER;
      break;
    case 62: // Poliwrath
      strcpy(pokemon.name, "POLIWRATH");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_WATER;
      break;
    case 63: // Abra
      strcpy(pokemon.name, "ABRA");
      pokemon.maxHP = 25;
      pokemon.currentHP = 25;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 64: // Kadabra
      strcpy(pokemon.name, "KADABRA");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 65: // Alakazam
      strcpy(pokemon.name, "ALAKAZAM");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 66: // Machop
      strcpy(pokemon.name, "MACHOP");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 67: // Machoke
      strcpy(pokemon.name, "MACHOKE");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 68: // Machamp
      strcpy(pokemon.name, "MACHAMP");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 69: // Bellsprout
      strcpy(pokemon.name, "BELLSPROUT");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
    case 70: // Weepinbell
      strcpy(pokemon.name, "WEEPINBELL");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_GRASS;
      break;
    case 71: // Victreebel
      strcpy(pokemon.name, "VICTREEBEL");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_GRASS;
      break;
    case 72: // Tentacool
      strcpy(pokemon.name, "TENTACOOL");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_WATER;
      break;
    case 73: // Tentacruel
      strcpy(pokemon.name, "TENTACRUEL");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_WATER;
      break;
    case 74: // Geodude
      strcpy(pokemon.name, "GEODUDE");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ROCK;
      break;
    case 75: // Graveler
      strcpy(pokemon.name, "GRAVELER");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_ROCK;
      break;
    case 76: // Golem
      strcpy(pokemon.name, "GOLEM");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_ROCK;
      break;
    case 77: // Ponyta
      strcpy(pokemon.name, "PONYTA");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FIRE;
      break;
    case 78: // Rapidash
      strcpy(pokemon.name, "RAPIDASH");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_FIRE;
      break;
    case 79: // Slowpoke
      strcpy(pokemon.name, "SLOWPOKE");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_WATER;
      break;
    case 80: // Slowbro
      strcpy(pokemon.name, "SLOWBRO");
      pokemon.maxHP = 95;
      pokemon.currentHP = 95;
      pokemon.attackMin = 6;
      pokemon.attackMax = 10;
      pokemon.type = TYPE_WATER;
      break;
    case 81: // Magnemite
      strcpy(pokemon.name, "MAGNEMITE");
      pokemon.maxHP = 25;
      pokemon.currentHP = 25;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 82: // Magneton
      strcpy(pokemon.name, "MAGNETON");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 83: // Farfetch'd
      strcpy(pokemon.name, "FARFETCHD");
      pokemon.maxHP = 52;
      pokemon.currentHP = 52;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FLYING;
      break;
    case 84: // Doduo
      strcpy(pokemon.name, "DODUO");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_FLYING;
      break;
    case 85: // Dodrio
      strcpy(pokemon.name, "DODRIO");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_FLYING;
      break;
    case 86: // Seel
      strcpy(pokemon.name, "SEEL");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_ICE;
      break;
    case 87: // Dewgong
      strcpy(pokemon.name, "DEWGONG");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_ICE;
      break;
    case 88: // Grimer
      strcpy(pokemon.name, "GRIMER");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_POISON;
      break;
    case 89: // Muk
      strcpy(pokemon.name, "MUK");
      pokemon.maxHP = 105;
      pokemon.currentHP = 105;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_POISON;
      break;
    case 90: // Shellder
      strcpy(pokemon.name, "SHELLDER");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_WATER;
      break;
    case 91: // Cloyster
      strcpy(pokemon.name, "CLOYSTER");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_ICE;
      break;
    case 92: // Gastly
      strcpy(pokemon.name, "GASTLY");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_GHOST;
      break;
    case 93: // Haunter
      strcpy(pokemon.name, "HAUNTER");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_GHOST;
      break;
    case 94: // Gengar
      strcpy(pokemon.name, "GENGAR");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_GHOST;
      break;
    case 95: // Onix
      strcpy(pokemon.name, "ONIX");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_ROCK;
      break;
    case 96: // Drowzee
      strcpy(pokemon.name, "DROWZEE");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 97: // Hypno
      strcpy(pokemon.name, "HYPNO");
      pokemon.maxHP = 85;
      pokemon.currentHP = 85;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 98: // Krabby
      strcpy(pokemon.name, "KRABBY");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_WATER;
      break;
    case 99: // Kingler
      strcpy(pokemon.name, "KINGLER");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_WATER;
      break;
    case 100: // Voltorb
      strcpy(pokemon.name, "VOLTORB");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 101: // Electrode
      strcpy(pokemon.name, "ELECTRODE");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 102: // Exeggcute
      strcpy(pokemon.name, "EXEGGCUTE");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
    case 103: // Exeggutor
      strcpy(pokemon.name, "EXEGGUTOR");
      pokemon.maxHP = 95;
      pokemon.currentHP = 95;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_GRASS;
      break;
    case 104: // Cubone
      strcpy(pokemon.name, "CUBONE");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GROUND;
      break;
    case 105: // Marowak
      strcpy(pokemon.name, "MAROWAK");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_GROUND;
      break;
    case 106: // Hitmonlee
      strcpy(pokemon.name, "HITMONLEE");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 107: // Hitmonchan
      strcpy(pokemon.name, "HITMONCHAN");
      pokemon.maxHP = 50;
      pokemon.currentHP = 50;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_FIGHTING;
      break;
    case 108: // Lickitung
      strcpy(pokemon.name, "LICKITUNG");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 109: // Koffing
      strcpy(pokemon.name, "KOFFING");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_POISON;
      break;
    case 110: // Weezing
      strcpy(pokemon.name, "WEEZING");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_POISON;
      break;
    case 111: // Rhyhorn
      strcpy(pokemon.name, "RHYHORN");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ROCK;
      break;
    case 112: // Rhydon
      strcpy(pokemon.name, "RHYDON");
      pokemon.maxHP = 105;
      pokemon.currentHP = 105;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_ROCK;
      break;
    case 113: // Chansey
      strcpy(pokemon.name, "CHANSEY");
      pokemon.maxHP = 250;
      pokemon.currentHP = 250;
      pokemon.attackMin = 3;
      pokemon.attackMax = 6;
      pokemon.type = TYPE_NORMAL;
      break;
    case 114: // Tangela
      strcpy(pokemon.name, "TANGELA");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_GRASS;
      break;
    case 115: // Kangaskhan
      strcpy(pokemon.name, "KANGASKHAN");
      pokemon.maxHP = 105;
      pokemon.currentHP = 105;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_NORMAL;
      break;
    case 116: // Horsea
      strcpy(pokemon.name, "HORSEA");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_WATER;
      break;
    case 117: // Seadra
      strcpy(pokemon.name, "SEADRA");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_WATER;
      break;
    case 118: // Goldeen
      strcpy(pokemon.name, "GOLDEEN");
      pokemon.maxHP = 45;
      pokemon.currentHP = 45;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_WATER;
      break;
    case 119: // Seaking
      strcpy(pokemon.name, "SEAKING");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_WATER;
      break;
    case 120: // Staryu
      strcpy(pokemon.name, "STARYU");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_WATER;
      break;
    case 121: // Starmie
      strcpy(pokemon.name, "STARMIE");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_WATER;
      break;
    case 122: // Mr. Mime
      strcpy(pokemon.name, "MRMIME");
      pokemon.maxHP = 40;
      pokemon.currentHP = 40;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 123: // Scyther
      strcpy(pokemon.name, "SCYTHER");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_BUG;
      break;
    case 124: // Jynx
      strcpy(pokemon.name, "JYNX");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_ICE;
      break;
    case 125: // Electabuzz
      strcpy(pokemon.name, "ELECTABUZZ");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 126: // Magmar
      strcpy(pokemon.name, "MAGMAR");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_FIRE;
      break;
    case 127: // Pinsir
      strcpy(pokemon.name, "PINSIR");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_BUG;
      break;
    case 128: // Tauros
      strcpy(pokemon.name, "TAUROS");
      pokemon.maxHP = 75;
      pokemon.currentHP = 75;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_NORMAL;
      break;
    case 129: // Magikarp
      strcpy(pokemon.name, "MAGIKARP");
      pokemon.maxHP = 20;
      pokemon.currentHP = 20;
      pokemon.attackMin = 1;
      pokemon.attackMax = 2;
      pokemon.type = TYPE_WATER;
      break;
    case 130: // Gyarados
      strcpy(pokemon.name, "GYARADOS");
      pokemon.maxHP = 95;
      pokemon.currentHP = 95;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_WATER;
      break;
    case 131: // Lapras
      strcpy(pokemon.name, "LAPRAS");
      pokemon.maxHP = 130;
      pokemon.currentHP = 130;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_ICE;
      break;
    case 132: // Ditto
      strcpy(pokemon.name, "DITTO");
      pokemon.maxHP = 48;
      pokemon.currentHP = 48;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 133: // Eevee
      strcpy(pokemon.name, "EEVEE");
      pokemon.maxHP = 55;
      pokemon.currentHP = 55;
      pokemon.attackMin = 4;
      pokemon.attackMax = 7;
      pokemon.type = TYPE_NORMAL;
      break;
    case 134: // Vaporeon
      strcpy(pokemon.name, "VAPOREON");
      pokemon.maxHP = 130;
      pokemon.currentHP = 130;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_WATER;
      break;
    case 135: // Jolteon
      strcpy(pokemon.name, "JOLTEON");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 136: // Flareon
      strcpy(pokemon.name, "FLAREON");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_FIRE;
      break;
    case 137: // Porygon
      strcpy(pokemon.name, "PORYGON");
      pokemon.maxHP = 65;
      pokemon.currentHP = 65;
      pokemon.attackMin = 6;
      pokemon.attackMax = 9;
      pokemon.type = TYPE_NORMAL;
      break;
    case 138: // Omanyte
      strcpy(pokemon.name, "OMANYTE");
      pokemon.maxHP = 35;
      pokemon.currentHP = 35;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ROCK;
      break;
    case 139: // Omastar
      strcpy(pokemon.name, "OMASTAR");
      pokemon.maxHP = 70;
      pokemon.currentHP = 70;
      pokemon.attackMin = 8;
      pokemon.attackMax = 12;
      pokemon.type = TYPE_ROCK;
      break;
    case 140: // Kabuto
      strcpy(pokemon.name, "KABUTO");
      pokemon.maxHP = 30;
      pokemon.currentHP = 30;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_ROCK;
      break;
    case 141: // Kabutops
      strcpy(pokemon.name, "KABUTOPS");
      pokemon.maxHP = 60;
      pokemon.currentHP = 60;
      pokemon.attackMin = 9;
      pokemon.attackMax = 14;
      pokemon.type = TYPE_ROCK;
      break;
    case 142: // Aerodactyl
      strcpy(pokemon.name, "AERODACTYL");
      pokemon.maxHP = 80;
      pokemon.currentHP = 80;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_FLYING;
      break;
    case 143: // Snorlax
      strcpy(pokemon.name, "SNORLAX");
      pokemon.maxHP = 160;
      pokemon.currentHP = 160;
      pokemon.attackMin = 8;
      pokemon.attackMax = 13;
      pokemon.type = TYPE_NORMAL;
      break;
    case 144: // Articuno
      strcpy(pokemon.name, "ARTICUNO");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_ICE;
      break;
    case 145: // Zapdos
      strcpy(pokemon.name, "ZAPDOS");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_ELECTRIC;
      break;
    case 146: // Moltres
      strcpy(pokemon.name, "MOLTRES");
      pokemon.maxHP = 90;
      pokemon.currentHP = 90;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_FIRE;
      break;
    case 147: // Dratini
      strcpy(pokemon.name, "DRATINI");
      pokemon.maxHP = 41;
      pokemon.currentHP = 41;
      pokemon.attackMin = 5;
      pokemon.attackMax = 8;
      pokemon.type = TYPE_DRAGON;
      break;
    case 148: // Dragonair
      strcpy(pokemon.name, "DRAGONAIR");
      pokemon.maxHP = 61;
      pokemon.currentHP = 61;
      pokemon.attackMin = 7;
      pokemon.attackMax = 11;
      pokemon.type = TYPE_DRAGON;
      break;
    case 149: // Dragonite
      strcpy(pokemon.name, "DRAGONITE");
      pokemon.maxHP = 91;
      pokemon.currentHP = 91;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_DRAGON;
      break;
    case 150: // Mewtwo
      strcpy(pokemon.name, "MEWTWO");
      pokemon.maxHP = 106;
      pokemon.currentHP = 106;
      pokemon.attackMin = 12;
      pokemon.attackMax = 18;
      pokemon.type = TYPE_PSYCHIC;
      break;
    case 151: // Mew
      strcpy(pokemon.name, "MEW");
      pokemon.maxHP = 100;
      pokemon.currentHP = 100;
      pokemon.attackMin = 10;
      pokemon.attackMax = 15;
      pokemon.type = TYPE_PSYCHIC;
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
// 🔰 Região Inicial
static int route1_pokemon[] = {19, 16}; // Route 1 - Rattata, Pidgey
static int route2_pokemon[] = {19, 16, 10, 13}; // Route 2 - Rattata, Pidgey, Caterpie, Weedle
static int viridian_forest_pokemon[] = {10, 13, 11, 14, 25}; // Viridian Forest - Caterpie, Weedle, Metapod, Kakuna, Pikachu

// 🪨 Área de Pewter / Mt. Moon
static int route3_pokemon[] = {16, 56, 39, 21, 29, 32}; // Route 3 - Pidgey, Mankey, Jigglypuff, Spearow, Nidoran♀, Nidoran♂
static int mt_moon_pokemon[] = {41, 74, 35, 46}; // Mt. Moon - Zubat, Geodude, Clefairy, Paras
static int route4_pokemon[] = {19, 21, 23, 27, 56}; // Route 4 - Rattata, Spearow, Ekans, Sandshrew, Mankey

// 💧 Área de Cerulean
static int route24_pokemon[] = {63, 69, 43, 16, 48}; // Route 24 (Nugget Bridge) - Abra, Bellsprout, Oddish, Pidgey, Venonat
static int route25_pokemon[] = {63, 69, 43, 16, 48, 54}; // Route 25 (Sea Cottage) - Abra, Bellsprout, Oddish, Pidgey, Venonat, Psyduck
static int route5_pokemon[] = {16, 52, 43, 69, 63}; // Route 5 - Pidgey, Meowth, Oddish, Bellsprout, Abra
static int route6_pokemon[] = {16, 52, 43, 69, 63, 54}; // Route 6 - Pidgey, Meowth, Oddish, Bellsprout, Abra, Psyduck

// ⚡ Vermilion
static int route11_pokemon[] = {96, 97, 81, 100}; // Route 11 - Drowzee, Hypno, Magnemite, Voltorb
static int digletts_cave_pokemon[] = {50, 51}; // Diglett's Cave - Diglett, Dugtrio

// 🌿 Área Central
static int route7_pokemon[] = {16, 52, 37, 43, 69, 58}; // Route 7 - Pidgey, Meowth, Vulpix, Oddish, Bellsprout, Growlithe
static int route8_pokemon[] = {16, 52, 23, 27, 37, 58}; // Route 8 - Pidgey, Meowth, Ekans, Sandshrew, Vulpix, Growlithe
static int route9_pokemon[] = {19, 21, 23, 27}; // Route 9 - Rattata, Spearow, Ekans, Sandshrew
static int route10_pokemon[] = {100, 81}; // Route 10 - Voltorb, Magnemite
static int rock_tunnel_pokemon[] = {41, 42, 66, 74}; // Rock Tunnel - Zubat, Golbat, Machop, Geodude

// 🌸 Lavender / Torre Pokémon
static int pokemon_tower_pokemon[] = {92, 93, 41, 42}; // Pokemon Tower - Gastly, Haunter, Zubat, Golbat

// 🏙️ Saffron City
static int silph_co_pokemon[] = {100, 101, 81, 82, 64, 65}; // Silph Co. - Voltorb, Electrode, Magnemite, Magneton, Kadabra, Alakazam
static int fighting_dojo_pokemon[] = {66, 67, 68, 56, 57, 106, 107}; // Fighting Dojo - Machop, Machoke, Machamp, Mankey, Primeape, Hitmonlee, Hitmonchan

// 🌺 Celadon City
static int celadon_game_corner_pokemon[] = {100, 101, 81, 82}; // Celadon Game Corner - Voltorb, Electrode, Magnemite, Magneton
static int rocket_hideout_pokemon[] = {88, 89, 109, 110, 23, 24}; // Rocket Hideout - Grimer, Muk, Koffing, Weezing, Ekans, Arbok

// 🌊 Fuchsia Area
static int route12_pokemon[] = {43, 44, 48, 69, 70, 83}; // Route 12 - Oddish, Gloom, Venonat, Bellsprout, Weepinbell, Farfetch'd
static int route13_pokemon[] = {16, 17, 43, 44, 48, 69, 70, 132}; // Route 13 - Pidgey, Pidgeotto, Oddish, Gloom, Venonat, Bellsprout, Weepinbell, Ditto
static int route14_pokemon[] = {16, 17, 43, 44, 48, 69, 70, 132}; // Route 14 - Pidgey, Pidgeotto, Oddish, Gloom, Venonat, Bellsprout, Weepinbell, Ditto
static int route15_pokemon[] = {16, 17, 43, 44, 48, 69, 70, 132}; // Route 15 - Pidgey, Pidgeotto, Oddish, Gloom, Venonat, Bellsprout, Weepinbell, Ditto
static int safari_zone_pokemon[] = {29, 30, 32, 33, 43, 44, 46, 47, 48, 49, 102, 103, 111, 112, 115, 123, 127, 128}; // Safari Zone - Nidoran♀, Nidorina, Nidoran♂, Nidorino, Oddish, Gloom, Paras, Parasect, Venonat, Venomoth, Exeggcute, Exeggutor, Rhyhorn, Rhydon, Kangaskhan, Scyther, Pinsir, Tauros

// 🌋 Ilhas / Água
static int route16_pokemon[] = {19, 20, 21, 22, 84}; // Route 16 - Rattata, Raticate, Spearow, Fearow, Doduo
static int route17_pokemon[] = {16, 17, 19, 20, 21, 22, 84, 85}; // Route 17 (Cycling Road) - Pidgey, Pidgeotto, Rattata, Raticate, Spearow, Fearow, Doduo, Dodrio
static int route18_pokemon[] = {19, 20, 21, 22, 84, 85}; // Route 18 - Rattata, Raticate, Spearow, Fearow, Doduo, Dodrio

// 🏝️ Seafoam / Cinnabar
static int route19_pokemon[] = {72, 73, 90, 120, 129, 130}; // Route 19 - Tentacool, Tentacruel, Shellder, Staryu, Magikarp, Gyarados
static int route20_pokemon[] = {72, 73, 90, 120, 129, 130}; // Route 20 - Tentacool, Tentacruel, Shellder, Staryu, Magikarp, Gyarados
static int seafoam_islands_pokemon[] = {72, 73, 86, 87, 90, 91, 129, 130}; // Seafoam Islands - Tentacool, Tentacruel, Seel, Dewgong, Shellder, Cloyster, Magikarp, Gyarados
static int route21_pokemon[] = {16, 17, 19, 20, 114}; // Route 21 - Pidgey, Pidgeotto, Rattata, Raticate, Tangela

// 🔥 Cinnabar Island
static int pokemon_mansion_pokemon[] = {88, 89, 109, 110, 58, 59}; // Pokemon Mansion - Grimer, Muk, Koffing, Weezing, Growlithe, Arcanine

// 🏁 Caminho Final
static int route22_pokemon[] = {19, 21, 56, 29, 32}; // Route 22 - Rattata, Spearow, Mankey, Nidoran♀, Nidoran♂
static int route23_pokemon[] = {22, 21, 23, 24, 27, 28, 149}; // Route 23 (Victory Road externo) - Fearow, Spearow, Ekans, Arbok, Sandshrew, Sandslash, Dragonite
static int victory_road_pokemon[] = {144, 145, 146}; // Victory Road (aves lendárias) - Articuno, Zapdos, Moltres
static int indigo_plateau_pokemon[] = {150, 151}; // Indigo Plateau - Mewtwo, Mew

route_t getRoute(int routeId) {
  route_t route;
  route.id = routeId;
  
  switch(routeId) {
    // 🔰 Região Inicial
    case 1: // Route 1
      strcpy(route.name, "ROUTE 1");
      route.pokemonCount = 2;
      for(int i = 0; i < 2; i++) {
        route.pokemonIds[i] = route1_pokemon[i];
      }
      break;
      
    case 2: // Route 2
      strcpy(route.name, "ROUTE 2");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = route2_pokemon[i];
      }
      break;
      
    case 3: // Viridian Forest
      strcpy(route.name, "VIRIDIAN F");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = viridian_forest_pokemon[i];
      }
      break;
      
    // 🪨 Área de Pewter / Mt. Moon
    case 4: // Route 3
      strcpy(route.name, "ROUTE 3");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route3_pokemon[i];
      }
      break;
      
    case 5: // Mt. Moon
      strcpy(route.name, "MT. MOON");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = mt_moon_pokemon[i];
      }
      break;
      
    case 6: // Route 4
      strcpy(route.name, "ROUTE 4");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route4_pokemon[i];
      }
      break;
      
    // 💧 Área de Cerulean
    case 7: // Route 24 (Nugget Bridge)
      strcpy(route.name, "ROUTE 24");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route24_pokemon[i];
      }
      break;
      
    case 8: // Route 25 (Sea Cottage)
      strcpy(route.name, "ROUTE 25");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route25_pokemon[i];
      }
      break;
      
    case 9: // Route 5
      strcpy(route.name, "ROUTE 5");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route5_pokemon[i];
      }
      break;
      
    case 10: // Route 6
      strcpy(route.name, "ROUTE 6");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route6_pokemon[i];
      }
      break;
      
    // ⚡ Vermilion
    case 11: // Route 11
      strcpy(route.name, "ROUTE 11");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = route11_pokemon[i];
      }
      break;
      
    case 12: // Diglett's Cave
      strcpy(route.name, "DIGLETT CAVE");
      route.pokemonCount = 2;
      for(int i = 0; i < 2; i++) {
        route.pokemonIds[i] = digletts_cave_pokemon[i];
      }
      break;
      
    // 🌿 Área Central
    case 13: // Route 7
      strcpy(route.name, "ROUTE 7");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route7_pokemon[i];
      }
      break;
      
    case 14: // Route 8
      strcpy(route.name, "ROUTE 8");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route8_pokemon[i];
      }
      break;
      
    case 15: // Route 9
      strcpy(route.name, "ROUTE 9");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = route9_pokemon[i];
      }
      break;
      
    case 16: // Route 10
      strcpy(route.name, "ROUTE 10");
      route.pokemonCount = 2;
      for(int i = 0; i < 2; i++) {
        route.pokemonIds[i] = route10_pokemon[i];
      }
      break;
      
    case 17: // Rock Tunnel
      strcpy(route.name, "ROCK TUNNEL");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = rock_tunnel_pokemon[i];
      }
      break;
      
    // 🌸 Lavender / Torre Pokémon
    case 18: // Pokemon Tower
      strcpy(route.name, "PKMN TOWER");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = pokemon_tower_pokemon[i];
      }
      break;
      
    // 🏙️ Saffron City
    case 19: // Silph Co.
      strcpy(route.name, "SILPH CO.");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = silph_co_pokemon[i];
      }
      break;
      
    case 20: // Fighting Dojo
      strcpy(route.name, "FIGHT DOJO");
      route.pokemonCount = 7;
      for(int i = 0; i < 7; i++) {
        route.pokemonIds[i] = fighting_dojo_pokemon[i];
      }
      break;
      
    // 🌺 Celadon City
    case 21: // Celadon Game Corner
      strcpy(route.name, "GAME CORNER");
      route.pokemonCount = 4;
      for(int i = 0; i < 4; i++) {
        route.pokemonIds[i] = celadon_game_corner_pokemon[i];
      }
      break;
      
    case 22: // Rocket Hideout
      strcpy(route.name, "ROCKET BASE");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = rocket_hideout_pokemon[i];
      }
      break;
      
    // 🌊 Fuchsia Area
    case 23: // Route 12
      strcpy(route.name, "ROUTE 12");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route12_pokemon[i];
      }
      break;
      
    case 24: // Route 13
      strcpy(route.name, "ROUTE 13");
      route.pokemonCount = 8;
      for(int i = 0; i < 8; i++) {
        route.pokemonIds[i] = route13_pokemon[i];
      }
      break;
      
    case 25: // Route 14
      strcpy(route.name, "ROUTE 14");
      route.pokemonCount = 8;
      for(int i = 0; i < 8; i++) {
        route.pokemonIds[i] = route14_pokemon[i];
      }
      break;
      
    case 26: // Route 15
      strcpy(route.name, "ROUTE 15");
      route.pokemonCount = 8;
      for(int i = 0; i < 8; i++) {
        route.pokemonIds[i] = route15_pokemon[i];
      }
      break;
      
    case 27: // Safari Zone
      strcpy(route.name, "SAFARI ZONE");
      route.pokemonCount = 18;
      for(int i = 0; i < 18; i++) {
        route.pokemonIds[i] = safari_zone_pokemon[i];
      }
      break;
      
    // 🌋 Ilhas / Água
    case 28: // Route 16
      strcpy(route.name, "ROUTE 16");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route16_pokemon[i];
      }
      break;
      
    case 29: // Route 17 (Cycling Road)
      strcpy(route.name, "ROUTE 17");
      route.pokemonCount = 8;
      for(int i = 0; i < 8; i++) {
        route.pokemonIds[i] = route17_pokemon[i];
      }
      break;
      
    case 30: // Route 18
      strcpy(route.name, "ROUTE 18");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route18_pokemon[i];
      }
      break;
      
    // 🏝️ Seafoam / Cinnabar
    case 31: // Route 19
      strcpy(route.name, "ROUTE 19");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route19_pokemon[i];
      }
      break;
      
    case 32: // Route 20
      strcpy(route.name, "ROUTE 20");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = route20_pokemon[i];
      }
      break;
      
    case 33: // Seafoam Islands
      strcpy(route.name, "SEAFOAM IS");
      route.pokemonCount = 8;
      for(int i = 0; i < 8; i++) {
        route.pokemonIds[i] = seafoam_islands_pokemon[i];
      }
      break;
      
    case 34: // Route 21
      strcpy(route.name, "ROUTE 21");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route21_pokemon[i];
      }
      break;
      
    // 🔥 Cinnabar Island
    case 35: // Pokemon Mansion
      strcpy(route.name, "PKMN MANSION");
      route.pokemonCount = 6;
      for(int i = 0; i < 6; i++) {
        route.pokemonIds[i] = pokemon_mansion_pokemon[i];
      }
      break;
      
    // 🏁 Caminho Final
    case 36: // Route 22
      strcpy(route.name, "ROUTE 22");
      route.pokemonCount = 5;
      for(int i = 0; i < 5; i++) {
        route.pokemonIds[i] = route22_pokemon[i];
      }
      break;
      
    case 37: // Route 23 (Victory Road externo)
      strcpy(route.name, "ROUTE 23");
      route.pokemonCount = 7;
      for(int i = 0; i < 7; i++) {
        route.pokemonIds[i] = route23_pokemon[i];
      }
      break;
      
    case 38: // Victory Road (aves lendárias)
      strcpy(route.name, "VICTORY RD");
      route.pokemonCount = 3;
      for(int i = 0; i < 3; i++) {
        route.pokemonIds[i] = victory_road_pokemon[i];
      }
      break;
      
    case 39: // Indigo Plateau
      strcpy(route.name, "INDIGO PLT");
      route.pokemonCount = 2;
      for(int i = 0; i < 2; i++) {
        route.pokemonIds[i] = indigo_plateau_pokemon[i];
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
      result = viridian_forest_pokemon;
      break;
    case 4:
      result = route3_pokemon;
      break;
    case 5:
      result = mt_moon_pokemon;
      break;
    case 6:
      result = route4_pokemon;
      break;
    case 7:
      result = route24_pokemon;
      break;
    case 8:
      result = route25_pokemon;
      break;
    case 9:
      result = route5_pokemon;
      break;
    case 10:
      result = route6_pokemon;
      break;
    case 11:
      result = route11_pokemon;
      break;
    case 12:
      result = digletts_cave_pokemon;
      break;
    case 13:
      result = route7_pokemon;
      break;
    case 14:
      result = route8_pokemon;
      break;
    case 15:
      result = route9_pokemon;
      break;
    case 16:
      result = route10_pokemon;
      break;
    case 17:
      result = rock_tunnel_pokemon;
      break;
    case 18:
      result = pokemon_tower_pokemon;
      break;
    case 19:
      result = silph_co_pokemon;
      break;
    case 20:
      result = fighting_dojo_pokemon;
      break;
    case 21:
      result = celadon_game_corner_pokemon;
      break;
    case 22:
      result = rocket_hideout_pokemon;
      break;
    case 23:
      result = route12_pokemon;
      break;
    case 24:
      result = route13_pokemon;
      break;
    case 25:
      result = route14_pokemon;
      break;
    case 26:
      result = route15_pokemon;
      break;
    case 27:
      result = safari_zone_pokemon;
      break;
    case 28:
      result = route16_pokemon;
      break;
    case 29:
      result = route17_pokemon;
      break;
    case 30:
      result = route18_pokemon;
      break;
    case 31:
      result = route19_pokemon;
      break;
    case 32:
      result = route20_pokemon;
      break;
    case 33:
      result = seafoam_islands_pokemon;
      break;
    case 34:
      result = route21_pokemon;
      break;
    case 35:
      result = pokemon_mansion_pokemon;
      break;
    case 36:
      result = route22_pokemon;
      break;
    case 37:
      result = route23_pokemon;
      break;
    case 38:
      result = victory_road_pokemon;
      break;
    case 39:
      result = indigo_plateau_pokemon;
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
  return 39; // Total de rotas disponíveis
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