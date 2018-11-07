# install PlatformIO
sudo pip install -U platformio

# update PlatformIO
platformio update

# install ArduinoJson (64) and AUnit (2778) libraries
platformio lib -g install 64@5.13.2 2778
