#include "Fan.h"

Fan::Fan(int pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

void Fan::setPin(int pin) {
  this->pin = pin;
}

void Fan::task(int deltaTime) {
  task_acc += deltaTime;

  if (task_acc < task_rate) return;

  task_acc = 0;

  Serial.print(F("Fan task"));

}

void Fan::turnOn() {
  digitalWrite(pin, HIGH);
}

void Fan::turnOff() {
  digitalWrite(pin, LOW);
}