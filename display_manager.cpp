#include "display_manager.h"
#include "config.h"

DisplayManager::DisplayManager() : lcd(LCD_I2C_ADDR, LCD_COLUMNS, LCD_ROWS) {}

void DisplayManager::begin() {
    lcd.init();
    lcd.backlight();
    showMessage("System Ready", "Awaiting Motion");
}

void DisplayManager::showMessage(const String& line1, const String& line2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(line2.substring(0, 16));
}

void DisplayManager::clearDisplay() {
    lcd.clear();
}
