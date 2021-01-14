/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HTTP_IMPL_IOT_ESPRESSIF
#define HTTP_IMPL_IOT_ESPRESSIF

#include "helpers/client_helpers.h"

#ifdef USE_IOT

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

#include "http/http_support.hpp"

namespace Ark {
namespace Client {
namespace {

////////////////////////////////////////////////////////////////////////////////
// Supports ESP8266 & ESP32 Boards
class HttpImpl : public AbstractHttp {
 public:
  HttpImpl() = default;

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  std::string get(const char *request) override { return this->send(request); }

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  std::string post(const char *request, const char *body) override {
    const std::string request_(request);
    const std::string body_(body);

    return this->send(request_, body_);
  }

  //////////////////////////////////////////////////////////////////////////////
  std::string get(const std::string &request) override {
    return this->send(request);
  }

  //////////////////////////////////////////////////////////////////////////////
  std::string post(const std::string &request,
                   const std::string &body) override {
    return this->send(request, body);
  }

 private:
  //////////////////////////////////////////////////////////////////////////////
  inline std::string send(const std::string &request,
                          const std::string &body = nullptr) {
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
    https.begin(*client, request.c_str());
    body ? https.POST(body) : https.GET();

    const std::string ret = https.getString().c_str();
    https.end();

    return ret;
  }
};
}  // namespace

////////////////////////////////////////////////////////////////////////////////
// HTTP Object Factory
std::unique_ptr<IHttp> DefaultHttp() {
  return std::unique_ptr<IHttp>(new HttpImpl());
}

}  // namespace Client
}  // namespace Ark

#endif  // USE_IOT
#endif  // HTTP_IMPL_IOT_ESPRESSIF
