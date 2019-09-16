#include<Arduino.h>

int redLED=8;     // set Red LED as “output”
int yellowLED=7;  // set Yellow LED as “output”
int greenLED=6;   // set Green LED as “output”
int redKey=5;       // initialize pin for Red button
int yellowKey=4;       // initialize pin for Yellow button
int greenKey=3;       // initialize pin for Green button
int resetKey=2;    // initialize pin for reset button

int setLED=redLED;

void resetLEDs();

void setup()
{
  Serial.begin(9600);
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(redKey,INPUT);
  pinMode(yellowKey,INPUT);
  pinMode(greenKey,INPUT);
  pinMode(resetKey,INPUT);
  attachInterrupt(digitalPinToInterrupt(resetKey), resetLEDs,RISING);
  if(setLED)
    digitalWrite(setLED,HIGH);
}

void loop()         // repeatedly read pins for buttons
{
  if(setLED==0){
    setLED=digitalRead(redKey)?redLED:digitalRead(yellowKey)?yellowLED:digitalRead(greenKey)?greenLED:0;
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
