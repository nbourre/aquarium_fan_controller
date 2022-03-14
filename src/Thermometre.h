
#ifndef Thermometre_h
#define Thermometre_h

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4

class Thermometre {
public:
    Thermometre(int pin);
    Thermometre();

    float getTemperature();
    float forceRead();
    void setTemperature(float temperature);
    void setPin(int pin);
    int getPin();
    void task(int deltaTime);

private:
    int pin;
    float temperature;
    float lastReading;

    OneWire oneWire;
    DallasTemperature sensor;

    uint16 task_acc = 0;
    uint16 task_rate = 5000;
};

#endif