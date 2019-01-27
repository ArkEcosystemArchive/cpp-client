#include "http/http.h"
#include <memory>
#include <vector>
#include "helpers/helpers.h"

#ifdef ESP8266
#include <ESP8266HTTPClient.h>
#else
#include <HTTPClient.h>
#endif

namespace Ark {
namespace Client {
namespace {
/**
 *
 **/
class PlatformHTTP : public AbstractHTTP {
 public:
  PlatformHTTP() = default;

  /**/

    int tryConnection(
        HTTPClient &httpClient,
        const char *const request
    ) {
      if (!httpClient.begin(request))
      { /* Bad HTTP begin */
        return -1;
      }
      int code = httpClient.GET();
      int count = 0;
      while (code != HTTP_CODE_OK)
      { //error
        httpClient.end();
        if (count >=2)
        { /* Bad connection. Try another peer */
          return code;
        };
        /* Bad HTTP GET.\nRetrying connection.. */
        delay(1000);
        httpClient.addHeader("Content-Type", "application/json");
        httpClient.addHeader("API-Version", "2");
        httpClient.begin(request);
        code = httpClient.GET();
        count++;
      }
      return code;
    }

  /**/

    // Arduino's HTTPClient requires that a single-line HTTP request string begins with 'http://'.
    // This is only a consideration on IoT platforms.
    inline std::string toHttpStr(const char *const request) {
      // char[7 (size of char string "http://") + 'request' string-length + 1 (for the null terminator '\0')]
      char httpRequest[7 + std::strlen(request) + 1];
      snprintf(httpRequest, sizeof(httpRequest), "http://%s%c", request, '\0');
      return httpRequest;
    }

    /**/

    std::string get(
        const char *const request
    ) override {
      HTTPClient httpClient;
      httpClient.setReuse(false);
      httpClient.setTimeout(3000);
      if (int code = tryConnection(httpClient, toHttpStr(request).c_str()) != 200)
      { /* error */
        return httpClient.errorToString(-code).c_str(); // <- note `-` symbol.
      }
      return httpClient.getString().c_str();
    }

  /**/

    std::string post(
        const char *const request,
        const char *body
    ) override {
      HTTPClient httpClient;
      httpClient.setReuse(true);
      httpClient.setTimeout(3000);
      httpClient.begin(toHttpStr(request).c_str());
      (body[0] == '{') // set the header content-type
        ? httpClient.addHeader("Content-Type", "application/json")
        : httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");
      httpClient.POST(body);
      return httpClient.getString().c_str();
    }
    /**/
};
/**/
}  // namespace

/**
 * HTTP object factory
 **/
std::unique_ptr<IHTTP> makeHTTP() {
  return std::unique_ptr<IHTTP>(new PlatformHTTP());
}
/**/
}  // namespace Client
}  // namespace Ark
