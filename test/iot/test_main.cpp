#if (defined PLATFORMIO && defined UNIT_TEST)

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Arduino.h>

// Connecting to WiFi is optional for testing.
#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#endif
#ifdef ESP32
#include <WiFi.h>
#endif
// This is the WiFi network you'd like your board to connect to.
const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";

/**/

void setup() {
  Serial.begin(115200);

#if defined(ESP8266) || defined(ESP32)
  // if ssid and passwd set
  if (strcmp(ssid, "yourSSID") != 0 && strcmp(password, "yourWiFiPassword") != 0) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    };
    Serial.println();
    Serial.println(WiFi.localIP());
  };
#endif

  testing::InitGoogleMock();

  auto __attribute__((unused)) run = RUN_ALL_TESTS();
}

void loop() {
  // do nothing
}

#endif
