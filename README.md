# Raindrops to Live Weather – ESP8266 Powered Rain Detection

## Project Overview

This project detects rainfall using an ESP8266 NodeMCU and a rain sensor module. It monitors rain conditions and transmits sensor readings to the KiwisIoT platform for real-time remote monitoring, helping users identify rainfall activity.

## Hardware Components

- ESP8266 NodeMCU
- Rain Sensor Module
- Jumper Wires
- Breadboard
- USB Cable
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library

## Circuit Connections

| Rain Sensor Module  | ESP8266 NodeMCU |
| ------------------- | --------------- |
| VCC                 | 3.3V            |
| GND                 | GND             |
| Digital Output (DO) | D5              |

## Working Principle

The rain sensor detects water droplets on its sensing surface and generates an output signal based on rainfall conditions. The ESP8266 reads the sensor output and sends the rain detection status to the KiwisIoT platform, allowing users to monitor rainfall activity remotely.

## KiwisIoT Dashboard

| Data           | Description                      |
| -------------- | -------------------------------- |
| Rain Detection | Rain detected / No rain          |
| Rain Status    | Current rainfall condition       |
| Monitoring     | Real-time rain detection updates |

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor rainfall conditions through the KiwisIoT dashboard.

## Applications

- Rainfall detection systems
- Smart weather monitoring
- Automatic irrigation systems
- Smart agriculture
- Outdoor environmental monitoring
- Weather-based automation

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/raindrops-to-live-weather-esp8266-powered-rain-detection-4aad13](https://www.hackster.io/harispidy07/raindrops-to-live-weather-esp8266-powered-rain-detection-4aad13)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266, Rain Sensor, and KiwisIoT for real-time rainfall detection and monitoring._
