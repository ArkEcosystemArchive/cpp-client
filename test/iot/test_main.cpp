

#if (defined PLATFORMIO && defined UNIT_TEST)

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#if (defined ESP8266 || defined ESP32)

#ifdef ESP8266

#include <ESP8266WiFi.h>

#else

#include <WiFi.h>

#endif // ESP8266

namespace
{

char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password

void setup_network()
{
	Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
        would try to act as both a client and an access-point and could cause
        network-issues with your other WiFi-devices on your WiFi-network. */
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

}

#else

namespace
{

void setup_network() {}

}

#endif

void setup() {
    Serial.begin(115200);
	while (!Serial); // for the Arduino Leonardo/Micro only
	delay(100);
	setup_network();
  testing::gmock_setup();
	delay(1000);
}

void loop() {
  testing::gmock_loop();
}

#endif
