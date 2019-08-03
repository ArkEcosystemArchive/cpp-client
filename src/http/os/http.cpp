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
namespace {  // NOLINT

class PlatformHTTP : public AbstractHTTP {
 public:
  PlatformHTTP() = default;

  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    // https://curl.haxx.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
  }

  /**/

  std::string get(const char* request) override {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl != nullptr) {
      curl_easy_setopt(curl, CURLOPT_URL, request);

      curl_slist *header_list = nullptr;
      header_list = curl_slist_append(header_list, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

      /* skip https verification */
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      curl_easy_perform(curl);
      curl_slist_free_all(header_list);
      curl_easy_cleanup(curl);
    }
    return readBuffer;
  }

  /**/

  std::string post(const char* request, const char *body) override {
    // https://curl.haxx.se/libcurl/c/http-post.html
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl != nullptr) {
      curl_easy_setopt(curl, CURLOPT_URL, request);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);

      /* set the header content-type */
      curl_slist *header_list = nullptr;
      header_list = curl_slist_append(header_list, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

      /* skip https verification */
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);  // Do NOT verify peer
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);  // Do NOT verify host

      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      };
      /* always cleanup */
      curl_easy_cleanup(curl);
    };
    curl_global_cleanup();
    return readBuffer;
  };
};

}  // namespace

/**
 * HTTP Object Factory
 **/
std::unique_ptr<IHTTP> makeHTTP() {
  return std::unique_ptr<IHTTP>(new PlatformHTTP());
}

}  // namespace Client
}  // namespace Ark

#endif
