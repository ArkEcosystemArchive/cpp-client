
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

TEST(api, test_one_loader_autoconfigure)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto autoconfigureResponse = connection.api.loader.autoconfigure();

    DynamicJsonBuffer jsonBuffer(autoconfigureResponse.size());
    JsonObject& root = jsonBuffer.parseObject(autoconfigureResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& network = root["network"];

    const char* nethash = network["nethash"];
    ASSERT_STREQ("6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988", nethash); // v1 mainnet nethash

    const char* token = network["token"];
    ASSERT_STREQ("ARK", token);

    const char* symbol = network["symbol"];
    ASSERT_STREQ(u8"Ѧ", symbol);

    const char* explorer = network["explorer"];
    ASSERT_STREQ("https://explorer.ark.io", explorer);

    int version = network["version"];
    ASSERT_EQ(23, version);
}

TEST(api, test_one_loader_status)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);
    
    const auto statusResponse = connection.api.loader.status();

    DynamicJsonBuffer jsonBuffer(statusResponse.size());
    JsonObject& root = jsonBuffer.parseObject(statusResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    bool loaded = root["loaded"];
    ASSERT_FALSE(loaded);

    int now = root["now"];
    ASSERT_NE(0, now);
    
    int blocksCount = root["blocksCount"];
    ASSERT_EQ(0, blocksCount);
}

TEST(api, test_one_loader_sync)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto syncResponse = connection.api.loader.sync();

    DynamicJsonBuffer jsonBuffer(syncResponse.size());
    JsonObject& root = jsonBuffer.parseObject(syncResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    bool syncing = root["syncing"];
    ASSERT_FALSE(syncing);

    int blocks = root["blocks"];
    ASSERT_STRNE("", std::to_string(blocks).c_str());

    int height = root["height"];
    ASSERT_NE(0, height);

    const char* id = root["id"];
    ASSERT_STRNE("", id);
}
