#ifndef FAN_h
#define FAN_h

#include <Arduino.h>

class Fan {
public:
    Fan(int pin);
    Fan();

    void setPin(int pin);
    int getPin();
    void task(int deltaTime);

    void turnOn();
    void turnOff();

private:
    int pin;
    uint16 task_acc = 0;
    uint16 task_rate = 5000;
};

#endif
