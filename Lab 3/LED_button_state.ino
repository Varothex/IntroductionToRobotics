const int pushButton = 2;
bool buttonState = LOW;

const int ledPin = 8;
bool ledState = LOW;

int counter = 0;
bool lastButtonState = LOW;

void setup() 
{
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonState = digitalRead(pushButton);
  if (buttonState != lastButtonState and buttonState == LOW)
  {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    counter++;
  }
  lastButtonState = buttonState;
  Serial.println(counter);
  
}
  
