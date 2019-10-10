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
#include <vector>
#include "helpers/client_helpers.h"

#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#else
#include <HTTPClient.h>
#endif

namespace Ark {
namespace Client {
namespace {

class PlatformHTTP : public AbstractHTTP {
 public:
  PlatformHTTP() = default;

  int tryConnection(HTTPClient &httpClient, const char* request ) {
    if (!httpClient.begin(request)) {
      return -1;
    };
    int code = httpClient.GET();
    int count = 0;
    while (code != HTTP_CODE_OK) {
      httpClient.end();
      if (count >=2) {
        return code;
      };
      delay(1000);
      httpClient.addHeader("Content-Type", "application/json");
      httpClient.begin(request);
      code = httpClient.GET();
      count++;
    }
    return code;
  }

  /**/

  // Arduino's HTTPClient requires that a single-line HTTP request string begins with 'http://'.
  // This is only a consideration on IoT platforms.
  inline std::string toHttpStr(const char* request) {
    // char[7 (size of char string "http://") + 'request' string-length + 1 (for the null terminator '\0')]
    size_t length = 0;
    while (request[length] != 0) { length++; };
    char httpRequest[7 + length + 1];
    snprintf(httpRequest, length, "http://%s%c", request, '\0');
    return httpRequest;
  }

  /**/

  std::string get(const char* request) override {
    HTTPClient httpClient;
    httpClient.setReuse(false);
    httpClient.setTimeout(3000);
    if (int code = tryConnection(httpClient,
                                 toHttpStr(request).c_str()) != 200) {
      return httpClient.errorToString(-code).c_str(); // <- note `-` symbol.
    }
    return httpClient.getString().c_str();
  }

  /**/

  std::string post(const char* request, const char *body) override {
    HTTPClient httpClient;
    httpClient.setReuse(true);
    httpClient.setTimeout(3000);
    httpClient.begin(toHttpStr(request).c_str());
    httpClient.addHeader("Content-Type", "application/json");
    httpClient.POST(body);
    return httpClient.getString().c_str();
  }
};

}  // namespace

/**
 * HTTP object factory
 **/
std::unique_ptr<IHTTP> makeHTTP() {
  return std::unique_ptr<IHTTP>(new PlatformHTTP());
}

}  // namespace Client
}  // namespace Ark
