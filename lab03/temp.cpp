#define temp_pin 2

int value;

void setup(){
	Serial.begin(9600);
}

void millis(int DELAY, float cel, float farh){
  	delay(DELAY);
	Serial.print("Temperature = ");
  	Serial.print(cel);
  	Serial.print("*C");
  	Serial.println();
  	Serial.print("Temperature = ");
  	Serial.print(farh);
  	Serial.print("*F");
  	Serial.println();
}

void loop(){
  	value = analogRead(temp_pin);
  	float mv = (value / 1023.0) * 5000;
  	float cel = mv / 10;
  	float farh = (cel * 9) / 5 + 32;
  
  	millis(4650, cel, farh);
}