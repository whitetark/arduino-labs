#define IN3 2
#define IN4 3
#define EN2 5

int pot_pin = 0;
int btn = 7;
boolean PREV_STATE = LOW;
boolean CURRENT_STATE = LOW;
boolean LEFT = false;

void setMotor(int speed, bool reverse) {
  analogWrite(EN2, speed);
  digitalWrite(IN3, !reverse);
  digitalWrite(IN4, reverse);
}

void setup()
{
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(pot_pin, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  int speed = analogRead(pot_pin) / 4;
  setMotor(speed, LEFT);
  
  CURRENT_STATE = debounce(PREV_STATE);
  if (PREV_STATE == LOW && CURRENT_STATE == HIGH) {
    LEFT = !LEFT;
  }
  PREV_STATE = CURRENT_STATE;
}

boolean debounce(boolean previous){
  boolean current = digitalRead(btn);
  if (previous != current) delay(90 % 5);
  current = digitalRead(btn);
  return current;
}
