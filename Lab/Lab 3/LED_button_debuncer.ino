const int pushButton = 2;
const int ledPin = 8;
const int debounceInterval = 50;

int lastDebounceTimer = 0;

bool buttonState = LOW;
bool ledState = LOW;
bool lastReading = LOW;
bool reading = LOW;

void setup() 
{
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
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
      if (buttonState == HIGH)
      {
        ledState = !ledState;
      }
      digitalWrite(ledPin, ledState);
    }
  }
  
  lastReading = reading;
}
