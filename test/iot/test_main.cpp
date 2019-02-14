#if (defined PLATFORMIO && defined UNIT_TEST)

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Arduino.h>

void setup() {
    Serial.begin(115200);
	while (!Serial); // for the Arduino Leonardo/Micro only
	delay(100);
  testing::InitGoogleMock();
	delay(1000);

  RUN_ALL_TESTS();
}

void loop() {
  // do nothing
  delay(1000);
}

#endif
