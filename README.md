# ESP32-BME280-Blynk
Simple arduino script that sends temperature, humidity, pressure and altitude to Blynk.cloud

# Setup #
1. Setup a template on Blynk.cloud
2. Add 4 datastreams
  - V0 = Temp (Double °C)
  - V1 = Pressure (Double Pa)
  - V2 = Altitude (Double m)
  - V3 = Humidity (Integer %)
3. Configure web dashboard to your liking
4. Create device
5. Change device auth token, device name and template id in the script
6. Change the SSID and password in the script
7. Upload script
8. Enjoy
