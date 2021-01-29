---
title: "Cpp"
---

# Cpp

::: warning
This package is still under development. This page will get more content as it evolves more. In the meantime you can view its source on [Github](https://github.com/ArkEcosystem/cpp-client/).
:::

[[toc]]

## Platforms

- [Arduino](#Arduino)
- [Linux >= 16.04](#OS)
- [macOS >= 10.10](#OS)
- [Windows >= 7](#OS)

## Usage

The Cpp Client is meant to be used for creating request to an API endpoint.
For cryptography related functionality, such as generating addresses or creating transactions,
please see the [Cpp Crypto](https://github.com/ArkEcosystem/cpp-crypto) repository.

### Connection

Before making a request, you should create a `Connection`.
A `Connection` expects a `host`, which is an url on which the API can be reached.
An example `Connection`, that interfaces with the API of an Ark Node, would be created as follows:

#### Create a connection using the default peer ("https://dwallets.ark.io") and http implementation.
```cpp
Ark::Client::Connection<Ark::Client::Api> connection;
```

#### Create a connection using a custom peer and the default http implementation.
```cpp
Ark::Client::Connection<Ark::Client::Api> connection("https://wallets.ark.io");
```

#### Create a connection using a custom peer and a custom http implementation.
```cpp
#include <memory>
#include <string>

////////////////////////////////////////////////////////////////////////////////
class SomeHttp : public AbstractHttp {
 public:
  SomeHttp() = default;

  std::string get(const std::string &request) override { ... }
  std::string post(const std::string &request,
                   const std::string &body) override { ... }

  std::string get(const char* request) override { ... }
  std::string post(const char* request, const char* body) override { ... }
};

// forward declaration
std::unique_ptr<IHttp> someNewHttp();

////////////////////////////////////////////////////////////////////////////////
// in the definition file (*.cpp)
std::unique_ptr<IHttp> someNewHttp() {
  return std::unique_ptr<IHttp>(new SomeHttp());
}

////////////////////////////////////////////////////////////////////////////////
Ark::Client::Connection<Ark::Client::Api> connection("https://wallets.ark.io", someNewHttp());
```

#### Create a connection using a peer Ip and a port using the systems default http implementation.
```cpp
// !DEPRECATED
Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.54", 4003);
```

### Making an API Request

The below example shows how you can perform a request.

```cpp
// Perform an API call using the connection to access endpoint
const auto blockchainResponse = connection.api.blockchain.get();

const auto blockResponse = connection.api.blocks.get("13114381566690093367")

const auto delegateResponse = connection.api.delegates.get("genesis_1");

const auto nodeConfiguration = connection.api.node.configuration();

const auto peer = connection.api.peers.get("167.114.29.49");

const auto transaction = connection.api.transactions.get("ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4");

const auto vote = connection.api.votes.get("a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67");

const auto wallets = connection.api.wallets.get("genesis_1");
```

> \*note: All API response are of the type `std::string`

# Arduino

**Arduino IDE:**
Download and install the Arduino IDE (>=1.8.5) from the following link:
`https://www.arduino.cc/en/Main/Software`

#### Minimal Arduino Example using the Adafruit Feather ESP8266

```Arduino
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

    auto allBlocks = arkClient.blocks.all();
    Serial.println(allBlocks.c_str());

    auto allDelegates = arkClient.delegates.all();
    Serial.println(allDelegates.c_str());

    auto delegatesCount = arkClient.delegates.count();
    Serial.println(delegatesCount.c_str());

    auto allPeers = arkClient.peers.all();
    Serial.println(allPeers.c_str());

    auto allTransactions = arkClient.transactions.all();
    Serial.println(allTransactions.c_str());
}

void loop() {}

```

**PlatformIO IDE:**

#### Python:

Use an installer package from the following link or use your preferred method to install Python:
`https://www.python.org/downloads/`

Install PlatformIO:

    pip install -U platformio

or

    python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"

Install AUnit (2778)

    platformio lib -g install 2778

#### Provide your WiFi info for your board to access the internet

Open the following file in your preferred code editor:

> "_.../cpp-client/test/IoT/test_main.cpp_"

lines 19 & 20:

```
char ssid[] = "your_ssid";     //  your network SSID (name)
const char password[] = "your_password";  // your network password
```

#### running the tests on an Arduino board

    cd Cpp-Client
    cd test

#### execute the following command to upload test to your board

> | board   | command                        |
> | :------ | :----------------------------- |
> | ESP8266 | `pio run -e esp8266 -t upload` |
> | ESP32   | `pio run -e esp32 -t upload`   |

#

# OS

## Linux, macOS and Windows

**CMake:**

Use an installer package from the following link, Homebrew, or use your preferred method:
`https://www.cmake.org/download/`

using
**Homebrew:**

    brew install cmake

> note: all other dependencies will be automatically installed via git submodule and CMake.

### make and build

    mkdir build && cd build
    cmake -DUNIT_TEST ..
    cmake --build .

### run tests

    ./test/ark_cpp_client_tests
