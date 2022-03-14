#include <Arduino.h>
#include "Thermometre.h"
#include "Fan.h"

#define LED D0
#define FAN_PIN D1
#define TEMP_PIN D2

long currentTime = 0;
long previousTime = 0;
int deltaTime = 0;

uint16 heart_acc = 0;
uint16 heart_rate = 2000;

Thermometre thermometre(TEMP_PIN);
Fan fan(FAN_PIN);

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(TEMP_PIN, INPUT_PULLUP);
  pinMode(FAN_PIN, OUTPUT); 

  thermometre.forceRead();

  Serial.print(F("Temperature: "));
  Serial.println(thermometre.getTemperature());

  currentTime = millis();
  previousTime = currentTime;
}

void HeartBeatTask(int deltaTime) {
  heart_acc += deltaTime;

  if (heart_acc < heart_rate) return;

  heart_acc = 0;
  
  Serial.print(F("Heartbeat task"));
}

float lowerLimit = 22.0;
float upperLimit = 25.0;

void loop() {
  currentTime = millis();
  deltaTime = currentTime - previousTime;
  previousTime = currentTime;

  thermometre.task(deltaTime);
  float temp = thermometre.getTemperature();

  if (temp < lowerLimit) {
    fan.turnOff();
  } else if (temp > upperLimit) {
    fan.turnOn();
  }  
}