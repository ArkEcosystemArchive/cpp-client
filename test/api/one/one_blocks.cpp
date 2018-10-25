
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

/**
 * @brief Construct a new TEST object
 * 
 * Expected Result:
 *  {
 *      "success": true,
 *      "block": {
 *          "id": "10000414802057079451",
 *          "version": 0,
 *          "timestamp": 21954240,
 *          "height": 2712171,
 *          "previousBlock": "15469398098499685416",
 *          "numberOfTransactions": 4,
 *          "totalAmount": 124978887682,
 *          "totalFee": 40000000,
 *          "reward": 200000000,
 *          "payloadLength": 128,
 *          "payloadHash": "1ef9fad890a276cc184950571145998d43bd80b2f6e8bd1c8ac1ae33aeb02cea",
 *          "generatorPublicKey": "034682a4c4d2c8c0bc5f966dd422a83d2b433e212ef1f334f82cc3fe4676240933",
 *          "generatorId": "AdBSvLKPp6pMp5ZDsxkgjFu6KeCokncSMk",
 *          "blockSignature": "3045022100ceb8d595474bd277ff4e7b652edbeed970f98c02c5b6523020078bb8902ffa4d02206ed0c070d6964687ac2fb264b46911ec21de1265560f047246cdbbbeca524266",
 *          "confirmations": 3119185,
 *          "totalForged": "240000000"
 *      }
 *  }
 */
TEST(api, test_one_blocks_block)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockResponse = connection.api.blocks.get("10000414802057079451");

    DynamicJsonBuffer jsonBuffer(blockResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockResponse);

    JsonObject& block = root["block"];

    const char* id = block["id"];
    ASSERT_STREQ("10000414802057079451", id);

    int version = block["version"];
    ASSERT_EQ(0, version);

    int timestamp = block["timestamp"];
    ASSERT_EQ(21954240, timestamp);

    int height = block["height"];
    ASSERT_EQ(2712171, height);

    const char* previousBlock = block["previousBlock"];
    ASSERT_STREQ("15469398098499685416", previousBlock);

    int numberOfTransactions = block["numberOfTransactions"];
    ASSERT_EQ(4, numberOfTransactions);

    uint64_t totalAmount = block["totalAmount"];
    ASSERT_TRUE(totalAmount == 124978887682);

    uint64_t totalFee = block["totalFee"];
    ASSERT_TRUE(totalFee == 40000000);

    uint64_t reward = block["reward"];
    ASSERT_TRUE(reward == 200000000);

    int payloadLength = block["payloadLength"];
    ASSERT_EQ(128, payloadLength);

    const char* payloadHash = block["payloadHash"];
    ASSERT_STREQ("1ef9fad890a276cc184950571145998d43bd80b2f6e8bd1c8ac1ae33aeb02cea", payloadHash);

    const char* generatorPublicKey = block["generatorPublicKey"];
    ASSERT_STREQ("034682a4c4d2c8c0bc5f966dd422a83d2b433e212ef1f334f82cc3fe4676240933", generatorPublicKey);

    const char* generatorId = block["generatorId"];
    ASSERT_STREQ("AdBSvLKPp6pMp5ZDsxkgjFu6KeCokncSMk", generatorId);

    const char* blockSignature = block["blockSignature"];
    ASSERT_STREQ("3045022100ceb8d595474bd277ff4e7b652edbeed970f98c02c5b6523020078bb8902ffa4d02206ed0c070d6964687ac2fb264b46911ec21de1265560f047246cdbbbeca524266", blockSignature);

    int confirmations = block["confirmations"];
    ASSERT_TRUE(confirmations > 3000000);

    uint64_t totalForged = block["totalForged"];
    ASSERT_TRUE(totalForged == 240000000);
}

TEST(api, test_one_blocks_blocks)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blocksResponse = connection.api.blocks.all();

    DynamicJsonBuffer jsonBuffer(blocksResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blocksResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonArray& blocks = root["blocks"];

    for (int i = 0; i < 10; i++) {
        int version = blocks[i]["version"];
        ASSERT_EQ(0, version);
    }
}

TEST(api, test_one_blocks_epoch)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto epochResponse = 	connection.api.blocks.epoch();

    DynamicJsonBuffer jsonBuffer(epochResponse.size());
    JsonObject& root = jsonBuffer.parseObject(epochResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* epoch = root["epoch"];
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);
}

TEST(api, test_one_blocks_fee)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockFeeResponse = connection.api.blocks.fee();

    DynamicJsonBuffer jsonBuffer(blockFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t blockFee = root["fee"];
    ASSERT_TRUE(blockFee == 10000000);
}

TEST(api, test_one_blocks_fees)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockFeesResponse = connection.api.blocks.fees();

    DynamicJsonBuffer jsonBuffer(blockFeesResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockFeesResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& fees = root["fees"];

    uint64_t send = fees["send"];
    ASSERT_TRUE(send == 10000000);

    uint64_t vote = fees["vote"];
    ASSERT_TRUE(vote == 100000000);

    uint64_t secondsignature = fees["secondsignature"];
    ASSERT_TRUE(secondsignature == 500000000);

    uint64_t delegate = fees["delegate"];
    ASSERT_TRUE(delegate == 2500000000);

    uint64_t multisignature = fees["multisignature"];
    ASSERT_TRUE(multisignature == 500000000);
}

TEST(api, test_one_blocks_height)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockHeightResponse = connection.api.blocks.height();

    DynamicJsonBuffer jsonBuffer(blockHeightResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockHeightResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int height = root["height"];
    ASSERT_NE(0, height);

    const char* id = root["id"];
    ASSERT_STRNE("", id);
}

#if 0
TEST(api, test_one_blocks_milestone)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockMilestoneResponse = connection.api.blocks.milestone();

    DynamicJsonBuffer jsonBuffer(blockMilestoneResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockMilestoneResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    int milestone = root["milestone"];
    ASSERT_EQ(1, milestone);
}
#endif

TEST(api, test_one_blocks_nethash)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto nethashResponse = connection.api.blocks.nethash();

    DynamicJsonBuffer jsonBuffer(nethashResponse.size());
    JsonObject& root = jsonBuffer.parseObject(nethashResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* nethash = root["nethash"];
    ASSERT_STREQ("6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988", nethash); // v1 mainnet nethash
}

TEST(api, test_one_blocks_reward)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockRewardResponse = connection.api.blocks.reward();

    DynamicJsonBuffer jsonBuffer(blockRewardResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockRewardResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t reward = root["reward"];
    ASSERT_TRUE(reward == 200000000);
}

#if 0
TEST(api, test_one_blocks_status)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockStatusResponse = connection.api.blocks.status();

    DynamicJsonBuffer jsonBuffer(blockStatusResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockStatusResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    const char* epoch = root["epoch"];
    ASSERT_STREQ("2017-03-21T13:00:00.000Z", epoch);

    int height = root["height"];
    ASSERT_NE(0, height);

    uint64_t fee = root["fee"];
    ASSERT_TRUE(fee == 10000000);

    int milestone = root["milestone"];
    ASSERT_EQ(1, milestone);

    const char* nethash = root["nethash"];
    ASSERT_STREQ("6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988", nethash); // v1 mainnet nethash
    
    uint64_t reward = root["reward"];
    ASSERT_TRUE(reward == 200000000);

    uint64_t supply = root["supply"];
    ASSERT_TRUE(supply != 0);
}
#endif

TEST(api, test_one_blocks_supply)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto blockSupplyResponse = connection.api.blocks.supply();

    DynamicJsonBuffer jsonBuffer(blockSupplyResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockSupplyResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t supply = root["supply"];
    ASSERT_TRUE(supply >= 13670148400000000);
}
