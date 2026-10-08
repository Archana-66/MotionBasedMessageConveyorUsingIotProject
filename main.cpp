#include <Arduino.h>
#include "config.h"
#include "motion_sensor.h"
#include "display_manager.h"
#include "iot_manager.h"

MotionSensor sensor(PIR_PIN);
DisplayManager display;
IoTManager iot;

void setup() {
    Serial.begin(115200);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

    sensor.begin();
    display.begin();
    iot.begin();
}

void loop() {
    iot.loop();

    if (sensor.checkMotion()) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(100);
        digitalWrite(BUZZER_PIN, LOW);

        display.showMessage("MOTION DETECTED", "Welcome User!");
        iot.publishNotification("{\"event\":\"motion_detected\"}");

        delay(DISPLAY_TIMEOUT_MS);
        display.showMessage("System Ready", "Awaiting Motion");
    }
}
