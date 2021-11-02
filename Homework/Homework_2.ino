const int pushButton = 2;
const int buzzer = 3;
const int ledRed = 8;
const int ledGreen = 9;
const int ledGreenCar = 10;
const int ledYellowCar = 11;
const int ledRedCar = 12;
const int intervalBuzzSlow = 1000;
const int intervalBuzzFast = 500;

int lastDebounceTimer = 0;
int debounceInterval = 50;
int buzzerTone = 650;
int timerSlow;
int timerFast;

unsigned int lastChangedSlow;
unsigned int elapsedTimeSlow;
unsigned int lastChangedFast;
unsigned int elapsedTimeFast;

bool buttonState = LOW;
bool buzzerState = LOW;
bool redLedState = HIGH;
bool greenLedState = LOW;
bool greenLedCarState = HIGH;
bool yellowLedCarState = LOW;
bool redLedCarState = LOW;
bool lastReading = LOW;
bool reading = LOW;

void setup() 
{
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledGreenCar, OUTPUT);
  pinMode(ledYellowCar, OUTPUT);
  pinMode(ledRedCar, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(ledRed, redLedState);
  digitalWrite(ledGreenCar, greenLedCarState);
  
  reading = digitalRead(pushButton);

  if (reading != lastReading)
  {
    lastDebounceTimer = millis();
  }

  if (millis() - lastDebounceTimer > debounceInterval)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      if (buttonState == HIGH)
      {
        delay(10000);
        
        greenLedCarState = !greenLedCarState;
        digitalWrite(ledGreenCar, greenLedCarState);
        yellowLedCarState = !yellowLedCarState;
        digitalWrite(ledYellowCar, yellowLedCarState);
        delay(3000);  
        
        yellowLedCarState = !yellowLedCarState; 
        digitalWrite(ledYellowCar, yellowLedCarState);
        redLedCarState = !redLedCarState;
        digitalWrite(ledRedCar, redLedCarState);
        redLedState = !redLedState;
        digitalWrite(ledRed, redLedState);
        greenLedState = !greenLedState;
        digitalWrite(ledGreen, greenLedState);

        timerSlow = 0;
        lastChangedSlow = 0;
        while (timerSlow <= 10)
        {
          elapsedTimeSlow = millis();
          if (elapsedTimeSlow - lastChangedSlow >= intervalBuzzSlow)
          {
            tone(buzzer, buzzerTone, 500);
            lastChangedSlow = elapsedTimeSlow;
            timerSlow++;
          }
        }

        timerFast = 0;
        lastChangedFast = 0;
        while (timerFast <= 10)
        {
          elapsedTimeFast = millis();
          if (elapsedTimeFast - lastChangedFast >= intervalBuzzFast)
          {
            greenLedState = !greenLedState;
            digitalWrite(ledGreen, greenLedState);
            tone(buzzer, buzzerTone, 125);
            lastChangedFast = elapsedTimeFast;
            timerFast++; 
          }
        }

        noTone(buzzer);
        redLedState = !redLedState;
        digitalWrite(ledRed, redLedState);

        redLedCarState = !redLedCarState;
        digitalWrite(ledRedCar, redLedCarState);
        greenLedCarState = !greenLedCarState;
        digitalWrite(ledGreenCar, greenLedCarState);
      }
    }
  }
  lastReading = reading;
}
  
