
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;

/**/

TEST(api, test_node_configuration) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.54", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string response = R"({
    "data": {
      "nethash": "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
      "token" : "DARK",
      "symbol" : "DѦ",
      "explorer" : "https://dexplorer.ark.io",
      "version" : 30,
      "ports" : {
        "@arkecosystem/core-p2p": 4000,
        "@arkecosystem/core-api" : 4003,
        "@arkecosystem/core-graphql" : 4005,
        "@arkecosystem/core-json-rpc" : 8080
      },
      "feeStatistics": [
        {
          "type": 0,
          "fees" : {
            "minFee": 268421,
            "maxFee" : 597781,
            "avgFee" : 404591
          }
        }
      ],
      "constants": {
        "height": 75600,
        "reward" : 200000000,
        "activeDelegates" : 51,
        "blocktime" : 8,
        "block" : {
          "version": 0,
          "maxTransactions" : 50,
          "maxPayload" : 2097152
        },
        "epoch" : "2017-03-21T13:00:00.000Z",
        "fees" : {
          "send": 10000000,
          "vote" : 100000000,
          "secondsignature" : 500000000,
          "delegate" : 2500000000,
          "multisignature" : 500000000
        }
      }
    }
  })";

  EXPECT_CALL(connection.api.node, configuration()).Times(1).WillOnce(Return(response));

  const auto nodeConfiguration = connection.api.node.configuration();

  DynamicJsonDocument doc(1556);
  DeserializationError error = deserializeJson(doc, nodeConfiguration);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto nethash = data["nethash"];
  ASSERT_STREQ(
      "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23",
      nethash);

  const auto token = data["token"];
  ASSERT_STREQ("DARK", token);

  const auto symbol = data["symbol"];
  ASSERT_STREQ(u8"DѦ", symbol);

  const auto explorer = data["explorer"];
  ASSERT_STREQ("https://dexplorer.ark.io", explorer);

  int version = data["version"];
  ASSERT_EQ(30, version);

  JsonObject ports = data["ports"];

  int core_p2p = ports["@arkecosystem/core-p2p"];
  ASSERT_EQ(4000, core_p2p);

  int core_api = ports["@arkecosystem/core-api"];
  ASSERT_EQ(4003, core_api);
}

/**/

TEST(api, test_node_status) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.54", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string response = R"({
    "data": {
      "synced": false,
      "now": 3034451,
      "blocksCount": 36
    }
  })";

  EXPECT_CALL(connection.api.node, status()).Times(1).WillOnce(Return(response));

  const auto nodeStatus = connection.api.node.status();

  DynamicJsonDocument doc(156);
  DeserializationError error = deserializeJson(doc, nodeStatus);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  bool synced = data["synced"];
  ASSERT_FALSE(synced);

  int now = data["now"];
  ASSERT_EQ(3034451, now);

  int blocksCount = data["blocksCount"];
  ASSERT_EQ(36, blocksCount);
}

/**/

TEST(api, test_node_syncing) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.54", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string response = R"({
    "data": {
      "syncing": true,
      "blocks": 36,
      "height": 3034451,
      "id": "5444078994968869529"
    }
  })";

  EXPECT_CALL(connection.api.node, syncing()).Times(1).WillOnce(Return(response));

  const auto nodeSyncing = connection.api.node.syncing();

  DynamicJsonDocument doc(212);
  DeserializationError error = deserializeJson(doc, nodeSyncing);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  bool syncing = data["syncing"];
  ASSERT_TRUE(syncing);

  int blocks = data["blocks"];
  ASSERT_EQ(36, blocks);

  uint64_t height = data["height"];
  ASSERT_TRUE(3034451ULL == height);

  const auto id = data["id"];
  ASSERT_STREQ("5444078994968869529", id);
}
