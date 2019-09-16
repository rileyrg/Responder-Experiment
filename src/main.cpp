#include<Arduino.h>

int redLEDPin=8;     // set Red LED as “output”
int yellowLEDPin=7;  // set Yellow LED as “output”
int greenLEDPin=6;   // set Green LED as “output”
int redKeyPin=5;       // initialize pin for Red button
int yellowKeyPin=4;       // initialize pin for Yellow button
int greenKeyPin=3;       // initialize pin for Green button
int resetKeyPin=2;    // initialize pin for reset button

int setLED=redLEDPin;

void resetLEDs();

void setup()
{
  Serial.begin(9600);
  pinMode(redLEDPin,OUTPUT);
  pinMode(yellowLEDPin,OUTPUT);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redKeyPin,INPUT);
  pinMode(yellowKeyPin,INPUT);
  pinMode(greenKeyPin,INPUT);
  pinMode(resetKeyPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(resetKeyPin), resetLEDs,FALLING);
  if(setLED)
    digitalWrite(setLED,HIGH);
}

void loop()         // repeatedly read pins for buttons
{
  if(setLED==0){
    setLED=digitalRead(redKeyPin)?redLEDPin:digitalRead(yellowKeyPin)?yellowLEDPin:digitalRead(greenKeyPin)?greenLEDPin:0;
    if(setLED){
      char str[15];
      Serial.println(sprintf(str,"Key pressed: %u",setLED));
      digitalWrite(setLED,HIGH);
    }
  }
}

void resetLEDs(){
  Serial.println("Resetting LEDs");
  digitalWrite(setLED,LOW);
  setLED=0;
}
