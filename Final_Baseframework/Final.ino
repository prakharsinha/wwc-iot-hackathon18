const int switchPin = 13;        //
const int ledPin = 2;
const int buzzoPin = 15;
int pirPin = 12;               // PIR sensor
int pirState = LOW;             // we start, assuming no motion detected
int pirVal = 0;// variable for reading the pin status
int swiVal = 0;


void setup() {
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
    }

 
  else if (swiVal == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.println("WATER OFF");
  }
}


