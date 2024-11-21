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
    // Maximum possible value for the ADC: 2^n - 1
    double Adc = pow(2, samplingBitsNumber) - 1;

    // Directly apply the general formula for temperature in Kelvin
    double tempK = 1.0 / ((1.0 / T0) +
                          (1.0 / Beta) * log((R0 * (Adc / adc - 1)) / Rref));
    // Convert to Celsius
    if (unit == 'C')
    {
        return tempK - ZERO_CELSIUS;
    }
    else if (unit == 'F')
    {
        return (tempK - ZERO_CELSIUS) * 9 / 5 + 32; // Convert to Fahrenheit
    }

    return tempK; // Return temperature in Kelvin by default
}
