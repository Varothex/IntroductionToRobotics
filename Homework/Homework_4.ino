#include <EEPROM.h>

const int pinSW = 3;
const int pinX = A0;
const int pinY = A1;

const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 10;

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int maxAnalogRead = 1023;
const unsigned long debounceInterval = 200;

const int displayCount = 4;
int displayDigits[displayCount] = {segD1, segD2, segD3, segD4};
int number[displayCount] = {0, 0, 0, 0};

int digitIndex;
int digitToShow;

bool dpState;
const int dpInterval = 500;
unsigned long lastDpFlick = 0;

bool swState = HIGH;
bool joyMoved = false;

int xValue = 0;
int yValue = 0;

int rightThreshold = 680;
int leftThreshold = 340;
int downThreshold = 340;
int upThreshold = 680;

const byte byteMask = 0xFF;
const int byteLength = 8;

int digitArray[16] = 
{
// ABCDEFGDP
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

void setup() 
{
  pinMode(pinSW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinSW), changeSwState, FALLING);

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) 
  {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW);
  }
  setCurrentNumber(readEEPROM());

  Serial.begin(9600);
}

void loop() 
{
  writeNumber();
  writeEEPROM(getCurrentNumber());

  if (swState == HIGH) // as long as the button was not pressed, we can switch the digit
  {
    yValue = analogRead(pinY); // the values are between 0 (left) and 1023 (right)

    if (yValue > rightThreshold && !joyMoved) // we go right
    {
      if (digitIndex + 1 < displayCount) 
      {
        digitIndex++;
      }
      else 
      {
        digitIndex = 0;
      }
      joyMoved = true;
    }

    if (yValue < leftThreshold && !joyMoved) // we go left
    {
        if (digitIndex > 0) 
        {
          digitIndex--;
        }
         else 
        {
          digitIndex = displayCount - 1;
        }
        joyMoved = true;
    }
    
    if (leftThreshold <= yValue && yValue <= rightThreshold) 
    {
      joyMoved = false;
    } 

    if (millis() - lastDpFlick >= dpInterval) 
    {
      dpState = !dpState;
      lastDpFlick = millis();
    }
  }
  else // when we press the button, we can no longer change the digit, but we can now change the number
  {
    dpState = HIGH;
    xValue = analogRead(pinX);
    digitToShow = number[digitIndex];

    if (xValue < downThreshold && joyMoved == false) // pointing the joystick down will decrement the digit
    {
      if (digitToShow > 0) 
      {
        digitToShow--;
      }
      else 
      {
        digitToShow = 9;
      }
      joyMoved = true;
    }

    if (xValue > upThreshold && joyMoved == false) // pointing the joystick up will increment the digit
    {
      if (digitToShow < 9) 
      {
        digitToShow++;
      }
      else 
      {
        digitToShow = 0;
      }
      joyMoved = true;
    }

    if (downThreshold <= xValue && xValue <= upThreshold) 
    {
      joyMoved = false;
    }

    number[digitIndex] = digitToShow;
  }
}

void changeSwState() // the blinking dot indicating the current digit that we are about to edit
{
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();

  if (interruptTime - lastInterruptTime >= debounceInterval) 
  {
    swState = !swState;
  }

  lastInterruptTime = interruptTime;
}

void writeNumber() 
{
  for (int i = 0; i < displayCount; i++) 
  // for (int i = displayCount-1; i >= 0; i--)
  {
    showDigit(displayCount - i - 1);
    // showDigit(displayCount);
    if (i == digitIndex) 
    {
      writeReg(digitArray[number[i]] ^ dpState);
    }
    else 
    {
      writeReg(digitArray[number[i]]);
    }
    delay(5);
  }
}

void showDigit(int displayNumber) 
{
  for (int i = 0; i < displayCount; i++) 
  {
    digitalWrite(displayDigits[i], HIGH);
  }

  digitalWrite(displayDigits[displayNumber], LOW);
}

void writeReg(int digit) 
{
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, digit);

  digitalWrite(latchPin, HIGH);
}

int getCurrentNumber() 
{
  int answer = 0;
  for (int i = 0; i < displayCount; i++) 
  {
    answer = answer * 10 + number[i];
  }
  return answer;
}

void setCurrentNumber(int currentNumber) 
{
  for (int i = displayCount - 1; i >= 0; i--) 
  {
    number[i] = currentNumber % 10;
    currentNumber /= 10;
  }
}

void writeEEPROM(int currentNumber) 
{
  byte firstByte = currentNumber & byteMask;
  byte secondByte = (currentNumber >> byteLength) & byteMask;
  EEPROM.update(0, secondByte);
  EEPROM.update(1, firstByte);
}

int readEEPROM() 
{
  int answer = 0;
  byte firstByte = EEPROM.read(1);
  byte secondByte = EEPROM.read(0);
  answer = secondByte;
  return (answer << byteLength) | firstByte;
}
