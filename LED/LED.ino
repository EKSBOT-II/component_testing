void setup()
{
    Serial1.begin(115200);

    pinMode(2, OUTPUT);
}

void loop()
{
    Serial1.println("HIGH");
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
}