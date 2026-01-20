#include "display.h"
#include <string.h>

void displayMessage(const char* line1, const char* line2) {
  // Clear LCD
  callDriver(DRV_LCD, LCD_CLEAR, NULL);
  
  // Print line 1
  if (line1 != NULL) {
    char cursor1[2] = {0, 0};
    callDriver(DRV_LCD, LCD_SET_CURSOR, (void*)cursor1);
    callDriver(DRV_LCD, LCD_PRINT, (void*)line1);
  }
  
  // Print line 2
  if (line2 != NULL) {
    char cursor2[2] = {0, 1};
    callDriver(DRV_LCD, LCD_SET_CURSOR, (void*)cursor2);
    callDriver(DRV_LCD, LCD_PRINT, (void*)line2);
  }
}

void displayPokemonInfo(const char* name, int currentHP, int maxHP) {
  // Format: "NAME HP:XX/XX"
  // This is a simplified version - in practice you'd need a buffer
  // For now, we'll create the display in the calling code
  // This function serves as a placeholder for future enhancement
  (void)name;
  (void)currentHP;
  (void)maxHP;
}
