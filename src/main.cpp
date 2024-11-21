#include <Arduino.h>
#include "thermistor.h"

// Thermistor configuration
const double Rref = 20000;      // Reference resistance in ohms
const double R0 = 18000;        // Resistance at 25°C in ohms
const double Beta = 3950;       // Beta coefficient 
const unsigned samplingBits = 10; // ADC resolution in bits
const int thermistorPin = A1;   // Analog pin for reading the thermistor

Thermistor thermistor(Rref, R0, Beta, samplingBits);

void setup() {
  Serial.begin(9600);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  // Read the ADC value
  int adcValue = analogRead(thermistorPin);
  
  // Convert to temperature
  double tempC = thermistor.getTemperature(adcValue, 'C');
  
  // Display the results
  Serial.print("ADC value: ");
  Serial.println(adcValue);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");
  
  delay(5000); // Measure every 5 seconds
}
