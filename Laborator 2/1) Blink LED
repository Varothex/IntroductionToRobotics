const int ledPin = 13;

int interval = 1000;
unsigned int lastChanged = 0;
bool ledState = LOW;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  //  digitalWrite(ledPin, HIGH);
  //  delay(1000);
  //  digitalWrite(ledPin, LOW);
  //  delay(1000);
  unsigned int elapsedTime = millis();

  if (elapsedTime - lastChanged > interval)
  {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    lastChanged = elapsedTime;
  }
  
  Serial.println(elapsedTime);
}
