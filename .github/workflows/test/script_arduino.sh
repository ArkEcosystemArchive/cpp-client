#!/usr/bin/env bash

bash ./extras/ARDUINO_IDE.sh --auto

mkdir -p ~/Arduino/libraries/cpp-client/
mv ${GITHUB_WORKSPACE}/* ~/Arduino/libraries/cpp-client

arduino-cli compile --output temp.bin -b esp32:esp32:esp32 ~/Arduino/libraries/cpp-client/examples/arduino/ESP32/ESP32.ino --debug

arduino-cli compile --output temp.bin -b esp8266:esp8266:nodemcu ~/Arduino/libraries/cpp-client/examples/arduino/ESP8266/ESP8266.ino --debug
