#include <Ultrasonic.h>

// Initialize the Ultrasonic sensor
Ultrasonic ultrasonic(2); // Connect the SIG pin of the sensor to digital pin 2

// Buzzer
const int buzzerPin = 4; // Buzzer pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Buzzer
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Measure the distance using the Ultrasonic sensor
  long distance = ultrasonic.MeasureInCentimeters();

  // Print the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than 30 centimeters
  if (distance < 30) {
    // Activate the buzzer
    digitalWrite(buzzerPin, LOW);
  } else {
    // Deactivate the buzzer
    digitalWrite(buzzerPin, HIGH);
  }
}