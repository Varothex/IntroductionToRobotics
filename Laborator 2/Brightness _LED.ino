const int ledPin = 11;

int brightness = 0;
int amount = 5;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  brightness += amount;
  analogWrite(ledPin, brightness);
  
  if (brightness >= 255 || brightness <= 0)
  {
    amount = -amount;
  }

  delay(30);
}
