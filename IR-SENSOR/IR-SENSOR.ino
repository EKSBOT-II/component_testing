/* PINS */
// int IRIN1 = 27;
// int IRIN2 = 26;
// int IRIN3 = 25;
// int IRIN4 = 33;
// int IRIN5 = 32;

// temp:
int IRIN1 = 26;
int IRIN2 = 25;
int IRIN4 = 33;
int IRIN5 = 32;

int LED = 2;

/* VARS */
int IR1, IR2, IR3, IR4, IR5;

void setup()
{
    Serial.begin(115200);

    pinMode(LED, OUTPUT);

    pinMode(IRIN1, INPUT);
    pinMode(IRIN2, INPUT);
    // pinMode(IRIN3, INPUT);
    pinMode(IRIN4, INPUT);
    pinMode(IRIN5, INPUT);
}

void loop()
{
    IR1 = digitalRead(IRIN1);
    IR2 = digitalRead(IRIN2);
    // IR3 = digitalRead(IRIN3);
    IR4 = digitalRead(IRIN4);
    IR5 = digitalRead(IRIN5);

    // high = no reflection = white = no obj
    if ((IR2 == HIGH) && (IR4 == HIGH))
    {
        digitalWrite(LED, HIGH);
        Serial.println("sedang mengikuti garis");
    }
    else
    {
        digitalWrite(LED, LOW);
        Serial.println("gak di garis");
    }
}