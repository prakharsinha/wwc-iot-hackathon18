const int switchPin = 14;
const int ledPin = 13;

void setup() {

  pinMode(switchPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(switchPin, HIGH);

  Serial.begin(9600);

}

void loop() {

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
