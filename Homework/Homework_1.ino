const int redPin = 11;
const int bluePin = 10;
const int greenPin = 9;

const int potGreen = A0;
const int potBlue = A1;
const int potRed = A2;

float potValueGreen = 0.00;
float potValueBlue = 0.00;
float potValueRed = 0.00;

void setup() 
{
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(potGreen, INPUT);
  pinMode(potBlue, INPUT);
  pinMode(potRed, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  potValueGreen = analogRead(potGreen) * 255.0 / 1023.0;
  potValueBlue = analogRead(potBlue) * 255.0 / 1023.0;
  potValueRed = analogRead(potRed) * 255.0 / 1023.0;

  analogWrite(greenPin, 255.00 - potValueGreen);
  analogWrite(bluePin, 255.00 - potValueBlue);
  analogWrite(redPin, 255.00 - potValueRed);
}
  
