const int pushButton = 2;
bool buttonState = LOW;

const int ledPin = 8;
bool ledState = LOW;

void setup() 
{
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonState = digitalRead(pushButton);
  ledState = !buttonState;
  digitalWrite(ledPin, ledState);
  
}
  
