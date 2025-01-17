#include <Arduino.h>
#include "led_control.h"

#define TRIG_PIN 9  // Define the pin for the TRIG signal
#define ECHO_PIN 10 // Define the pin for the ECHO signal

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    while (!Serial); // Wait for the serial port to connect (optional for some boards)

    // Initialize pins
    pinMode(13, OUTPUT); // LED pin
    pinMode(TRIG_PIN, OUTPUT); // HC-SR04 trigger pin
    pinMode(ECHO_PIN, INPUT);  // HC-SR04 echo pin

    Serial.println("Setup complete. Starting LED blinking and distance measurement...");
}

void loop() {
    long duration;
    float distance;

    // Send a 10-microsecond pulse to trigger the sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read the duration of the echo pulse
    duration = pulseIn(ECHO_PIN, HIGH);

    // Calculate the distance in centimeters
    distance = (duration * 0.034) / 2;

    // Print the distance to the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if the distance is less than a threshold (e.g., 10 cm)
    if (distance < 10) {
        turnOnLED(13); // Turn on the LED
        Serial.println("Object detected within 10 cm. LED is ON.");
    } else {
        turnOffLED(13); // Turn off the LED
        Serial.println("Object out of range. LED is OFF.");
    }

    // Wait before taking the next reading
    delay(500);
}
