const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin1 = 11;       // pin that LED is attached to
const int ledPin2 = 10;       // pin that LED is attached to
const int ledPin3 = 12;       // pin that LED is attached to
const int ledPin4 = 9;       // pin that LED is attached to
const int threshold1 = 250; 
const int threshold2 = 500;
const int threshold3 = 750; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue < threshold1) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }

  if (analogValue < threshold2 && analogValue > threshold1) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  if (analogValue < threshold3 && analogValue > threshold2) {
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }

  if (analogValue > threshold3) {
    digitalWrite(ledPin4, HIGH);
  } else {
    digitalWrite(ledPin4, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability
}