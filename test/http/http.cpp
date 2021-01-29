
#include "gtest/gtest.h"

#include <array>
#include <string>

#include "http/http_support.hpp"

// Note: These test Http against a live server

namespace {
using namespace Ark::Client;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, get_string) {
  const auto http = DefaultHttp();

  const std::string request = "postman-echo.com/get?foo=bar";
  const auto response = http->get(request);

  ASSERT_LT(response.find("bar"), response.length());
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, https_get) {
  const auto https = DefaultHttp();

  constexpr auto request = "https://postman-echo.com/get?foo=bar";
  const auto response = https->get(request);

  ASSERT_LT(response.find("bar"), response.length());
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, post_body_strings) {
  const auto http = DefaultHttp();

  const std::string request = "postman-echo.com/post";
  const std::string body = "This should be sent back as part of response body.";
  const auto response = http->post(request, body);

  ASSERT_LT(response.find(body), response.length());
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, https_post_body) {  // NOLINT
  const auto https = DefaultHttp();

  constexpr auto request = "https://postman-echo.com/post";
  constexpr auto body = "This should be sent back as part of response body.";

  const auto response = https->post(request, body);

  ASSERT_LT(response.find(body), response.length());
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, invalid_post_body) {
  const auto http = DefaultHttp();

  constexpr auto request = "/167.114.29.55:4003/api/wallets";
  constexpr auto body = R"({"username":"baldninja"})";

  const auto response = http->post(request, body);

  // The malformed request will result in the following error being logged:
  // 'curl_easy_perform() failed: URL using bad/illegal format or missing URL'

  // the response itself will be empty.
  ASSERT_TRUE(response.empty());
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_http, post_json) {
  const auto http = DefaultHttp();

  constexpr auto request = "167.114.29.55:4003/api/transactions";
  constexpr auto txJson = R"({"transactions":[]})";

  const auto response = http->post(request, txJson);

  ASSERT_LT(response.find("422"), response.length());
}

////////////////////////////////////////////////////////////////////////////////
// This tests the use of "http://" in single-line HTTP requests.
TEST(api_http, request_strings) {
  constexpr const size_t HTTPS_MAX_ELEMENTS = 3U;
  std::array<std::string, HTTPS_MAX_ELEMENTS> requests = {
      "postman-echo.com/get",         // No HTTP prefix
      "http://postman-echo.com/get",  // HTTP
      "https://postman-echo.com/get"  // HTTPS
  };

  const auto http = DefaultHttp();

  for (auto& i : requests) {
    const auto response = http->get(i.c_str());
    ASSERT_LT(response.find("args"), response.length());
  };
}
