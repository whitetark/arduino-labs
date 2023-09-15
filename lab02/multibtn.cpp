const int led = 6;
const int btn = 4;

boolean PREV_STATE = LOW;
boolean CURRENT_STATE = LOW;

const int MIN_VALUE = 93;
const int MAX_VALUE = 255 - 93;
const int DELAY = 10;

const int first_type = 1;
const int second_type = 2;
const int third_type = 3;
const int forth_type = 4;

int counter = 1;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop(){
  CURRENT_STATE = debounce(PREV_STATE);
  if (PREV_STATE == LOW && CURRENT_STATE == HIGH) {
    if (counter > 4) counter = 1;
    switch(counter){
      case first_type:
      	fromMinToMax();
      	break;
      case second_type:
      	fromMaxToMin();
      	break;
      case third_type:
      	digitalWrite(led, HIGH);
      	break;
      case forth_type:
      	digitalWrite(led, LOW);
      	break;
    }
    counter++;
  }
  PREV_STATE = CURRENT_STATE;
}

void fromMinToMax(){
  for (int i = MIN_VALUE; i < MAX_VALUE; i++) {
    analogWrite(led, i);
    Serial.println(i);
    delay(DELAY);
  }
}

void fromMaxToMin(){
  for (int i = MAX_VALUE; i >= MIN_VALUE; i--) {
    analogWrite(led, i);
    Serial.println(i);
    delay(DELAY);
  }
}

boolean debounce(boolean last){
  boolean current = digitalRead(btn);
  if (last != current) delay(5);
  current = digitalRead(btn);
  return current;
}