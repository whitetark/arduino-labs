#define pinNumber 7

const float seconds = 1.0;

void setup()
{
  pinMode(pinNumber, OUTPUT);
}

void loop()
{
  digitalWrite(pinNumber, HIGH);
  delay(1000 * seconds); 
  digitalWrite(pinNumber, LOW);
  delay(1000 * seconds); 
}