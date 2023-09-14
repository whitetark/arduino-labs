#define pinNumberOutput 7
#define pinNumberDelay 6

const int dot = 1;
const int dash = 3*dot;
const int maxSymbols = 5;
const int dictionarySize = 5;
const char dictionary[dictionarySize] = "achp";
const int symbolsArray[dictionarySize][maxSymbols] = {{dot, dash},{dash, dot, dash, dot},{dot, dot, dot, dot},{dot, dash, dash, dot}};

void setup()
{  
  pinMode(pinNumberOutput, OUTPUT);
  pinMode(pinNumberDelay, OUTPUT);
}

void loop()
{
  const String surname = "chapcha";
  const int length = sizeof(dictionary)/sizeof(*dictionary);
  
  for (int i=0; i<surname.length(); i++) {
    int index = findIndex(surname[i], length);
    if (index == -1) continue;

    int symbolsLength = sizeof(symbolsArray[index])/sizeof(*symbolsArray[index]);
    for (int y=0; y<symbolsLength; y++) {
      if (symbolsArray[index][y] == 0) continue;
      makeItLigth(symbolsArray[index][y]);
    }
    makeLettersPause();
  }
}

int findIndex(char letter, int length) {
  for(int index=0; index<length; index++) {
    if (dictionary[index] == letter) {
      return index;
    }
  
  }
  return -1;  
}

void makeItLigth(int seconds) {
  digitalWrite(pinNumberOutput, HIGH);
  delay(1000 * seconds);
  digitalWrite(pinNumberOutput, LOW);
  delay(1000 * dot);
}

void makeLettersPause() {
  digitalWrite(pinNumberDelay, HIGH);
  delay(1000 * dash);
  digitalWrite(pinNumberDelay, LOW);
}