int IR1;

void setup()
{
    Serial.begin(9600);
    pinMode(IR1, INPUT);
}

void loop()
{
    Serial.println(IR1);
}