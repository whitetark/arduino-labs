#define led1_pin 3
#define led2_pin 5
#define led3_pin 6
#define light_pin 2
#define btn_pin 7

boolean PREV_STATE = LOW;
boolean CURRENT_STATE = LOW;
boolean SWITCH_ON = false;

const int min_light = 350 - 93 * 2;
const int max_light = 700 + 93 * 4;
int mode;

void setup(){
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    mode = Serial.parseInt();
    Serial.print("Mode value: ");
    Serial.println(mode);
    delay(500);
  }

  CURRENT_STATE = debounce(PREV_STATE);
  if (PREV_STATE == LOW && CURRENT_STATE == HIGH) {
    SWITCH_ON = !SWITCH_ON;
    Serial.print("Access mode: ");
    Serial.println(SWITCH_ON);
  }
  PREV_STATE = CURRENT_STATE;

  if (SWITCH_ON) {
    int value = analogRead(light_pin);
    value = map(value, 6, 679, 255, 0);
    value = constrain(value, 0, 255);
    int max = map(min_light, 200, 900, 255, 0);
    max = constrain(max, 0, 255);
    int min = map(max_light, 200, 900, 255, 0);
    min = constrain(min, 0, 255);

    int middle = (max + min) / 2;

    Serial.println(value);

    if (mode == 1) {
      if (value >= max) {
        digitalWrite(led1_pin, HIGH);
        digitalWrite(led2_pin, HIGH);
        digitalWrite(led3_pin, HIGH);
      }
      if (value >= middle && value < max) {
        digitalWrite(led1_pin, LOW);
        digitalWrite(led2_pin, HIGH);
        digitalWrite(led3_pin, HIGH);
      }
      if (value > min && value < middle) {
        digitalWrite(led1_pin, LOW);
        digitalWrite(led2_pin, LOW);
        digitalWrite(led3_pin, HIGH);
      }
      if (value <= min) {
        digitalWrite(led1_pin, LOW);
        digitalWrite(led2_pin, LOW);
        digitalWrite(led3_pin, LOW);
      }
    }
    if (mode == 2) {
      analogWrite(led1_pin, value);
      analogWrite(led2_pin, value);
      analogWrite(led3_pin, value);
    }
  }
}

boolean debounce(boolean previous){
  boolean current = digitalRead(btn_pin);
  if (previous != current) delay(3);
  current = digitalRead(btn_pin);
  return current;
}