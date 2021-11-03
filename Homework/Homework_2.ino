const int pushButton = 2;
const int buzzer = 3;
const int ledRed = 8;
const int ledGreen = 9;
const int ledGreenCar = 10;
const int ledYellowCar = 11;
const int ledRedCar = 12;
const int intervalBuzzSlow = 1000;
const int intervalBuzzFast = 500;
const int periodStart = 10000;
const int periodYellow = 3000;
const unsigned long slowDuration = 10;
const unsigned long fastDuration = 125;

int lastDebounceTimer = 0;
int debounceInterval = 50;
int buzzerTone = 650;
int timerSlow;
int timerFast;

unsigned int lastChangedSlow;
unsigned int elapsedTimeSlow;
unsigned int lastChangedFast;
unsigned int elapsedTimeFast;
unsigned long start = 0;

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

  digitalWrite(ledRed, redLedState);
  digitalWrite(ledGreenCar, greenLedCarState);
}

void loop() 
{
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
      if (buttonState == LOW)
      {
        start = millis();
        while(millis() - start < periodStart)
        {
          // We wait for the period mentioned.
        }
        
        greenLedCarState = !greenLedCarState;
        digitalWrite(ledGreenCar, greenLedCarState);
        yellowLedCarState = !yellowLedCarState;
        digitalWrite(ledYellowCar, yellowLedCarState);
        
        start = millis();
        while(millis() - start < periodYellow)
        {
          // We wait for the period mentioned.
        }  
        
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
        while (timerSlow <= 10000 / intervalBuzzSlow) // We want a 10 seconds stage.
        {
          elapsedTimeSlow = millis();
          if (elapsedTimeSlow - lastChangedSlow >= intervalBuzzSlow)
          {
            tone(buzzer, buzzerTone, slowDuration);
            lastChangedSlow = elapsedTimeSlow;
            timerSlow++;
          }
        }

        timerFast = 0;
        lastChangedFast = 0;
        while (timerFast <= 5000 / intervalBuzzFast)  // We want a 5 seconds stage.
        {
          elapsedTimeFast = millis();
          if (elapsedTimeFast - lastChangedFast >= intervalBuzzFast)
          {
            greenLedState = !greenLedState;
            digitalWrite(ledGreen, greenLedState);
            tone(buzzer, buzzerTone, fastDuration);
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
