/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "http/http.h"
#include "helpers/client_helpers.h"

#ifndef USE_IOT

#include <curl/curl.h>
#include <cstring>
#include <iostream>
#include <sstream>

namespace Ark {
namespace Client {
namespace {

class PlatformHTTP : public AbstractHTTP {
 public:
  PlatformHTTP() = default;

  //////////////////////////////////////////////////////////////////////////////
  std::string get(const char *request) override { return this->send(request); }

  //////////////////////////////////////////////////////////////////////////////
  std::string post(const char *request, const char *body) override {
    return this->send(request, body);
  }

 private:
  //////////////////////////////////////////////////////////////////////////////
  // - https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
  static inline size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                                     void *userp) {
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
  }
  //////////////////////////////////////////////////////////////////////////////
  // Combines GET and POST operations.
  // - https://curl.haxx.se/libcurl/c/https.html
  // - https://curl.haxx.se/libcurl/c/http-post.html
  inline std::string send(const char *request, const char *body = nullptr) {
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl != nullptr) {
      curl_easy_setopt(curl, CURLOPT_URL, request);
      if (body) {
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);
      }

      /* set the header content-type */
      curl_slist *headers = nullptr;
      headers = curl_slist_append(headers, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

      /* skip https verification */
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);  // Do NOT verify peer
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);  // Do NOT verify host

      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

      const CURLcode result = curl_easy_perform(curl);
      if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(result));
      }

      /* always cleanup */
      curl_slist_free_all(headers);
      curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return readBuffer;
  }
};
}  // namespace

////////////////////////////////////////////////////////////////////////////////
// HTTP Object Factory
std::unique_ptr<IHTTP> makeHTTP() {
  return std::unique_ptr<IHTTP>(new PlatformHTTP());
}

}  // namespace Client
}  // namespace Ark

#endif  // USE_IOT
