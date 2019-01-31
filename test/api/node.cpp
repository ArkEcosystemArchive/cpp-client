
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;

/* test_node_configuration
 * https://dexplorer.ark.io:8443/api/v2/node/configuration
 * Expected Response:
    {
    "data": {
        "nethash": "string",
        "token": "string",
        "symbol": "string",
        "explorer": "string",
        "version": int,
        "ports": {
            "@arkecosystem\/core-p2p": "int",
            "@arkecosystem\/core-api": "int"
        },
        "constants": {
            "height": uint64_t,
            "reward": uint64_t,
            "activeDelegates": int,
            "blocktime": 8,
            "block": {
                "version": int,
                "maxTransactions": int,
                "maxPayload": int
            },
            "epoch": "string",
            "fees": {
                "dynamic": bool,
                "transfer": uint64_t,
                "secondSignature": uint64_t,
                "delegateRegistration": uint64_t,
                "vote": uint64_t,
                "multiSignature": uint64_t,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            },
            "dynamicOffsets": {
                "transfer": int,
                "secondSignature": int,
                "delegateRegistration": int,
                "vote": int,
                "multiSignature": int,
                "ipfs": int,
                "timelockTransfer": int,
                "multiPayment": int,
                "delegateResignation": int
            }
        },
        "feeStatistics": [
        {
            "type": 0,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 3,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 1,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 2,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        },
        {
            "type": 4,
            "fees": {
                "minFee": uint64_t,
                "maxFee": uint64_t,
                "avgFee": uint64_t
            }
        }
        ]
    }
    }
*/
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

  DynamicJsonBuffer jsonBuffer(nodeConfiguration.size());
  JsonObject& root = jsonBuffer.parseObject(nodeConfiguration);

  JsonObject& data = root["data"];

  const char* nethash = data["nethash"];
  ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", nethash);

  const char* token = data["token"];
  ASSERT_STREQ("DARK", token);

  const char* symbol = data["symbol"];
  ASSERT_STREQ(u8"DѦ", symbol);

  const char* explorer = data["explorer"];
  ASSERT_STREQ("https://dexplorer.ark.io", explorer);

  int version = data["version"];
  ASSERT_EQ(30, version);

  JsonObject& ports = data["ports"];

  int core_p2p = ports["@arkecosystem/core-p2p"];
  ASSERT_EQ(4000, core_p2p);

  int core_api = ports["@arkecosystem/core-api"];
  ASSERT_EQ(4003, core_api);
}

/* test_node_status
 * https://dexplorer.ark.io:8443/api/v2/node/status
 * Expected Response:
    {
        "data": {
            "synced": bool,
            "now": int,
            "blocksCount": int
        }
    }
 */
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

  DynamicJsonBuffer jsonBuffer(nodeStatus.size());
  JsonObject& root = jsonBuffer.parseObject(nodeStatus);

  JsonObject& data = root["data"];

  bool synced = data["synced"];
  ASSERT_FALSE(synced);

  int now = data["now"];
  ASSERT_EQ(3034451, now);

  int blocksCount = data["blocksCount"];
  ASSERT_EQ(36, blocksCount);
}

/* test_node_status
 * 167.114.29.54:4003/api/v2/node/syncing
 * Expected Response:
    {
    "data": {
        "syncing": bool,
        "blocks": int,
        "height": uint64_t,
        "id": "string"
    }
    }
 */
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

  DynamicJsonBuffer jsonBuffer(nodeSyncing.size());
  JsonObject& root = jsonBuffer.parseObject(nodeSyncing);

  JsonObject& data = root["data"];

  bool syncing = data["syncing"];
  ASSERT_TRUE(syncing);

  int blocks = data["blocks"];
  ASSERT_EQ(36, blocks);

  uint64_t height = data["height"];
  ASSERT_TRUE(3034451ull == height);

  const char* id = data["id"];
  ASSERT_STREQ("5444078994968869529", id);
}
