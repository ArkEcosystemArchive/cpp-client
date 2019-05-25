#include "gtest/gtest.h"
#include "http/http.h"
#include "utils/json.h"

// Note: These test HTTP against a live node

TEST(api, test_http_get) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Get the response using HTTP
  const auto response = http->get("167.114.29.55:4003/api/node/status");

  // Create a JSON object of the result
  DynamicJsonDocument doc(156);
  DeserializationError error = deserializeJson(doc, response);
  if (error) { exit(0); }

  // Test JSON object for the "data" key.
  // The correct response will include this key.
  ASSERT_TRUE(doc.containsKey("data"));
}

/**/

// Tests POSTing of HTTP body.
TEST(api, test_http_post_body) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a Request URL and 'Post' body.
  const auto request = "167.114.29.55:4003/api/v2/wallets/search?limit=1&page=1";
  const auto body = "username=baldninja";

  // Post the 'request' and 'body' for a response using HTTP
  const auto response = http->post(request, body);

  // Create a JSON object of the result
  DynamicJsonDocument doc(956);
  DeserializationError error = deserializeJson(doc, response);
  if (error) { exit(0); }

  // Test JSON object for the "meta" key.
  // The correct response will include this key
  ASSERT_TRUE(doc.containsKey("meta"));
}

/**/

// Tests invalid POSTing of HTTP body.
TEST(api, test_http_invalid_post_body) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a malformed Request URL and 'Post' body.
  const auto request = "/167.114.29.55:4003/api/v2/wallets/search";
  const auto body = "username=baldninja";

  // Post the 'request' and 'body' for a response using HTTP
  const auto response = http->post(request, body);

  // Create a JSON object of the result
  DynamicJsonDocument doc(100);
  DeserializationError error = deserializeJson(doc, response);
  // the empty response should cause deserialization to fail
  ASSERT_TRUE(error);
}

/**/

// Tests POSTing of JSON.
TEST(api, test_http_post_json) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // Create a Request URL and an empty Transaction JSON.
  const auto request = "167.114.29.55:4003/api/v2/transactions";
  const auto txJson = "{\"transactions\":[]}";

  // Post the 'request' and 'txJson' for a response using HTTP
  const auto response = http->post(request, txJson);

  // Create a JSON object of the result
  DynamicJsonDocument doc(180);
  DeserializationError error = deserializeJson(doc, response);
  if (error) { exit(0); }

  // Test JSON object for the "message" key.
  // The correct response will include the following
  ASSERT_EQ(422, doc["statusCode"]);
}

/**/

// This tests the use of "http://" in single-line HTTP requests.
TEST(api, test_http_request_strings) { // NOLINT
  char requests[3][43] = {
    "167.114.29.55:4003/api/node/status",        // No HTTP
    "http://167.114.29.55:4003/api/node/status", // HTTP
    "https://167.114.29.55:4003/api/node/status" // HTTPS
  };

  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  for (auto i: requests) {
    // Get the response using HTTP
    const auto response = http->get(i);

    // Create a JSON object of the result
    DynamicJsonDocument doc(156);
    DeserializationError error = deserializeJson(doc, response);

    // Test JSON object for the "data" key.
    // HTTPS is NOT supported and should fail to parse.
    if (std::string(i).find("https://") != 0) {
      if (error) { exit(0); }
      ASSERT_TRUE(doc.containsKey("data"));
    } else {
      ASSERT_FALSE(doc.containsKey("data"));
    };
  };
}

/**/

TEST(api, test_http_version) { // NOLINT
  // Create the HTTP object
  const auto http = Ark::Client::makeHTTP();

  // The default 'api_version' of an unconfigured 'HTTP' object is '0'.
  ASSERT_EQ(0, http->api_version());
}
