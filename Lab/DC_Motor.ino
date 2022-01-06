int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;

int motorSpeed = 255;
bool reverse = true; // 0 = LOW

void setup() 
{
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() 
{
  setMotor(motorSpeed, reverse);
}

void setMotor(int motorSpeed, bool reverse) 
{
  analogWrite(enablePin, motorSpeed);
  digitalWrite(in1Pin, reverse);
  digitalWrite(in2Pin, !reverse);
}
