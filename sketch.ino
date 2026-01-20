#include <TimerOne.h>
#include <stdio.h>
#include <string.h>
#include "kernel.h"
#include "ctrDrv.h"
#include "state_machine.h"
#include "display.h"
#include "pokemon_db.h"
#include "pokedex.h"
#include "game_types.h"
#include "pokemon_types.h"
#include <Arduino.h>

// Game state variables
static int selectedIndex = 0; // 0-2 for starters
static int currentRoute = 1;           // Current route (starts at route 1)
static int stepsTaken = 0;             // Steps taken in exploration
static int stepsUntilEncounter = 0;    // Steps remaining until encounter
static int encounteredPokemonId = 0;   // ID of encountered pokemon
static char pokedex[POKEDEX_SIZE];     // Bitfield for captured pokemon
static int totalCaptured = 0;          // Total captured
static char displayNeedsUpdate = 1;
static char lastButtonA = 0;
static char lastButtonSelect = 0;
static char lastButtonB = 0;
static char lastButtonUp = 0;
static char lastButtonDown = 0;
static int captureDelay = 0;           // Delay for capture messages
static int routeCompleteDelay = 0;     // Delay for route complete message
static int ledBlinkCounter = 0;        // Counter for LED blinking
static char ledState = 0;               // Current LED state (0=off, 1=on)
static char exploringStateInitialized = 0; // Flag to reset button states when entering exploring
static int lastExploringState = -1;    // Track state changes for exploring
static char pokemonFoundStateInitialized = 0; // Flag to reset button states when entering pokemon found
static int lastPokemonFoundState = -1; // Track state changes for pokemon found
static char selectPokemonStateInitialized = 0; // Flag to reset button states when entering select pokemon
static int lastSelectPokemonState = -1; // Track state changes for select pokemon
static int lastSelectedIndex = -1; // Track selected index changes for LCD updates
static int pokedexViewingPokemonId = 0; // Currently viewing pokemon ID in pokedex (0 = summary view)
static char pokedexStateInitialized = 0; // Flag for pokedex state initialization

void setup() {
  process p1 = {gameLoop, 1, 0}; // periodo 1 tick (10ms)
  
  initCtrDrv();
  initDriver(DRV_LED);
  initDriver(DRV_BUTTON);
  initDriver(DRV_LCD);

  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  initStateMachine();
  initPokedex(pokedex);

  kernelInit();

  kernelAddProc(&p1);

  Timer1.initialize(10000); // 10ms tick (100 ticks = 1 segundo)
  Timer1.attachInterrupt(tick);

  kernelLoop();
}

void tick(){
  kernelTick();
}

char gameLoop(void){
  int currentState = getCurrentState();
  int buttonA = 0;
  int buttonSelect = 0;
  int buttonB = 0;
  int buttonUp = 0;
  int buttonDown = 0;
  
  // Read button states (1 = pressed, 0 = not pressed)
  callDriver(DRV_BUTTON, BUTTON_A, &buttonA);
  callDriver(DRV_BUTTON, BUTTON_SELECT, &buttonSelect);
  callDriver(DRV_BUTTON, BUTTON_B, &buttonB);
  callDriver(DRV_BUTTON, BUTTON_UP, &buttonUp);
  callDriver(DRV_BUTTON, BUTTON_DOWN, &buttonDown);
  
  // Temporary workaround: Handle STATE_EXPLORING outside switch due to compiler issue
  if (currentState == STATE_EXPLORING || currentState == 2) {
    // Handle STATE_EXPLORING (removed spam log)
    
    // Reset button states when first entering exploring state
    int currentExploringState = getCurrentState();
    if (lastExploringState != currentExploringState) {
      exploringStateInitialized = 0;
      lastExploringState = currentExploringState;
      routeCompleteDelay = 0;
      displayNeedsUpdate = 1;
    }
    
    if (!exploringStateInitialized) {
      lastButtonA = buttonA;
      lastButtonSelect = buttonSelect;
      lastButtonB = buttonB;
      exploringStateInitialized = 1;
    }
    
    // Handle route complete delay
    if (routeCompleteDelay > 0) {
      routeCompleteDelay--;
      if (routeCompleteDelay == 0) {
        displayNeedsUpdate = 1;
      }
    }
    
    // Display route info
    if (displayNeedsUpdate && routeCompleteDelay == 0) {
      route_t route = getRoute(currentRoute);
      char line1[17];
      char line2[17];
      snprintf(line1, 17, "%-16s", route.name);
      snprintf(line2, 17, "Steps: %2d", stepsTaken);
      displayMessage(line1, line2);
      displayNeedsUpdate = 0;
    }
    
    // Handle button A to walk
    if (buttonA == 1 && lastButtonA == 0) {
      stepsTaken++;
      displayNeedsUpdate = 1;
      
      if (stepsTaken >= stepsUntilEncounter) {
        encounteredPokemonId = getRandomPokemonFromRoute(currentRoute, pokedex);
        
        if (encounteredPokemonId == 0) {
          if (isRouteComplete(currentRoute, pokedex)) {
            changeState(STATE_ROUTE_COMPLETE);
            displayNeedsUpdate = 1;
          } else {
            stepsTaken = 0;
            stepsUntilEncounter = random(3, 11);
          }
        } else {
          changeState(STATE_POKEMON_FOUND);
          displayNeedsUpdate = 1;
        }
      }
    }
    lastButtonA = buttonA;
    
    // Handle SELECT button to open Pokedex
    if (buttonSelect == 1 && lastButtonSelect == 0) {
      pokedexStateInitialized = 0;
      changeState(STATE_POKEDEX);
      displayNeedsUpdate = 1;
    }
    lastButtonSelect = buttonSelect;
  } else if (currentState == STATE_POKEMON_FOUND || currentState == 3) {
    // Handle STATE_POKEMON_FOUND outside switch (same issue as EXPLORING)
    
    // Reset button states when first entering this state
    int currentPokemonFoundState = getCurrentState();
    if (lastPokemonFoundState != currentPokemonFoundState) {
      pokemonFoundStateInitialized = 0;
      lastPokemonFoundState = currentPokemonFoundState;
    }
    
    if (!pokemonFoundStateInitialized) {
      lastButtonSelect = buttonSelect;
      lastButtonB = buttonB;
      pokemonFoundStateInitialized = 1;
    }
    
    if (displayNeedsUpdate) {
      pokemon_t pokemon = getPokemonById(encounteredPokemonId);
      char line1[17];
      char line2[17];
      snprintf(line1, 17, "A wild %s!", pokemon.name);
      strcpy(line2, "SEL=Capt B=Flee");
      displayMessage(line1, line2);
      displayNeedsUpdate = 0;
    }
    
    // Handle SELECT to capture
    if (buttonSelect == 1 && lastButtonSelect == 0) {
      lastButtonSelect = buttonSelect;
      changeState(STATE_CAPTURING);
      displayNeedsUpdate = 1;
    } else {
      lastButtonSelect = buttonSelect;
    }
    
    // Handle B to flee
    if (buttonB == 1 && lastButtonB == 0) {
      lastButtonB = buttonB;
      // Reset steps and continue exploring
      stepsTaken = 0;
      stepsUntilEncounter = random(3, 11);
      exploringStateInitialized = 0; // Reset exploring state
      changeState(STATE_EXPLORING);
      displayNeedsUpdate = 1;
    } else {
      lastButtonB = buttonB;
    }
  } else if (currentState == STATE_CAPTURING || currentState == 4) {
    // Handle STATE_CAPTURING outside switch (same issue)
    if (displayNeedsUpdate) {
      displayMessage("Throwing ball...", "");
      displayNeedsUpdate = 0;
      captureDelay = 100; // 1 second delay
    }
    
    if (captureDelay > 0) {
      captureDelay--;
      if (captureDelay == 0) {
        // Calculate capture chance (50% base)
        int captureChance = random(0, 100);
        
        if (captureChance < 50) {
          // Capture successful
          markPokemonCaptured(encounteredPokemonId, pokedex);
          totalCaptured = countCapturedPokemon(pokedex);
          changeState(STATE_CAPTURE_SUCCESS);
          displayNeedsUpdate = 1;
        } else {
          // Capture failed, pokemon flees
          changeState(STATE_CAPTURE_FAILED);
          displayNeedsUpdate = 1;
        }
      }
    }
  } else if (currentState == STATE_CAPTURE_SUCCESS || currentState == 5) {
    // Handle STATE_CAPTURE_SUCCESS outside switch
    if (displayNeedsUpdate) {
      pokemon_t pokemon = getPokemonById(encounteredPokemonId);
      char line1[17];
      char line2[17];
      snprintf(line1, 17, "Gotcha! %s!", pokemon.name);
      snprintf(line2, 17, "Pokedex: %d/151", totalCaptured);
      displayMessage(line1, line2);
      displayNeedsUpdate = 0;
      captureDelay = 200; // 2 second delay
      ledBlinkCounter = 0;
      ledState = 0;
      
      // Check if all 151 captured
      if (totalCaptured >= 151) {
        captureDelay = 300; // Longer delay before victory
      }
    }
    
    // Blink green LED (every 5 ticks = 50ms)
    ledBlinkCounter++;
    if (ledBlinkCounter >= 5) {
      ledBlinkCounter = 0;
      ledState = !ledState;
      if (ledState) {
        callDriver(DRV_LED, LED_VERDE, 0);
      } else {
        // Turn off LED (both LEDs off)
        digitalWrite(20, LOW);
        digitalWrite(21, LOW);
      }
    }
    
    if (captureDelay > 0) {
      captureDelay--;
      if (captureDelay == 0) {
        // Turn off LED when delay ends
        digitalWrite(20, LOW);
        digitalWrite(21, LOW);
        // Check if all pokemon captured
        if (totalCaptured >= 151) {
          changeState(STATE_VICTORY);
          displayNeedsUpdate = 1;
        } else {
          // Check if route is complete
          if (isRouteComplete(currentRoute, pokedex)) {
            changeState(STATE_ROUTE_COMPLETE);
            displayNeedsUpdate = 1;
          } else {
            // Continue exploring
            stepsTaken = 0;
            stepsUntilEncounter = random(3, 11);
            exploringStateInitialized = 0;
            changeState(STATE_EXPLORING);
            displayNeedsUpdate = 1;
          }
        }
      }
    }
  } else if (currentState == STATE_CAPTURE_FAILED || currentState == 6) {
    // Handle STATE_CAPTURE_FAILED outside switch
    if (displayNeedsUpdate) {
      displayMessage("It broke free!", "It fled!");
      displayNeedsUpdate = 0;
      captureDelay = 200; // 2 second delay
      ledBlinkCounter = 0;
      ledState = 0;
    }
    
    // Blink red LED (every 5 ticks = 50ms)
    ledBlinkCounter++;
    if (ledBlinkCounter >= 5) {
      ledBlinkCounter = 0;
      ledState = !ledState;
      if (ledState) {
        callDriver(DRV_LED, LED_VERMELHO, 0);
      } else {
        // Turn off LED (both LEDs off)
        digitalWrite(20, LOW);
        digitalWrite(21, LOW);
      }
    }
    
    if (captureDelay > 0) {
      captureDelay--;
      if (captureDelay == 0) {
        // Turn off LED when delay ends
        digitalWrite(20, LOW);
        digitalWrite(21, LOW);
        // Reset steps and continue exploring
        stepsTaken = 0;
        stepsUntilEncounter = random(3, 11);
        exploringStateInitialized = 0; // Reset exploring state
        changeState(STATE_EXPLORING);
        displayNeedsUpdate = 1;
      }
    }
  } else if (currentState == STATE_ROUTE_COMPLETE || currentState == 7) {
    // Handle STATE_ROUTE_COMPLETE outside switch
    if (displayNeedsUpdate) {
      route_t route = getRoute(currentRoute);
      char line1[17];
      char line2[17];
      snprintf(line1, 17, "%s complete!", route.name);
      strcpy(line2, "Moving to next...");
      displayMessage(line1, line2);
      displayNeedsUpdate = 0;
      routeCompleteDelay = 200; // 2 second delay
    }
    
    if (routeCompleteDelay > 0) {
      routeCompleteDelay--;
      if (routeCompleteDelay == 0) {
        // Move to next route
        currentRoute++;
        
        // Check if we've completed all routes
        if (currentRoute > getTotalRoutes()) {
          // Check if we have all 151 pokemon
          if (totalCaptured >= 151) {
            changeState(STATE_VICTORY);
          } else {
            // Go back to first route
            currentRoute = 1;
          }
        }
        
        // Reset exploration
        stepsTaken = 0;
        stepsUntilEncounter = random(3, 11);
        exploringStateInitialized = 0; // Reset exploring state
        changeState(STATE_EXPLORING);
        displayNeedsUpdate = 1;
      }
    }
  } else if (currentState == STATE_POKEDEX || currentState == 8) {
    // Handle STATE_POKEDEX outside switch
    static int lastPokedexState = -1;
    if (lastPokedexState != currentState) {
      pokedexStateInitialized = 0;
      lastPokedexState = currentState;
    }
    
    if (!pokedexStateInitialized) {
      lastButtonA = buttonA;
      lastButtonSelect = buttonSelect;
      lastButtonB = buttonB;
      lastButtonUp = buttonUp;
      lastButtonDown = buttonDown;
      pokedexViewingPokemonId = 0; // Start with summary view
      pokedexStateInitialized = 1;
      displayNeedsUpdate = 1;
    }
    
    // Handle display updates
    if (displayNeedsUpdate) {
      if (pokedexViewingPokemonId == 0) {
        // Summary view
        char line1[17];
        char line2[17];
        strcpy(line1, "Pokedex");
        snprintf(line2, 17, "%d/151 captured", totalCaptured);
        displayMessage(line1, line2);
      } else {
        // Individual pokemon view
        pokemon_t pokemon = getPokemonById(pokedexViewingPokemonId);
        char line1[17];
        char line2[17];
        snprintf(line1, 17, "#%03d %s", pokedexViewingPokemonId, pokemon.name);
        snprintf(line2, 17, "HP:%d/%d", pokemon.currentHP, pokemon.maxHP);
        displayMessage(line1, line2);
      }
      displayNeedsUpdate = 0;
    }
    
    // Handle A or SELECT to enter pokemon view or switch pokemon
    if ((buttonA == 1 && lastButtonA == 0) || (buttonSelect == 1 && lastButtonSelect == 0)) {
      if (pokedexViewingPokemonId == 0) {
        // Enter pokemon view - go to first captured pokemon
        if (totalCaptured > 0) {
          pokedexViewingPokemonId = getFirstCapturedPokemon(pokedex);
          displayNeedsUpdate = 1;
        }
      }
    }
    lastButtonA = buttonA;
    lastButtonSelect = buttonSelect;
    
    // Handle UP button - previous pokemon (or go to summary if at first)
    if (buttonUp == 1 && lastButtonUp == 0) {
      if (pokedexViewingPokemonId > 0) {
        int prevId = getPreviousCapturedPokemon(pokedexViewingPokemonId, pokedex);
        if (prevId > 0 && prevId != pokedexViewingPokemonId) {
          pokedexViewingPokemonId = prevId;
          displayNeedsUpdate = 1;
        } else {
          // Wrap to summary
          pokedexViewingPokemonId = 0;
          displayNeedsUpdate = 1;
        }
      }
    }
    lastButtonUp = buttonUp;
    
    // Handle DOWN button - next pokemon
    if (buttonDown == 1 && lastButtonDown == 0) {
      if (pokedexViewingPokemonId == 0) {
        // From summary, go to first pokemon
        if (totalCaptured > 0) {
          pokedexViewingPokemonId = getFirstCapturedPokemon(pokedex);
          displayNeedsUpdate = 1;
        }
      } else {
        int nextId = getNextCapturedPokemon(pokedexViewingPokemonId, pokedex);
        if (nextId > 0 && nextId != pokedexViewingPokemonId) {
          pokedexViewingPokemonId = nextId;
          displayNeedsUpdate = 1;
        } else {
          // Wrap to summary
          pokedexViewingPokemonId = 0;
          displayNeedsUpdate = 1;
        }
      }
    }
    lastButtonDown = buttonDown;
    
    // Handle B to go back (to summary or exit)
    if (buttonB == 1 && lastButtonB == 0) {
      if (pokedexViewingPokemonId > 0) {
        // Go back to summary
        pokedexViewingPokemonId = 0;
        displayNeedsUpdate = 1;
      } else {
        // Exit pokedex
        exploringStateInitialized = 0; // Reset exploring state
        changeState(STATE_EXPLORING);
        displayNeedsUpdate = 1;
      }
    }
    lastButtonB = buttonB;
  } else if (currentState == STATE_VICTORY || currentState == 9) {
    // Handle STATE_VICTORY outside switch
    if (displayNeedsUpdate) {
      displayMessage("CONGRATULATIONS!", "You caught all 151!");
      callDriver(DRV_LED, LED_VERDE, 0);
      displayNeedsUpdate = 0;
      lastButtonA = 0;
    }
    
    // Handle A to restart
    if (buttonA == 1 && lastButtonA == 0) {
      callDriver(DRV_LED, LED_VERMELHO, 0);
      changeState(STATE_START);
      displayNeedsUpdate = 1;
    }
    lastButtonA = buttonA;
  } else {
    // Normal switch for other states (STATE_START and STATE_SELECT_POKEMON only)
    switch(currentState) {
    case STATE_START:
      // Initialize game
      selectedIndex = 0;
      currentRoute = 1;
      stepsTaken = 0;
      stepsUntilEncounter = 0;
      totalCaptured = 0;
      captureDelay = 0;
      routeCompleteDelay = 0;
      displayNeedsUpdate = 1;
      // Reset pokedex
      initPokedex(pokedex);
      // Reset button states
      lastButtonA = 0;
      lastButtonSelect = 0;
      lastButtonB = 0;
      lastButtonUp = 0;
      lastButtonDown = 0;
      // Reset state initialization flags
      exploringStateInitialized = 0;
      lastExploringState = -1;
      pokemonFoundStateInitialized = 0;
      lastPokemonFoundState = -1;
      selectPokemonStateInitialized = 0;
      lastSelectPokemonState = -1;
      lastSelectedIndex = -1;
      changeState(STATE_SELECT_POKEMON);
      break;
      
    case STATE_SELECT_POKEMON:
      // Reset button states when first entering this state
      int currentSelectPokemonState = getCurrentState();
      if (lastSelectPokemonState != currentSelectPokemonState) {
        selectPokemonStateInitialized = 0;
        lastSelectPokemonState = currentSelectPokemonState;
        lastSelectedIndex = -1; // Force LCD update on state entry
      }
      
      if (!selectPokemonStateInitialized) {
        lastButtonA = buttonA;
        lastButtonSelect = buttonSelect;
        lastButtonB = buttonB;
        lastButtonUp = buttonUp;
        lastButtonDown = buttonDown;
        selectPokemonStateInitialized = 1;
      }
      
      // Handle Pokémon selection display - only update when needed
      if (displayNeedsUpdate) {
        // Full display update (first time entering state)
        displayMessage("Choose Pokemon:", "");
        displayNeedsUpdate = 0;
        // Force update of selection line
        lastSelectedIndex = -1;
      }
      
      // Update selection display on line 2 when selectedIndex changes
      if (lastSelectedIndex != selectedIndex) {
        char selectionLine[17];
        switch(selectedIndex) {
          case 0:
            strcpy(selectionLine, "1.BULBASAUR");
            break;
          case 1:
            strcpy(selectionLine, "2.CHARMANDER");
            break;
          case 2:
            strcpy(selectionLine, "3.SQUIRTLE");
            break;
        }
        
        char cursor2[2] = {0, 1};
        callDriver(DRV_LCD, LCD_SET_CURSOR, (void*)cursor2);
        callDriver(DRV_LCD, LCD_PRINT, (void*)selectionLine);
        lastSelectedIndex = selectedIndex;
      }
      
      // Handle UP button (cycle down) - detect press edge
      if (buttonUp == 1 && lastButtonUp == 0) {
        selectedIndex = (selectedIndex + 2) % 3; // Move up (decrement)
      }
      lastButtonUp = buttonUp;
      
      // Handle DOWN button (cycle up) - detect press edge
      if (buttonDown == 1 && lastButtonDown == 0) {
        selectedIndex = (selectedIndex + 1) % 3; // Move down (increment)
      }
      lastButtonDown = buttonDown;
      
      // Handle A or SELECT button (confirm selection) - detect press edge
      if ((buttonA == 1 && lastButtonA == 0) || (buttonSelect == 1 && lastButtonSelect == 0)) {
        // Starter pokemon selected (not used in capture system, but selection kept for game flow)
        (void)getStarter(selectedIndex);
        
        // Initialize exploration
        currentRoute = 1;
        stepsTaken = 0;
        stepsUntilEncounter = random(3, 11); // Random 3-10 steps
        
        // Reset button states for new state
        lastButtonA = buttonA;
        lastButtonSelect = buttonSelect;
        lastButtonB = 0;
        lastButtonUp = 0;
        lastButtonDown = 0;
        
        // Reset state flags
        exploringStateInitialized = 0;
        lastExploringState = -1;
        
        changeState(STATE_EXPLORING);
        displayNeedsUpdate = 1;
      } else {
        lastButtonA = buttonA;
        lastButtonSelect = buttonSelect;
      }
      break;
      
    // STATE_EXPLORING handled outside switch above
      
    case STATE_POKEMON_FOUND:
      // Reset button states when first entering this state
      int currentPokemonFoundState = getCurrentState();
      if (lastPokemonFoundState != currentPokemonFoundState) {
        pokemonFoundStateInitialized = 0;
        lastPokemonFoundState = currentPokemonFoundState;
      }
      
      if (!pokemonFoundStateInitialized) {
        lastButtonSelect = buttonSelect;
        lastButtonB = buttonB;
        pokemonFoundStateInitialized = 1;
      }
      
      if (displayNeedsUpdate) {
        pokemon_t pokemon = getPokemonById(encounteredPokemonId);
        char line1[17];
        char line2[17];
        snprintf(line1, 17, "A wild %s!", pokemon.name);
        strcpy(line2, "SEL=Capt B=Flee");
        displayMessage(line1, line2);
        displayNeedsUpdate = 0;
      }
      
      // Handle SELECT to capture
      if (buttonSelect == 1 && lastButtonSelect == 0) {
        lastButtonSelect = buttonSelect;
        changeState(STATE_CAPTURING);
        displayNeedsUpdate = 1;
      } else {
        lastButtonSelect = buttonSelect;
      }
      
      // Handle B to flee
      if (buttonB == 1 && lastButtonB == 0) {
        lastButtonB = buttonB;
        // Reset steps and continue exploring
        stepsTaken = 0;
        stepsUntilEncounter = random(3, 11);
        exploringStateInitialized = 0; // Reset exploring state
        changeState(STATE_EXPLORING);
        displayNeedsUpdate = 1;
      } else {
        lastButtonB = buttonB;
      }
      break;
      
    case STATE_CAPTURING:
      if (displayNeedsUpdate) {
        displayMessage("Throwing ball...", "");
        displayNeedsUpdate = 0;
        captureDelay = 100; // 1 second delay
      }
      
      if (captureDelay > 0) {
        captureDelay--;
        if (captureDelay == 0) {
          // Calculate capture chance (50% base)
          int captureChance = random(0, 100);
          
          if (captureChance < 50) {
            // Capture successful
            markPokemonCaptured(encounteredPokemonId, pokedex);
            totalCaptured = countCapturedPokemon(pokedex);
            changeState(STATE_CAPTURE_SUCCESS);
            displayNeedsUpdate = 1;
          } else {
            // Capture failed, pokemon flees
            changeState(STATE_CAPTURE_FAILED);
            displayNeedsUpdate = 1;
          }
        }
      }
      break;
      
    case STATE_CAPTURE_SUCCESS:
      if (displayNeedsUpdate) {
        pokemon_t pokemon = getPokemonById(encounteredPokemonId);
        char line1[17];
        char line2[17];
        snprintf(line1, 17, "Gotcha! %s!", pokemon.name);
        snprintf(line2, 17, "Pokedex: %d/151", totalCaptured);
        displayMessage(line1, line2);
        displayNeedsUpdate = 0;
        captureDelay = 200; // 2 second delay
        
        // Check if all 151 captured
        if (totalCaptured >= 151) {
          captureDelay = 300; // Longer delay before victory
        }
      }
      
      if (captureDelay > 0) {
        captureDelay--;
        if (captureDelay == 0) {
          // Check if all pokemon captured
          if (totalCaptured >= 151) {
            changeState(STATE_VICTORY);
            displayNeedsUpdate = 1;
          } else {
            // Check if route is complete
            if (isRouteComplete(currentRoute, pokedex)) {
              changeState(STATE_ROUTE_COMPLETE);
              displayNeedsUpdate = 1;
            } else {
              // Continue exploring
              stepsTaken = 0;
              stepsUntilEncounter = random(3, 11);
              exploringStateInitialized = 0; // Reset exploring state
              changeState(STATE_EXPLORING);
              displayNeedsUpdate = 1;
            }
          }
        }
      }
      break;
      
    case STATE_CAPTURE_FAILED:
      if (displayNeedsUpdate) {
        displayMessage("It broke free!", "It fled!");
        displayNeedsUpdate = 0;
        captureDelay = 200; // 2 second delay
      }
      
      if (captureDelay > 0) {
        captureDelay--;
        if (captureDelay == 0) {
          // Reset steps and continue exploring
          stepsTaken = 0;
          stepsUntilEncounter = random(3, 11);
          exploringStateInitialized = 0; // Reset exploring state
          changeState(STATE_EXPLORING);
          displayNeedsUpdate = 1;
        }
      }
      break;
      
    case STATE_ROUTE_COMPLETE:
      if (displayNeedsUpdate) {
        route_t route = getRoute(currentRoute);
        char line1[17];
        char line2[17];
        snprintf(line1, 17, "%s complete!", route.name);
        strcpy(line2, "Moving to next...");
        displayMessage(line1, line2);
        displayNeedsUpdate = 0;
        routeCompleteDelay = 200; // 2 second delay
      }
      
      if (routeCompleteDelay > 0) {
        routeCompleteDelay--;
        if (routeCompleteDelay == 0) {
          // Move to next route
          currentRoute++;
          
          // Check if we've completed all routes
          if (currentRoute > getTotalRoutes()) {
            // Check if we have all 151 pokemon
            if (totalCaptured >= 151) {
              changeState(STATE_VICTORY);
            } else {
              // Go back to first route
              currentRoute = 1;
            }
          }
          
          // Reset exploration
          stepsTaken = 0;
          stepsUntilEncounter = random(3, 11);
          exploringStateInitialized = 0; // Reset exploring state
          changeState(STATE_EXPLORING);
          displayNeedsUpdate = 1;
        }
      }
      break;
      
    // STATE_POKEDEX and STATE_VICTORY handled outside switch above
      
    default:
      break;
    }
  } // Close else block
  
  return REPEAT;
}

void loop() {
  // Empty - kernelLoop() handles everything
}