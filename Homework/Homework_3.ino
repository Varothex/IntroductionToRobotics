#define sample 300

const int pinA = 12;
const int pinB = 13;
const int pinC = 9;
const int pinD = 8;
const int pinE = 7;
const int pinF = 11;
const int pinG = 10;
const int segSize = 7;

int segments[segSize] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};

byte digitMatrix[10][segSize] = 
{
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(byte digit) 
{
  for (int i = 0; i < segSize; i++) 
  {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
}

const int inputPin = 5;
const int buzzPin = 5;
const int pinLed = 6;
float val;
int array1[sample];

unsigned long averaging;

void setup() 
{
  for (int i = 0; i < segSize; i++) 
  {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(inputPin, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{               
  for (int i = 0; i < sample; i++)
  {
    array1[i] = analogRead(inputPin);
    averaging += array1[i];
  }
  val = averaging / sample;
  analogWrite(buzzPin, val);
  
  val = constrain(val, 0, 10);
//  Serial.println(val);
  if (0.0 <= val and val <= 1.0)               
  {  
    displayNumber(0);   
  }
  if (1.0 <= val and val <= 2.0)               
  {
    displayNumber(1);
  }
  if (2.0 <= val and val <= 3.0)               
  {
    displayNumber(2);    
  }
  if (3.0 <= val and val <= 4.0)               
  {
    displayNumber(3);    
  }
  if (4.0 <= val and val <= 5.0)               
  {
    displayNumber(4);    
  }
  if (5.0 <= val and val <= 6.0)               
  {
    displayNumber(5);    
  }
  if (6.0 <= val and val <= 7.0)               
  {
    displayNumber(6);    
  }  
  
  val = map(val, 0, 10, 0, 255);
  analogWrite(pinLed, val);
  averaging = 0;
}
