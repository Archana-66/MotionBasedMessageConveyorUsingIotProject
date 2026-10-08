#ifndef CONFIG_H
#define CONFIG_H

#define PIR_PIN D5
#define BUZZER_PIN D6

#define LCD_I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

#define MQTT_SERVER "broker.hivemq.com"
#define MQTT_PORT 1883
#define MQTT_TOPIC_NOTIFY "iot/conveyor/motion"

#define SENSOR_DEBOUNCE_MS 3000
#define DISPLAY_TIMEOUT_MS 5000

#endif
