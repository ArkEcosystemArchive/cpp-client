#include "gtest/gtest.h"

#include "http/http.h"

// Note: These test HTTP against a live server

#include <iostream>

TEST(api, test_http_get) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a request
  const auto request = "postman-echo.com/get?foo=bar";

  // Get the response using HTTP
  const auto response = http->get(request);

  ASSERT_LT(response.find("bar"), response.length());
}

/**/

// Tests POSTing of HTTP body.
TEST(api, test_http_post_body) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a Request URL and 'Post' body.
  const auto request = "postman-echo.com/post";
  const auto body = "This should be sent back as part of response body.";

  // Post the 'request' and 'body' for a response using HTTP
  const auto response = http->post(request, body);

  ASSERT_LT(response.find(body), response.length());
}

/**/

// Tests invalid POSTing of HTTP body.
TEST(api, test_http_invalid_post_body) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a malformed Request URL and 'Post' body.
  const auto request = "/167.114.29.55:4003/api/wallets/search";
  const auto body = "{\"username\":\"baldninja\"}";

  // Post the 'request' and 'body' for a response using HTTP
  const auto response = http->post(request, body);

  // The malformed request will result in the following error being logged:
  // 'curl_easy_perform() failed: URL using bad/illegal format or missing URL'
  
  // the response will be empty
  ASSERT_TRUE(response.empty());
}

/**/

// Tests POSTing of JSON.
TEST(api, test_http_post_json) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a Request URL and an empty Transaction JSON.
  const auto request = "167.114.29.55:4003/api/transactions";
  const auto txJson = "{\"transactions\":[]}";

  // Post the 'request' and 'txJson' for a response using HTTP
  const auto response = http->post(request, txJson);

  ASSERT_LT(response.find("422"), response.length());
}

/**/

// This tests the use of "http://" in single-line HTTP requests.
TEST(api, test_http_request_strings) { // NOLINT
  char requests[3][43] = {
    "postman-echo.com/get",         // No HTTP prefix
    "http://postman-echo.com/get",  // HTTP
    "https://postman-echo.com/get"  // HTTPS
  };

  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  for (auto& i: requests) {
    // Get the response using HTTP
    const auto response = http->get(i);
#ifdef USE_IOT 
    // HTTPS is NOT supported on IoT and should fail to parse.
    response.find("https://") < response.length())
        ? ASSERT_TRUE(response.empth())
        : ASSERT_LT(response.find("args"), response.length());
#else // OS Builds
    ASSERT_LT(response.find("args"), response.length());
#endif
  };
}
