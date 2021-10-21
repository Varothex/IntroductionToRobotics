const int ledPin = 11;
const int potPin = A0;

int potValue = 0;
float voltage = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  potValue = analogRead(potPin);
  voltage = potValue * 5.0 / 1023.0;
  Serial.println(voltage);
  analogWrite(ledPin, potValue);
}
