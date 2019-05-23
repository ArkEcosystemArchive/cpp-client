#if (defined PLATFORMIO && defined UNIT_TEST)

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <Arduino.h>

void setup() {
  Serial.begin(115200);

  testing::InitGoogleMock();

  auto __attribute__((unused)) run = RUN_ALL_TESTS();
}

void loop() {
  // do nothing
}

#endif
