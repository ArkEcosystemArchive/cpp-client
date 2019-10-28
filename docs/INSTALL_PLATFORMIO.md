

# PlatformIO

### dependencies

**Python:**  
Use an installer package from the following link:  
```https://www.python.org/downloads/```

#

**PlatformIO:**  
install PlatformIO if not already installed  
```pip install -U platformio```  
or  
```python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"```


also install platformio dependencies:  
> install AUnit (2778)
```platformio lib -g install 2778```

#  

### provide your WiFi info for your board to access the internet   

**open the following file in your preferred code editor:**  

> "*.../cpp-client/test/IoT/test_main.cpp*"  


lines 19 & 20:  
```
char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password
```

#

### running the tests on an Arduino board

**`cd` into this directory "*.../Cpp-Client/test*"**  
> ```cd test```

**execute the following command to upload test to your board**  

>| board | command |
>|:-- |:-- |
>| ESP8266 | ```pio run -e esp8266 -t upload``` |
>| ESP32 | ```pio run -e esp32 -t upload``` |
