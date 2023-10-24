#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Set the LCD I2C address

/* PINS */
int PB = 35;

/* VARS */
int pbVal;
int pbValPrev;
int selected = 1;

/* SETUP */
void setup()
{
    Serial.begin();
    lcd.begin(16, 2);

    pinMode(PB, INPUT);
}

/* LOOP */
void loop()
{
    // Menu reading
    pbValPrev = pbVal;
    pbVal = digitalRead(PB);
    if (pbVal != pbValPrev)
    {
        changeMenu(pbVal);

        Serial.print(pbVal);
        Serial.print("\t");
        Serial.println(selected);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(selected);
    }

    // Programs
    switch (selected)
    {
    case 1:
        Serial.println("Program 1");
        break;
    case 2:
        Serial.println("Program 2");
        break;
    case 3:
        Serial.println("Program 3");
        break;
    case 4:
        Serial.println("Program 4");
        break;

    default:
        Serial.println("INVALID PROGRAM");
        break;
    }
}

/* FUNCS */
// Menu Change Function
void changeMenu(int val)
{
    if (selected < 4)
    {
        selected++;
    }
    else
    {
        selected = 1;
    }
}