#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27);

int button;
int menu = 1;

uint8_t customCharacter[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000,
};

void setup()
{
    // lcd.begin(16, 2);
    // lcd.createChar(0, customCharacter);
    Serial.begin(115200);
}

void loop()
{
    // lcd.setCursor(0, 0);
    Serial.print("printing");
    // lcd.print("test");
    Serial.print("printed");
    delay(1000);
}