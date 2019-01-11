
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;
using testing::_;

/* test_two_peers_peer
 * https://dexplorer.ark.io:8443/api/v2/peers/167.114.29.54
 * Expected Response:
    {
    "data": {
        "ip": "string",
        "port": int,
        "version": "string",
        "status": "string",
        "os": "string",
        "latency": int
    }
    }
 */
TEST(api, test_two_peer) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.54", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "data": {
            "ip": "167.114.29.55",
            "port": 4002,
            "version": "1.1.1",
            "status": 200,
            "os": "linux",
            "latency": 355
        }
    })";

    EXPECT_CALL(connection.api.peers, get(_))
      .Times(1)
      .WillOnce(Return(response));

    const auto peer = connection.api.peers.get("167.114.29.49");

    DynamicJsonBuffer jsonBuffer(peer.size());
    JsonObject& root = jsonBuffer.parseObject(peer);

    JsonObject& data = root["data"];

    const char* ip = data["ip"];
    ASSERT_STREQ("167.114.29.55", ip);

    int port = data["port"];
    ASSERT_EQ(4002, port);

    const char* version = data["version"];
    ASSERT_STREQ("1.1.1", version);

    int status = data["status"];
    ASSERT_EQ(200, status);

    const char* os = data["os"];
    ASSERT_STREQ("linux", os);

    int latency = data["latency"];
    ASSERT_EQ(355, latency);
}

/* test_peers_peers
 * https://dexplorer.ark.io:8443/api/v2/peers?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/peers?limit=5&page=1",
        "first": "/api/v2/peers?limit=5&page=1",
        "last": "/api/v2/peers?limit=5&page=1"
    },
    "data": [
        {
        "ip": "string",
        "port": "string",
        "version": "string",
        "status": "string",
        "os": "string",
        "latency": int
        }
    ]
    }
 */
TEST(api, test_two_peers) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "meta": {
            "count": 2,
            "pageCount": 1,
            "totalCount": 2,
            "next": null,
            "previous": null,
            "self": "/v2/peers?page=1",
            "first": "/v2/peers?page=1",
            "last": "/v2/peers?page=1"
        },
        "data": [
            {
                "ip": "167.114.29.53",
                "port": 4002,
                "version": "1.1.1",
                "status": 200,
                "os": "linux",
                "latency": 1390
            }
        ]
    })";

    EXPECT_CALL(connection.api.peers, all(_, _))
      .Times(1)
      .WillOnce(Return(response));

    const auto peers = connection.api.peers.all(5, 1);

    DynamicJsonBuffer jsonBuffer(peers.size());
    JsonObject& root = jsonBuffer.parseObject(peers);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    const char* ip = dataZero["ip"];
    ASSERT_STREQ("167.114.29.53", ip);

    int port = dataZero["port"];
    ASSERT_EQ(4002, port);

    const char* version = dataZero["version"];
    ASSERT_STREQ("1.1.1", version);

    int status = dataZero["status"];
    ASSERT_EQ(200, status);

    const char* os = dataZero["os"];
    ASSERT_STREQ("linux", os);

    int latency = dataZero["latency"];
    ASSERT_EQ(1390, latency);
}
