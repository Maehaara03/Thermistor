#include "thermistor.h"
#include <math.h>

Thermistor::Thermistor(double Rref, double R0, double Beta,
                       unsigned samplingBitsNumber, double Vcc, double T0)
{
    this->Rref = Rref;
    this->R0 = R0;
    this->Beta = Beta;
    this->samplingBitsNumber = samplingBitsNumber;
    this->Vcc = Vcc;
    this->T0 = T0;
}

double Thermistor::getTemperature(double adc, char unit)
{
    // Nombre maximal possible pour l'ADC : 2^n - 1
    double Adc = pow(2, samplingBitsNumber) - 1;

    // Appliquer directement la formule générale de la température en Kelvin
    double tempK = 1.0 / ((1.0 / T0) +
                          (1.0 / Beta) * log((R0 * (Adc / adc - 1)) / Rref));
    // Convertir en Celsius
    if (unit == 'C')
    {
        return tempK - ZERO_CELSIUS;
    }
    else if (unit == 'F')
    {
        return (tempK - ZERO_CELSIUS) * 9 / 5 + 32; // Convertir en Fahrenheit
    }

    return tempK; // Retourner la température en Kelvin par défaut
}