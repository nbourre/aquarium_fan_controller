#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Thermometre.h"

Thermometre::Thermometre(int pin){
    pinMode(pin, INPUT_PULLUP);
    oneWire.begin(pin);
    sensor.setOneWire(&oneWire);
}

Thermometre::Thermometre(){
    pinMode(pin, INPUT_PULLUP);
    oneWire.begin(ONE_WIRE_BUS);
    sensor.setOneWire(&oneWire);
}

void Thermometre::task(int deltaTime){

    task_acc += deltaTime;

    if (task_acc < task_rate) return;

    task_acc = 0;

    

    sensor.requestTemperatures();
    lastReading = sensor.getTempCByIndex(0);

    Serial.print(F("Temperature task : "));
    Serial.println(lastReading);
}

float Thermometre::getTemperature(){

  return lastReading;
  
}

float Thermometre::forceRead(){

    sensor.requestTemperatures();
    lastReading = sensor.getTempCByIndex(0);

    return lastReading;
}