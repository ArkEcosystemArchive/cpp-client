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
    DynamicJsonBuffer jsonBuffer(response.length());
    JsonObject& obj = jsonBuffer.parseObject(response.c_str());

    // Test JSON object for the "data" key.
    // The correct response will include this key.
    ASSERT_TRUE(obj.containsKey("data"));
}

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
    DynamicJsonBuffer jsonBuffer(response.length());
    JsonObject& obj = jsonBuffer.parseObject(response.c_str());

    // Test JSON object for the "meta" key.
    // The correct response will include this key
    ASSERT_TRUE(obj.containsKey("meta"));
}

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
    DynamicJsonBuffer jsonBuffer(response.length());
    JsonObject& obj = jsonBuffer.parseObject(response.c_str());

    // Test JSON object for the "message" key.
    // The correct response will include the following
    ASSERT_STREQ("should NOT have fewer than 1 items", obj["message"]);
}

// This tests the use of "http://" in single-line HTTP requests.
TEST(api, test_http_request_strings) { // NOLINT

    char requests[3][43] = {
        "167.114.29.55:4003/api/node/status",        // No HTTP
        "http://167.114.29.55:4003/api/node/status", // HTTP
        "https://167.114.29.55:4003/api/node/status" // HTTPS
    };

    // Create the HTTP object
    const auto http = Ark::Client::makeHTTP();

    for (int i = 0; i < 3; ++i) {
        // Get the response using HTTP
        const auto response = http->get(requests[i]);

        // Create a JSON object of the result
        DynamicJsonBuffer jsonBuffer(response.length());
        JsonObject& obj = jsonBuffer.parseObject(response.c_str());

        // Test JSON object for the "data" key.
        // HTTPS is NOT supported and should fail to parse.
        if (std::string(requests[i]).find("https://") == 0) { 
            ASSERT_FALSE(obj.containsKey("data"));
        } else {
            ASSERT_TRUE(obj.containsKey("data"));
        };
    }
}

TEST(api, test_http_version) { // NOLINT
    // Create the HTTP object
    const auto http = Ark::Client::makeHTTP();

    // The default 'api_version' of an unconfigured 'HTTP' object is '0'.
    ASSERT_EQ(0, http->api_version());
}
