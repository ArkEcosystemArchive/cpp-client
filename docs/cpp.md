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

```cpp
// Create a connection
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

const auto walletsSearch = connection.api.wallets.search({"username", "genesis_1"});
```

> \*note: All API response are of the type `std::string`

#

### Getting an API Path

There are instances when a client may use a gateway or bridge to do http get/post;
for this we have provided an interface for obtaining a properly formatted API Path for a given API Endpoint.
Below are examples of how to access the Path interface:

```cpp
Ark::Client::Host dummyHost("0.0.0.0:4003");

std::string blockchainGetPath = Ark::Client::API::Paths::Blockschain::get(dummyHost);
// blockchainGetPath will be the string "0.0.0.0:4003/api/blockchain"

std::string blocksAllPath = Ark::Client::API::Paths::Blocks::all(dummyHost, 5 /* limit */, 1 /* page */);
// blocksAllPath will be the string "0.0.0.0:4003/api/blocks?limit=5&page=1"

std::string delegatesGetPath = Ark::Client::API::Paths::Delegates::get(dummyHost, "genesis_1");
// delegatesGetPath will be the string "0.0.0.0:4003/api/delegates/genesis_1"

std::string nodeConfigurationPath = Ark::Client::API::Paths::Node::configuration(dummyHost);
// nodeConfigurationPath will be the string "0.0.0.0:4003/api/node/configuration"

std::string peersAllPath = Ark::Client::API::Paths::Peers::all(dummyHost, 5 /* limit */, 1 /* page */);
// peersAllPath will be the string "0.0.0.0:4003/api/peers?limit=5&page=1"

std::string transactionsTypesPath = Ark::Client::API::Paths::Transactions::types(dummyHost);
// transactionsTypesPath will be the string "0.0.0.0:4003/api/transactions/types"

std::string votesGetPath = Ark::Client::API::Paths::Votes::get(dummyHost, "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67");
// votesGetPath will be the string "0.0.0.0:4003/api/votes/a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67"

// the following is an example of formatting a path and body parameters for an http post
const std::map<std::string, std::string> searchBody = {
    {"username", "genesis_1"}
};

std::pair<std::string, std::string> walletsSearchPath = Ark::Client::API::Paths::Wallets::search(testHost, searchBody, 5, 1);
// walletsSearchPath.first will be the string "0.0.0.0:4003/api/wallets/search?limit=5&page=1"
// walletsSearchPath.second will be the string "username=genesis_1"
```

# Arduino

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

    cd cpp-client/
    cmake . && cmake --build .

### run tests
    ./test/Ark-Cpp-Client-tests
