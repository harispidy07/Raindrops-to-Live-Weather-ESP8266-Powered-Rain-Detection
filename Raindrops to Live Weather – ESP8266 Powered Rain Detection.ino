#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>

const char* ssid  = "YOUR_WIFI";
const char* pass  = "YOUR_PASSWORD";
const char* topic = "YOUR_TOPIC";

KiwisIoT kiwisiot(ssid, pass, topic);

#define DHTPIN D4
#define DHTTYPE DHT11
#define RAIN_PIN A0
#define LED_PIN D5

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bmp;

float temperature;
float humidity;
float pressure;
int rainValue;

const int RAIN_THRESHOLD = 500;

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();
  Wire.begin(D2, D1);

  if (!bmp.begin(0x76))
  {
    Serial.println("BMP280 not detected!");
    while (1)
    {
      delay(100);
    }
  }

  kiwisiot.begin();
}

void loop()
{
  kiwisiot.run();

  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  pressure = bmp.readPressure() / 100.0;
  rainValue = analogRead(RAIN_PIN);

  if (rainValue < RAIN_THRESHOLD)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }

  Serial.println("----------------------");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Rain sensor raw value: ");
  Serial.println(rainValue);

  if (!isnan(temperature) && !isnan(humidity))
  {
    kiwisiot.send("1", String(temperature));
    kiwisiot.send("2", String(humidity));
  }

  kiwisiot.send("3", String(pressure));
  kiwisiot.send("4", String(rainValue));

  delay(2000);
}