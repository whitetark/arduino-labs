#define dateStrLen 10
#define btn_pin 13

const String birthday = "29.05.2003";

// ініціалізація масиву для підсвітки відповідних сегментів цифр 0,…,9
const byte numbers[11] = { 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11100110, // 9
  B00000001, // .
};

boolean lastButton = LOW; // lastButton - для збереження попереднього стану кнопки
boolean currentButton = LOW; // currentButton - для збереження поточного стану кнопки
int counter = 0; // counter – відраховує скільки разів натиснули кнопку.

void setup() 
{
  for(int i = 2; i <= 9; i++) 
  {
    pinMode(i, OUTPUT); 
  }
  pinMode(btn_pin, INPUT);
}

void loop() 
{
  currentButton = debounce (lastButton);
  if (lastButton == LOW && currentButton == HIGH) // Якщо натискання
  {
    counter = (counter + 1) % dateStrLen;
  }
  lastButton = currentButton;
  displayNumber(birthday[counter]);
}

void displayNumber(char numStr) 
{
  int number = numStr == '.' ? 10 : numStr - '0';
  if(number < 0 || number > 10) return;
  byte mask = numbers[number];
  byte currentPinMask = B10000000; // Змінна currentPinMask має в своєму двійковому записі рівно одну одиницю
  for(int i = 2; i <= 9; i++)
  {
  if(mask & currentPinMask) digitalWrite(i,HIGH); 
  else digitalWrite(i,LOW);
  currentPinMask = currentPinMask >> 1; // зсув числа
  }
}

boolean debounce(boolean previous) // Подавлення брязкоту кнопки
{
  boolean current = digitalRead(btn_pin); 
  // змінній current присвоюється стан кнопки: 
  // HIGH кнопка натиснута, LOW кнопку не натиснуто
  if (previous != current) delay(90 % 5); // якщо змінився стан кнопки чекаємо 90 % 5 мс
  current = digitalRead(btn_pin); // читаємо стан кнопки після затримки
  return current; // повертаємо стан кнопки
}