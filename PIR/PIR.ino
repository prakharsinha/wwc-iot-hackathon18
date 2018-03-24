/**
 * BasicHTTPClient.ino
 *
 *  Created on: 24.05.2015
 *
 */

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;

/*
 * PIR sensor tester
 */
 
int ledPin = 16;                // choose the pin for the LED
int inputPin = 12;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(9600);
}
 
void loop(){
  
  Serial.println("Loop");
  val = digitalRead(inputPin);  // read input value
  //val = LOW;
  if (val == HIGH) {            // check if the input is HIGH
    Serial.println("HIGH");
    digitalWrite(LED_BUILTIN, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    Serial.println("LOW");
    digitalWrite(LED_BUILTIN, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
