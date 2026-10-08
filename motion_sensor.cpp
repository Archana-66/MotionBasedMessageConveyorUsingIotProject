#include "motion_sensor.h"
#include "config.h"

MotionSensor::MotionSensor(uint8_t sensorPin) : pin(sensorPin), lastTriggerTime(0) {}

void MotionSensor::begin() {
    pinMode(pin, INPUT);
}

bool MotionSensor::checkMotion() {
    int state = digitalRead(pin);
    unsigned long currentTime = millis();

    if (state == HIGH && (currentTime - lastTriggerTime > SENSOR_DEBOUNCE_MS)) {
        lastTriggerTime = currentTime;
        return true;
    }
    return false;
}
