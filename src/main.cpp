#include <Arduino.h>
#include "thermistor.h"

// Configuration de la thermistance
const double Rref = 20000;      // Résistance de référence en ohms
const double R0 = 18000;        // Résistance à 25°C en ohms
const double Beta = 3950;      // Coefficient Beta 
const unsigned samplingBits = 10; // Bits du convertisseur ADC
const int thermistorPin = A1;  // Broche analogique pour la lecture

Thermistor thermistor(Rref, R0, Beta, samplingBits);

void setup() {
  Serial.begin(9600);
  pinMode(thermistorPin, INPUT);
}

void loop() {
  // Lecture de la valeur ADC
  int adcValue = analogRead(thermistorPin);
  
  // Conversion en température
  double tempC = thermistor.getTemperature(adcValue, 'C');
  
  // Affichage des résultats
  Serial.print("Valeur ADC : ");
  Serial.println(adcValue);
  Serial.print("Température : ");
  Serial.print(tempC);
  Serial.println(" °C");
  
  delay(5000); // Mesure toutes les 5 secondes
}