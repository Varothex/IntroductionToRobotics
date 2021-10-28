const int pushButton = 2;
bool buttonState = LOW;

void setup() 
{
  pinMode(pushButton, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
}
