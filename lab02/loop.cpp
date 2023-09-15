const int led = 2;

const int start = 93;
const int finish = (100 * 3) + 1000;
const int step = 93 + 100;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = start; i <= finish; i = i + step) {
    digitalWrite(led, HIGH);
    delay(i);
    digitalWrite(led, LOW);
    delay(i);
    Serial.println(i);
  }
}