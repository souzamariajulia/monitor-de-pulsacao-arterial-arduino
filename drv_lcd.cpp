#include "drv_lcd.h"

// LCD pin configuration (standard parallel interface)
// RS, E, D4, D5, D6, D7
#define LCD_RS_PIN 12
#define LCD_EN_PIN 11
#define LCD_D4_PIN 5
#define LCD_D5_PIN 4
#define LCD_D6_PIN 3
#define LCD_D7_PIN 2

static driver meu_cartao;
static ptrFuncDrv my_funcs[LCD_END];
static LiquidCrystal lcd(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
static char lcdInitialized = 0;

char clearLCD(void * parameters){
	if (!lcdInitialized) return FAIL;
	lcd.clear();
	return SUCCESS;
}

char printLCD(void * parameters){
	if (!lcdInitialized || parameters == NULL) return FAIL;
	char *text = (char *)parameters;
	lcd.print(text);
	return SUCCESS;
}

char setCursorLCD(void * parameters){
	if (!lcdInitialized || parameters == NULL) return FAIL;
	// Parameters: [col, row] as two bytes
	char *params = (char *)parameters;
	int col = params[0];
	int row = params[1];
	lcd.setCursor(col, row);
	return SUCCESS;
}

char initGenericoLCD(void * parameters){
	if (!lcdInitialized) {
		lcd.begin(16, 2); // 16 columns, 2 rows
		lcdInitialized = 1;
	}
	meu_cartao.id = (char) parameters;
	return SUCCESS;
}

driver * getLCDDriver(void){
	meu_cartao.initFunc = initGenericoLCD;
	my_funcs[LCD_INIT] = initGenericoLCD;
	my_funcs[LCD_CLEAR] = clearLCD;
	my_funcs[LCD_PRINT] = printLCD;
	my_funcs[LCD_SET_CURSOR] = setCursorLCD;
	meu_cartao.funcoes = my_funcs;
	return &meu_cartao;
}
