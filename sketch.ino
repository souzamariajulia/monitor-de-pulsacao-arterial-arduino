#include <TimerOne.h>
#include <stdio.h>
#include <string.h>
#include "src/kernel/kernel.h"
#include "src/controller/ctrDrv.h"
#include "src/kernel/state_machine.h"
#include "src/kernel/display.h"
#include "src/game/pokemon_db.h"
#include "src/game/battle_logic.h"
#include "include/game_types.h"
#include "include/pokemon_types.h"
#include <Arduino.h>

// Game state variables
static int selectedIndex = 0; // 0-2 for starters
static pokemon_t playerPokemon;
static pokemon_t enemyPokemon;
static battle_t battle;
static char displayNeedsUpdate = 1;
static char lastButtonA = 0;
static char lastButtonUp = 0;
static char lastButtonDown = 0;
static char enemyTurnDelay = 0;

void setup() {
  process p1 = {gameLoop, 1, 0};
  
  initCtrDrv();
  initDriver(DRV_LED);
  initDriver(DRV_BUTTON);
  initDriver(DRV_LCD);

  Serial.begin(9600);
  
  randomSeed(analogRead(0));
  
  initStateMachine();

  kernelInit();

  if(kernelAddProc(&p1) == SUCCESS){
    Serial.println("Game process added\n");
  }

  Timer1.initialize(1000000); // 1 second tick
  Timer1.attachInterrupt(tick);

  kernelLoop();
}

void tick(){
  kernelTick();
}

char gameLoop(void){
  int currentState = getCurrentState();
  int buttonA = 0;
  int buttonUp = 0;
  int buttonDown = 0;
  
  // Read button states
  callDriver(DRV_BUTTON, BUTTON_A, &buttonA);
  callDriver(DRV_BUTTON, BUTTON_UP, &buttonUp);
  callDriver(DRV_BUTTON, BUTTON_DOWN, &buttonDown);
  
  switch(currentState) {
    case STATE_START:
      // Initialize game
      selectedIndex = 0;
      displayNeedsUpdate = 1;
      changeState(STATE_SELECT_POKEMON);
      break;
      
    case STATE_SELECT_POKEMON:
      // Handle Pokémon selection
      if (displayNeedsUpdate) {
        displayMessage("Choose Pokemon:", "");
        displayNeedsUpdate = 0;
      }
      
      // Update selection display on line 2
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
      
      // Handle UP button (cycle down)
      if (buttonUp == 1 && lastButtonUp == 0) {
        selectedIndex = (selectedIndex + 2) % 3; // Move up (decrement)
        displayNeedsUpdate = 1;
      }
      lastButtonUp = buttonUp;
      
      // Handle DOWN button (cycle up)
      if (buttonDown == 1 && lastButtonDown == 0) {
        selectedIndex = (selectedIndex + 1) % 3; // Move down (increment)
        displayNeedsUpdate = 1;
      }
      lastButtonDown = buttonDown;
      
      // Handle A button (confirm selection)
      if (buttonA == 1 && lastButtonA == 0) {
        playerPokemon = getStarter(selectedIndex);
        enemyPokemon = getEnemy();
        
        // Initialize battle
        battle.playerTurn = 1;
        battle.turnCount = 0;
        battle.player = &playerPokemon;
        battle.enemy = &enemyPokemon;
        
        displayNeedsUpdate = 1;
        changeState(STATE_BATTLE);
      }
      lastButtonA = buttonA;
      break;
      
    case STATE_BATTLE:
      // Display battle UI
      if (displayNeedsUpdate) {
        char line1[17];
        char line2[17];
        
        // Format player info: "NAME HP:XX/XX"
        snprintf(line1, 17, "%.9s HP:%2d/%2d", 
                 playerPokemon.name, 
                 playerPokemon.currentHP, 
                 playerPokemon.maxHP);
        
        // Format enemy info
        snprintf(line2, 17, "%.9s HP:%2d/%2d", 
                 enemyPokemon.name, 
                 enemyPokemon.currentHP, 
                 enemyPokemon.maxHP);
        
        displayMessage(line1, line2);
        displayNeedsUpdate = 0;
      }
      
      if (battle.playerTurn) {
        // Player's turn - wait for button A
        if (buttonA == 1 && lastButtonA == 0) {
          // Player attacks
          int damage = calculateDamage(battle.player);
          applyDamage(battle.enemy, damage);
          
          // Show attack message briefly
          char msg[17];
          snprintf(msg, 17, "%s attacks!", battle.player->name);
          displayMessage(msg, "");
          displayNeedsUpdate = 1;
          
          battle.playerTurn = 0;
          enemyTurnDelay = 3; // Wait 3 ticks (3 seconds) before enemy turn
          
          // Check if battle ended
          int result = checkBattleEnd(battle.player, battle.enemy);
          if (result != 0) {
            changeState(result);
            displayNeedsUpdate = 1;
          }
        }
        lastButtonA = buttonA;
      } else {
        // Enemy's turn - automatic after delay
        if (enemyTurnDelay > 0) {
          enemyTurnDelay--;
        } else {
          // Enemy attacks
          int damage = calculateDamage(battle.enemy);
          applyDamage(battle.player, damage);
          
          // Show attack message briefly
          char msg[17];
          snprintf(msg, 17, "%s attacks!", battle.enemy->name);
          displayMessage(msg, "");
          displayNeedsUpdate = 1;
          
          battle.playerTurn = 1;
          battle.turnCount++;
          
          // Check if battle ended
          int result = checkBattleEnd(battle.player, battle.enemy);
          if (result != 0) {
            changeState(result);
            displayNeedsUpdate = 1;
          } else {
            // Return to battle display after brief delay
            enemyTurnDelay = 2;
          }
        }
      }
      break;
      
    case STATE_VICTORY:
      // Victory screen
      if (displayNeedsUpdate) {
        displayMessage("VICTORY!", "Enemy fainted!");
        callDriver(DRV_LED, LED_VERDE, 0);
        displayNeedsUpdate = 0;
      }
      
      // Wait for button A to restart
      if (buttonA == 1 && lastButtonA == 0) {
        callDriver(DRV_LED, LED_VERMELHO, 0);
        changeState(STATE_START);
        displayNeedsUpdate = 1;
      }
      lastButtonA = buttonA;
      break;
      
    case STATE_DEFEAT:
      // Defeat screen
      if (displayNeedsUpdate) {
        displayMessage("DEFEAT", "You fainted!");
        callDriver(DRV_LED, LED_VERMELHO, 0);
        displayNeedsUpdate = 0;
      }
      
      // Wait for button A to restart
      if (buttonA == 1 && lastButtonA == 0) {
        callDriver(DRV_LED, LED_VERDE, 0);
        changeState(STATE_START);
        displayNeedsUpdate = 1;
      }
      lastButtonA = buttonA;
      break;
  }
  
  return REPEAT;
}

void loop() {
  // Empty - kernelLoop() handles everything
}
