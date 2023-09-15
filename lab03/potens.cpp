#define led_pin 4
#define pot_pin 1
// 93%20
#define n 20 

int start, end, pot_value;

void setup() {
	Serial.begin(9600);
  	pinMode(led_pin, OUTPUT);
}

void loop() {
  start = n * 20;
  end = n * 40;
  delay(500);
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);

  if (pot_value > start && pot_value < end) {
    digitalWrite(led_pin, HIGH);
    delay(1000);
    digitalWrite(led_pin, LOW);
    delay(1000);
  }
}