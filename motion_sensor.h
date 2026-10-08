#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include <Arduino.h>

class MotionSensor {
private:
    uint8_t pin;
    unsigned long lastTriggerTime;

public:
    MotionSensor(uint8_t sensorPin);
    void begin();
    bool checkMotion();
};

#endif
