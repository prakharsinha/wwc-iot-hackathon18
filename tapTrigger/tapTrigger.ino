/***************************************************
  Adafruit IO Trigger Example
  Must use ESP8266 Arduino from:
    https://github.com/esp8266/Arduino
  Works great with Adafruit's Huzzah ESP board:
  ----> https://www.adafruit.com/product/2471
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
  Written by Todd Treece for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include "Adafruit_IO_Client.h"

// function prototypes

void tap_on();

const int switchPin = 13;        //
const int ledPin = 2;
const int buzzoPin = 15;
int pirPin = 12;               // PIR sensor
int pirState = LOW;             // we start, assuming no motion detected
int pirVal = 0;// variable for reading the pin status
int swiVal = 0;


// wifi credentials
#define WLAN_SSID       "Puppet Guest"
#define WLAN_PASS       "argon4949"

// configure Adafruit IO access
#define AIO_KEY         "f3375e3c08804d7b942bd11d1ca08771"

// create an Adafruit IO client instance
WiFiClient client;
Adafruit_IO_Client aio = Adafruit_IO_Client(client, AIO_KEY);

void setup() {
  Serial.begin(9600);
  Serial.println("Tap trigger");

  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirPin, INPUT);     // declare sensor as input
  pinMode(switchPin, INPUT);  // The magnetic switch
  pinMode(switchPin, INPUT_PULLUP);
  digitalWrite(switchPin, HIGH);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Loop");
  pirVal = digitalRead(pirPin);      // read pir value
  swiVal = digitalRead(switchPin);   // read magnetic switch value
  if (pirVal == HIGH) {
    Serial.println("PERSON");
  }

  if (pirVal == LOW) {
    Serial.println("NO PERSON");
  }

  if (swiVal == HIGH && pirVal == HIGH) {
    Serial.println("you're good");
    digitalWrite(ledPin, LOW);
  }

  else if (swiVal == HIGH && pirVal == LOW ) {
    Serial.println("Water  still running!");
    digitalWrite(ledPin, HIGH);
    tone(buzzoPin, 1000, 500);
    delay(1000);
    tone(buzzoPin, 500, 500);
    delay(1000);
    tone(buzzoPin, 250, 500);
    delay(1000);
    tap_on();
  }


  else if (swiVal == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println("WATER OFF");
  }
}

// connect to wifi network. used by

void wifi_init() {

  // wifi init
  Serial.println("Starting WiFi");
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  // wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.write('.');
    delay(500);
  }

  // AIO init
  Serial.println("Connecting to Adafruit.io");
  aio.begin();

}

void tap_on() {

  // turn on wifi if we aren't connected
  if (WiFi.status() != WL_CONNECTED) {
    wifi_init();
  }

  // grab the door feed
  Adafruit_IO_Feed  tapOn = aio.getFeed("tap-on");

  Serial.println("Sending to Adafruit.io");
  // send door open value to AIO
  tapOn.send("1");

}

