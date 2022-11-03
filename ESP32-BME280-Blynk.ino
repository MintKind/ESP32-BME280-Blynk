#define BLYNK_TEMPLATE_ID "xxx" // Your Blynk TEMPLATE_ID
#define BLYNK_DEVICE_NAME "xxx" // Your Blynk DEVICE_NAME
#define BLYNK_AUTH_TOKEN "xxx" // Your Blynk AUTH_TOKEN

#include <WiFi.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
char ssid[] = "xxx";
char pass[] = "xxx";

BlynkTimer timer;

Adafruit_BME280 bme;
#define SEALEVELPRESSURE_HPA (1013.25)
float temperature, humidity, pressure, altitude;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  bme.begin(0x76);  
  timer.setInterval(100L, sendBlynk);
}

void sendBlynk() {
  temperature = bme.readTemperature();
  humidity = bme.readHumidity();
  pressure = bme.readPressure() / 100.0F;
  altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, pressure);
  Blynk.virtualWrite(V2, altitude);
  Blynk.virtualWrite(V3, humidity);
  delay(2000);
}

void loop()
{
  Blynk.run();
  timer.run();
  
}
