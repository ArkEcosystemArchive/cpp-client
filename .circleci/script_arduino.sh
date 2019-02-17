#!/usr/bin/env bash

bash ./extras/ARDUINO_IDE.sh --auto

mkdir -p ~/Arduino/libraries/cpp-client/
mv ~/project/* ~/Arduino/libraries/cpp-client

arduino-cli compile --output temp.bin -b esp32:esp32:esp32 ~/Arduino/libraries/cpp-client/examples/ESP32/ESP32.ino --debug
