const int greenPin = 9;
const int bluePin = 10;
const int redPin = 11;

const int potGreen = A0;
const int potBlue = A1;
const int potRed = A2;

const float minAnalogValue = 0.0;
const float maxAnalogValue = 1023.0;
const float minBrightness = 0.0;
const float maxBrightness = 255.0;

float potValueGreen = 0.0;
float potValueBlue = 0.0;
float potValueRed = 0.0;

float trueValueGreen = 0.0;
float trueValueBlue = 0.0;
float trueValueRed = 0.0;

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
  potValueGreen = analogRead(potGreen);
  // I have a common cathode, therefore I must substarct the returned value from the maxim RGB brightness.
  trueValueGreen = maxBrightness - map(potValueGreen, minAnalogValue, maxAnalogValue, minBrightness, maxBrightness);

  potValueBlue = analogRead(potBlue);
  trueValueBlue = maxBrightness - map(potValueBlue, minAnalogValue, maxAnalogValue, minBrightness, maxBrightness);
  
  potValueRed = analogRead(potRed);
  trueValueRed = maxBrightness - map(potValueRed, minAnalogValue, maxAnalogValue, minBrightness, maxBrightness);

  analogWrite(greenPin, trueValueGreen);
  analogWrite(bluePin, trueValueBlue);
  analogWrite(redPin, trueValueRed);
}
