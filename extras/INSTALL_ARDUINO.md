

# Arduino Builds


### requirements:

**Arduino IDE:**  
Download and install the Arduino IDE (>=1.8.5) from the following link:  
```https://www.arduino.cc/en/Main/Software```

#

### Using with the Arduino IDE
> include the following header in your Arduino Sketch:  
```cpp
#include <arkClient.h>
```

#

### Minimal Arduino Example using the Adafruit Feather ESP8266

```cpp
#include <ESP8266WiFi.h>
#include <arkClient.h>

const char* ssid = "your_network";
const char* password = "your_password";

void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
    Serial.print("\nConnected, IP address: ");
    Serial.println(WiFi.localIP());

    Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.54", 4003);

    Serial.println(arkClient.blockchain.get().c_str());
    Serial.println();

    Serial.println(arkClient.blocks.all().c_str());
    Serial.println();

    Serial.println(arkClient.delegates.all().c_str());
    Serial.println();

    Serial.println(arkClient.delegates.count().c_str());
    Serial.println();

    auto delegatesCount = arkClient.delegates.count();
    Serial.println(delegatesCount.c_str());

    auto allPeers = arkClient.peers.all();
    Serial.println(allPeers.c_str());

    auto allTransactions = arkClient.transactions.all();
    Serial.println(allTransactions.c_str());
}

void loop() {}

```
