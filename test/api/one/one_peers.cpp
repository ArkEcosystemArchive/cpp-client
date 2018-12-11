
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

TEST(api, test_one_peers_peer)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.196.105.32", 4003);

    const auto peerResponse = connection.api.peers.get("46.105.160.104", 4001);

    DynamicJsonBuffer jsonBuffer(peerResponse.size());
    JsonObject& root = jsonBuffer.parseObject(peerResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonObject& peer = root["peer"];

    const char* ip = peer["ip"];
    ASSERT_STREQ("46.105.160.104", ip);

    int port = peer["port"];
    ASSERT_EQ(4001, port);

    const char* version = peer["version"];
    ASSERT_STRNE("", version);
    // ASSERT_STREQ("1.1.1", version);
    // ASSERT_STREQ("2.0.0", version);

    int errors = peer["errors"];
    ASSERT_EQ(0, errors);

    const char* os = peer["os"];
    ASSERT_STRNE(NULL, os);

    int height = peer["height"];
    ASSERT_GE(height, 0);

    const char* status = peer["status"];
    ASSERT_STREQ("200", status);

    int delay = peer["delay"];
    ASSERT_NE(0, delay);
}


/**
 * limit is currently not working on v1 for the '/api/peers' endpoint
 * this results in the full list of peers being returned (~18,000 bytes).
 * Arduinos will generally crash with an object of this size. So we skip it
 */
#ifndef ARDUINO

TEST(api, test_one_peers_peers)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.196.105.32", 4003);

    const auto peersResponse = connection.api.peers.all(5);

    DynamicJsonBuffer jsonBuffer(peersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(peersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonObject& peersZero = root["peers"][0];

    const char* ip = peersZero["ip"];
    ASSERT_STRNE("", ip);

    int port = peersZero["port"];
    ASSERT_EQ(4001, port);

    int version = peersZero["version"];
    ASSERT_NE(0, version);

    int errors = peersZero["errors"];
    ASSERT_EQ(0, errors);

    const char* os = peersZero["os"];
    ASSERT_STRNE("", os);

    int height = peersZero["height"];
    ASSERT_GE(height, 0);

    const char* status = peersZero["status"];
    ASSERT_STREQ("OK", status);

    int delay = peersZero["delay"];
    ASSERT_GE(delay, 0);
}
#endif

TEST(api, test_one_peers_version)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.196.105.32", 4003);

    const auto versionResponse = connection.api.peers.version();

    DynamicJsonBuffer jsonBuffer(versionResponse.size());
    JsonObject& root = jsonBuffer.parseObject(versionResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* version = root["version"];
    ASSERT_STRNE("", version);
    // ASSERT_STREQ("1.3.0", version);
    // ASSERT_STREQ("2.0.0", version);

    const char* build = root["build"];
    ASSERT_STRNE("", build);
}
