/* PINS */
int LE, L1, L2;
int RE, R1, R2;

/* LOG VARS */
int LcurrentSpeed;
int RcurrentSpeed;

/* SETUP */
void setup()
{
    Serial.begin(9600);
}

/* LOOP */
void loop()
{
    Serial.println("Forward");
    motorRun(100, 100);
    delay(2000);

    Serial.println("Backward");
    motorRun(-100, -100);
    delay(2000);

    Serial.println("Silent");
    motorRun(0, 0);
    delay(5000);

    for (int i = 0; i <= 100; i++)
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
        digitalWrite(L1, LOW);
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
    }
}