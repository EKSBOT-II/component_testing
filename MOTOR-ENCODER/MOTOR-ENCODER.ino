/* PINS */
int LE = 12;
int L1 = 14;
int L2 = 27;
int RE = 33;
int R1 = 26;
int R2 = 25;

/* LOG VARS */
int LcurrentSpeed;
int RcurrentSpeed;

/* SETUP */
void setup()
{
    Serial.begin(115200);

    pinMode(LE, OUTPUT);
    pinMode(L1, OUTPUT);
    pinMode(L2, OUTPUT);

    pinMode(RE, OUTPUT);
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
}

/* LOOP */
void loop()
{
    // digitalWrite(L1, HIGH);
    // digitalWrite(L2, LOW);

    // digitalWrite(R1, HIGH);
    // digitalWrite(R2, LOW);

    // analogWrite(LE, 255);
    // analogWrite(RE, 255);

    // delay(1000);

    // analogWrite(LE, 0);
    // analogWrite(RE, 0);

    // delay(1000);

    Serial.println("Forward");
    motorRun(100, 100);
    delay(3000);

    Serial.println("Backward");
    motorRun(-100, -100);
    delay(3000);

    Serial.println("Silent");
    motorRun(0, 0);
    delay(4000);

    Serial.println("Backward");
    motorRun(-100, -100);
    delay(3000);

    Serial.println("Forward");
    motorRun(100, 100);
    delay(3000);

    Serial.println("Silent");
    motorRun(0, 0);
    delay(4000);

    for (int i = 0; i < 100; i++)
    {
        Serial.println(i);
        motorRun(i, i);
        delay(200);
    }
}

/* FUNCTIONS */
// Speed Mapping
int speed(float val)
{
    return map(val, 0, 100, 0, 255);
}

// Motor Run
void motorRun(int Lnum, int Rnum)
{
    analogWrite(LE, speed(abs(Lnum)));
    LcurrentSpeed = Lnum;
    if (Lnum > 0)
    {
        digitalWrite(L1, HIGH);
        digitalWrite(L2, LOW);
    }
    else if (Lnum < 0)
    {
        digitalWrite(L1, LOW);
        digitalWrite(L2, HIGH);
    }
    else
    {
        digitalWrite(L1, LOW);
        digitalWrite(L2, LOW);
        // analogWrite(LE, 0);
    }

    analogWrite(RE, speed(abs(Rnum)));
    RcurrentSpeed = Rnum;
    if (Rnum > 0)
    {
        digitalWrite(R1, HIGH);
        digitalWrite(R2, LOW);
    }
    else if (Rnum < 0)
    {
        digitalWrite(R1, LOW);
        digitalWrite(R2, HIGH);
    }
    else
    {
        digitalWrite(R1, LOW);
        digitalWrite(R2, LOW);
        // analogWrite(RE, 0);
    }
}