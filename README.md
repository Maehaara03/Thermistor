# Thermistor Library

**Version**: 1.0.0  
**Author**: Maehaara
**Date**: 21/11/2024

## Description

The **Thermistor Library** is a simple and effective solution for reading temperatures using thermistor sensors. It allows users to calculate the temperature in Kelvin, Celsius, or Fahrenheit based on the ADC values from a microcontroller such as an Arduino.

This library uses the Steinhart-Hart equation and supports various thermistor configurations through adjustable parameters such as `Rref`, `R0`, `Beta`, ADC resolution, and reference voltage.

---

## Features

- Supports NTC thermistors.
- Calculate temperature in **Kelvin (K)**, **Celsius (°C)**, or **Fahrenheit (°F)**.
- Configurable parameters for resistance, Beta value, and ADC resolution.
- Simple integration with Arduino projects.

---

## Installation

1. Clone or download this repository.
2. Place the folder `Thermistor` inside the `lib` directory of your PlatformIO project.
3. Include the library in your code:
   ```cpp
   #include <thermistor.h>

Below is the recommended wiring setup for the thermistor sensor:


       +5V
        |
        Rref
        |
        +-------> Analog Pin (e.g., A1)
        |
      Thermistor
        |
       GND


How to Use :

Initialize the Thermistor object with your specific parameters:

Thermistor thermistor(Rref, R0, Beta, samplingBits, Vcc, T0);


Call getTemperature() with the ADC value and desired unit:

double tempC = thermistor.getTemperature(adcValue, 'C');

Example de code :

#include <Arduino.h>
#include <Thermistor.h>

// Thermistor configuration
const double Rref = 20000;      // Reference resistance in ohms
const double R0 = 18000;        // Resistance at 25°C in ohms
const double Beta = 3950;       // Beta coefficient
const unsigned samplingBits = 10; // ADC resolution in bits
const int thermistorPin = A1;   // Analog pin for the thermistor

Thermistor thermistor(Rref, R0, Beta, samplingBits);

void setup() {
  Serial.begin(9600);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  int adcValue = analogRead(thermistorPin);
  double tempC = thermistor.getTemperature(adcValue, 'C');
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");
  delay(5000);
}


