/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "http/http.h"

#include <memory>
#include <string>

#if defined(ESP8266)
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
using namespace BearSSL;
#endif

#if defined(ESP32)
#include <HTTPClient.h>
#endif

#include "helpers/client_helpers.h"

namespace Ark {
namespace Client {
namespace {

////////////////////////////////////////////////////////////////////////////////
// Supports ESP8266 & ESP32 Boards
class PlatformHTTP : public AbstractHTTP {
 public:
  PlatformHTTP() = default;

  //////////////////////////////////////////////////////////////////////////////
  std::string get(const char* request) override { return this->send(request); }

  //////////////////////////////////////////////////////////////////////////////
  std::string post(const char* request, const char* body) override {
    return this->send(request, body);
  }

 private:
  //////////////////////////////////////////////////////////////////////////////
  inline std::string send(const char* request, const char* body = nullptr) {
    std::unique_ptr<WiFiClientSecure> client(new WiFiClientSecure);
#if defined(ESP8266)
    // skip fingerprint verification on the ESP8266
    // https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/bearssl-client-secure-class.html#setinsecure
    client->setInsecure();
#endif
    HTTPClient https;
    https.setReuse(false);
    https.setTimeout(3000);

    https.addHeader("Content-Type", "application/json");
    https.begin(*client, request);
    body ? https.POST(body) : https.GET();

    const std::string ret = https.getString().c_str();
    https.end();

    return ret;
  }
};
}  // namespace

////////////////////////////////////////////////////////////////////////////////
// HTTP object factory
std::unique_ptr<IHTTP> makeHTTP() {
  return std::unique_ptr<IHTTP>(new PlatformHTTP());
}

}  // namespace Client
}  // namespace Ark
