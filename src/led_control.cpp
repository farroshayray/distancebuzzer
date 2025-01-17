#include <Arduino.h>
void turnOnLED(int pin) {
  digitalWrite(pin, HIGH);
}

// Function to turn off the LED
void turnOffLED(int pin) {
  digitalWrite(pin, LOW);
}