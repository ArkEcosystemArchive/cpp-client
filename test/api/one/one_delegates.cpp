
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

namespace
{
    const auto publicKey = "03e6397071866c994c519f114a9e7957d8e6f06abc2ca34dc9a96b82f7166c2bf9"; // ACF
}

TEST(api, test_one_delegates_fee)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegateFeeResponse = connection.api.delegates.fee();

    DynamicJsonBuffer jsonBuffer(delegateFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t delegateFee = root["fee"];
    ASSERT_TRUE(delegateFee == 2500000000);
}

TEST(api, test_one_delegates_forged_by_account)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto forgedByAccountResponse = connection.api.delegates.forgedByAccount(publicKey);

    DynamicJsonBuffer jsonBuffer(forgedByAccountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(forgedByAccountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t fees = root["fees"];
    ASSERT_TRUE(fees >= 0);

    uint64_t rewards = root["rewards"];
    ASSERT_TRUE(rewards >= 0);

    uint64_t forged = root["forged"];
    ASSERT_TRUE(forged >= 0);
}

TEST(api, test_one_delegates_next_forgers)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto nextForgersResponse = connection.api.delegates.nextForgers();

    DynamicJsonBuffer jsonBuffer(nextForgersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(nextForgersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int currentBlock = root["currentBlock"];
    ASSERT_NE(0, currentBlock);

    int currentSlot = root["currentSlot"];
    ASSERT_NE(0, currentSlot);

    JsonArray& delegates = root["delegates"];
    for (int i = 0; i < 10; ++i)
    {
        const char* delegateKey = delegates[i];
        ASSERT_STRNE("", delegateKey);
    };
}

TEST(api, test_one_delegates_delegate_by_public_key)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    auto delegateResponse = connection.api.delegates.get(publicKey);

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("acf", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("AKzB7dWkCsYnt4u9P4Sch6iKyZ7QnDjBav", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("03e6397071866c994c519f114a9e7957d8e6f06abc2ca34dc9a96b82f7166c2bf9", publicKey);

    uint64_t vote = delegate["vote"];
    ASSERT_TRUE(vote >= 0);

    int producedblocks = delegate["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegate["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegate["rate"];
    ASSERT_NE(0, rate);

    double approval = delegate["approval"];
    ASSERT_TRUE(approval >= 0.00);

    double productivity = delegate["productivity"];
    ASSERT_TRUE(productivity >= 0.00);
}

TEST(api, test_one_delegates_delegate_by_username)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegateResponse = connection.api.delegates.get("acf");

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("acf", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("AKzB7dWkCsYnt4u9P4Sch6iKyZ7QnDjBav", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("03e6397071866c994c519f114a9e7957d8e6f06abc2ca34dc9a96b82f7166c2bf9", publicKey);

    uint64_t vote = delegate["vote"];
    ASSERT_TRUE(vote >= 0);

    int producedblocks = delegate["producedblocks"];
    ASSERT_NE(0, producedblocks);

    int missedblocks = delegate["missedblocks"];
    ASSERT_NE(0, missedblocks);

    int rate = delegate["rate"];
    ASSERT_NE(0, rate);

    double approval = delegate["approval"];
    ASSERT_TRUE(approval >= 0.00);

    double productivity = delegate["productivity"];
    ASSERT_TRUE(productivity >= 0.00);
}

TEST(api, test_one_delegates_delegates)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegatesResponse = connection.api.delegates.all();

    DynamicJsonBuffer jsonBuffer(delegatesResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonArray& delegates = root["delegates"];

    for (int i = 0; i < 20; i++) 
    {
        const char* username = delegates[i]["username"];
        ASSERT_STRNE("", username);

        const char* address = delegates[i]["address"];
        ASSERT_STRNE("", address);

        const char* publicKey = delegates[i]["publicKey"];
        ASSERT_STRNE("", publicKey);

        uint64_t vote = delegates[i]["vote"];
        ASSERT_TRUE(vote >= 0);

        int producedblocks = delegates[i]["producedblocks"];
        ASSERT_TRUE(producedblocks >= 0);

        int missedblocks = delegates[i]["missedblocks"];
        ASSERT_TRUE(missedblocks >= 0);

        int rate = delegates[i]["rate"];
        ASSERT_TRUE(rate >= 0);

        double approval = delegates[i]["approval"];
        ASSERT_TRUE(approval >= 0.00);

        double productivity = delegates[i]["productivity"];
        ASSERT_TRUE(productivity >= 0.00);
    }
}

TEST(api, test_one_delegates_voters)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto votersResponse = connection.api.delegates.voters(publicKey);

    DynamicJsonBuffer jsonBuffer(votersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(votersResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& accountsZero = root["accounts"][0];

    const char* address0 = accountsZero["address"];
    ASSERT_STRNE("", address0);

    const char* publicKey0 = accountsZero["publicKey"];
    ASSERT_STRNE("", publicKey0);

    uint64_t balance0 = accountsZero["balance"];
    ASSERT_TRUE(balance0 >= 0);


    JsonObject& accountsOne = root["accounts"][1];

    const char* username1 = accountsOne["username"];
    ASSERT_STRNE("", username1);

    const char* address1 = accountsOne["address"];
    ASSERT_STRNE("", address1);

    const char* publicKey1 = accountsOne["publicKey"];
    ASSERT_STRNE("", publicKey1);

    uint64_t balance1 = accountsOne["balance"];
    ASSERT_TRUE(balance1 >= 0);
}

TEST(api, test_one_delegates_search)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegateResponse = connection.api.delegates.get("acf");

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegate = root["delegate"];

    const char* username = delegate["username"];
    ASSERT_STREQ("acf", username);

    const char* address = delegate["address"];
    ASSERT_STREQ("AKzB7dWkCsYnt4u9P4Sch6iKyZ7QnDjBav", address);

    const char* publicKey = delegate["publicKey"];
    ASSERT_STREQ("03e6397071866c994c519f114a9e7957d8e6f06abc2ca34dc9a96b82f7166c2bf9", publicKey);

    uint64_t vote = delegate["vote"];
    ASSERT_TRUE(vote >= 0);

    int producedblocks = delegate["producedblocks"];
    ASSERT_TRUE(producedblocks >= 0);

    int missedblocks = delegate["missedblocks"];
    ASSERT_TRUE(missedblocks >= 0);

    int rate = delegate["rate"];
    ASSERT_TRUE(rate >= 0);

    double  approval = delegate["approval"];
    ASSERT_TRUE(approval >= 0.00);

    double productivity = delegate["productivity"];
    ASSERT_TRUE(productivity >= 0.00);
}

TEST(api, test_one_delegates_count)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegatesCountResponse = connection.api.delegates.count();

    DynamicJsonBuffer jsonBuffer(delegatesCountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesCountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int count = root["count"];
    ASSERT_NE(0, count);
}
