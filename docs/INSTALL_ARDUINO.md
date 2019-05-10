

# Arduino Builds


### requirements:

**Arduino IDE:**  
Download and install the Arduino IDE (>=1.8.5) from the following link:  
```https://www.arduino.cc/en/Main/Software```

#

### dependencies:

Using the Arduino IDE's built in Library Manager,  
install the following Libraries  
- ArduinoJson v6.10.1
- AUnit

#

### Using with the Arduino IDE
> include the following header in your Arduino Sketch:  
```cpp
#include <arkClient.h>
```

#

### Arduino Example using the Adafruit Feather ESP8266

```cpp
#include <arkClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "your_network";
const char* password = "your_password";

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.print("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

  Ark::Client::Connection<Ark::Client::Api> connection(CustomNetwork);

  Serial.println(arkClient.blocks.all().c_str());
  Serial.println();
  
  Serial.println(arkClient.delegates.all().c_str());
  Serial.println();
  
  Serial.println(arkClient.delegates.count().c_str());
  Serial.println();
  
  Serial.println(arkClient.peers.all().c_str());
  Serial.println();
  
  Serial.println(arkClient.transactions.all().c_str());
  Serial.println();

}

void loop() {}
```
