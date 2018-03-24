/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

//#include "pitches.h"

const int switchPin = 13;
//const int ledPin = 13;
const int buzzPin = 15;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {

  
  pinMode(switchPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);

}


void loop() 
{

Serial.println("loop");
  if (digitalRead(switchPin) == LOW) {

    digitalWrite(ledPin, LOW);
    Serial.println("low");

  }

  else {

    digitalWrite(ledPin, HIGH);
    Serial.println("high");

  }

}

