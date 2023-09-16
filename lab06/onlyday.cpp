#define dateStrLen 4

const String dateStr = "  29";
int step = 0;

String fixedLength(String str)
{  
  for(int i = str.length(); i < dateStrLen; i++) str = " " + str;
  return str.substring(0,dateStrLen);
}

String stepDate(String str, int step)
{
  return str.substring(step,dateStrLen) + str.substring(0,step);
}

void ledDigitDisplay(String num, float time)
{
	unsigned long ltime = millis();
	// налаштування  
   	// 6, 8, 9, 12 – GND в потрібний момент
	int pin[] = { 6, 7, 8, 9, 10, 2, 11, 3, 4, 12, 13, 5 }; // піни
	int settingsSegments[] = { pin[10], pin[6], pin[3], pin[1], pin[0], pin[9], pin[4], pin[2] }; // Порядок сегментів
	
	int segments[] = 
	{ 
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111, // 9
		0b10000000, // .
		0b01000000, // -
	};

	// визначаємо піни як вихід
	for (int i = 0; i < 12; ++i) pinMode(pin[i], OUTPUT);
	int floatingPoint = 0, minus = 4;

	for (int i = 0; millis() - ltime <= time * 1000; i++)
	{
		if (i >= 4) i = 0;

		int currentChar = num[3 - i];

		if (currentChar == ' ') continue;

		int temp = currentChar == '.' ? 10 : currentChar - '0';
		
		// працюємо з  4 розрядом
		if (i == 3) pinMode(pin[11], OUTPUT);
		else pinMode(pin[11], INPUT);
		// працюємо з  3 розрядом
		if (i == 2) pinMode(pin[8], OUTPUT); 
		else pinMode(pin[8], INPUT);
		// працюємо з  2 розрядом
		if (i == 1) pinMode(pin[7], OUTPUT);
		else pinMode(pin[7], INPUT);
		// працюємо з  1 розрядом
		if (i == 0) pinMode(pin[5], OUTPUT); 
		else pinMode(pin[5], INPUT);

		for (int j = 0; j < 8; j++) // Передаємо число
			if (segments[temp] & (1 << j))
				digitalWrite(settingsSegments[j], HIGH);
		delay(1); // невеличка пауза, щоб світлодіоди  «розігрілися»
		for (int j = 0; j < 8; j++) digitalWrite(settingsSegments[j], LOW);
		// вимикаємо  усі світлодіоди
	}
}

void setup() {}

void loop()
{
    ledDigitDisplay(fixedLength(stepDate(dateStr, step)), 1);
  	step++;
  	step = step % dateStrLen;
}