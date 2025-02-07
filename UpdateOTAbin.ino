#include <Arduino.h>
#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

#include <GyverHub.h>
GyverHub hub("MyDevices", "Updater");

void setup() {
  IPAddress apIP(192, 168, 4, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, subnet);
  WiFi.softAP("Updater");

  hub.onBuild(build);
  hub.begin();
}

void loop() {
  hub.tick();
}

void build(gh::Builder& b) {
  b.Title(F("нажми меню и загрузи прошивку, OTA")).fontSize(15);
}