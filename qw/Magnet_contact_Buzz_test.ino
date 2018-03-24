

const int switchPin = 13;
//const int ledPin = 13;
const int BuzzoPin = 15;

void setup() {

  pinMode(switchPin, INPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(switchPin, INPUT_PULLUP);

  digitalWrite(switchPin, HIGH);

  

  Serial.begin(9600);

}

void loop() {
  Serial.println("loop");

  if (digitalRead(switchPin) == LOW) {

    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LOWNESS");
    
  }

  else {

    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("HIGNESS");
    tone(BuzzoPin, 1000, 500);
    

  }

}
