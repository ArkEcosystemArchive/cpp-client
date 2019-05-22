
#include "arkClient.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mocks/mock_api.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

TEST(api, test_delegate) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
    "data": {
      "username": "boldninja",
      "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
      "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
      "votes": 0,
      "rank": 29,
      "blocks": {
        "produced": 0,
        "missed": 0,
        "last": {
          "id": "10652480998435361357",
          "timestamp": {
            "epoch": 32816112,
            "unix": 1522917312,
            "human": "2018-04-05T08:35:12Z"
          }
        }
      },
      "production": {
        "approval": "0.10",
        "productivity": "0.00"
      }
    }
  })";

  EXPECT_CALL(connection.api.delegates, get(_)).Times(1).WillOnce(Return(expected_response));

  const auto delegateResponse = connection.api.delegates.get("boldninja");

  DynamicJsonDocument doc(876);
  DeserializationError error = deserializeJson(doc, delegateResponse);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto username = data["username"];
  ASSERT_STREQ("boldninja", username);

  const auto address = data["address"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", address);

  const auto publicKey = data["publicKey"];
  ASSERT_STREQ(
      "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
      publicKey);

  uint64_t votes = data["votes"];
  ASSERT_EQ(0, votes);

  int rank = data["rank"];
  ASSERT_EQ(29, rank);

  JsonObject blocks = data["blocks"];

  int produced = blocks["produced"];
  ASSERT_EQ(0, produced);

  int missed = blocks["missed"];
  ASSERT_EQ(0, missed);

  JsonObject last = blocks["last"];

  const auto last_id = last["id"];
  ASSERT_STREQ("10652480998435361357", last_id);

  JsonObject timestamp = last["timestamp"];

  uint64_t epoch = timestamp["epoch"];
  ASSERT_TRUE(32816112ULL == epoch);

  uint64_t unix_timestamp = timestamp["unix"];
  ASSERT_TRUE(1522917312ULL == unix_timestamp);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2018-04-05T08:35:12Z", human);

  JsonObject production = data["production"];

  double approval = production["approval"];
  ASSERT_EQ(0.10, approval);

  double productivity = production["productivity"];
  ASSERT_EQ(0.0, productivity);
}

/**/

TEST(api, test_delegate_blocks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
            "count": 2,
            "pageCount": 29919,
            "totalCount": 59838,
            "next": "/v2/delegates/boldninja/blocks?page=2",
            "previous": null,
            "self": "/v2/delegates/boldninja/blocks?page=1",
            "first": "/v2/delegates/boldninja/blocks?page=1",
            "last": "/v2/delegates/boldninja/blocks?page=29919"
    },
    "data": [
      {
        "id": "10652480998435361357",
        "version": 0,
        "height": 3035318,
        "previous": "12548322724277171379",
        "forged": {
          "reward": 200000000,
          "fee": 0,
          "total": 200000000
        },
        "payload": {
          "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
          "length": 0
        },
        "generator": {
          "username": "boldninja",
          "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
          "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d"
        },
        "signature": "3044022034e754a3ff70adba6323517e1297c6a9f30176df2ac589661e9206fe60a203120220182c38da201fee20e803bb7725fe9618d6707547e6d7b757d4108f546934fe1c",
        "transactions": 0,
        "timestamp": {
          "epoch": 32816112,
          "unix": 1522917312,
          "human": "2018-04-05T08:35:12Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, blocks(_, _, _)).Times(1).WillOnce(Return(expected_response));

  const auto delegateBlocksResponse = connection.api.delegates.blocks("boldninja", 2, 1);

  DynamicJsonDocument doc(1788);
  DeserializationError error = deserializeJson(doc, delegateBlocksResponse);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_EQ(2, count);

  int pageCount = meta["pageCount"];
  ASSERT_EQ(29919, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_EQ(59838, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto id = dataZero["id"];
  ASSERT_STREQ("10652480998435361357", id);

  int version = dataZero["version"];
  ASSERT_EQ(0, version);

  uint64_t height = dataZero["height"];
  ASSERT_TRUE(3035318ULL == height);

  const auto previous = dataZero["previous"];
  ASSERT_STREQ("12548322724277171379", previous);

  JsonObject generatorZero = dataZero["generator"];

  const auto username = generatorZero["username"];
  ASSERT_STREQ("boldninja", username);

  const auto address = generatorZero["address"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", address);

  const auto publicKey = generatorZero["publicKey"];
  ASSERT_STREQ(
      "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
      publicKey);
}

/**/

TEST(api, test_delegate_voters) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
    "meta": {
      "count": 2,
      "pageCount": 10,
      "totalCount": 19,
      "next": "/v2/delegates/boldninja/voters?page=2",
      "previous": null,
      "self": "/v2/delegates/boldninja/voters?page=1",
      "first": "/v2/delegates/boldninja/voters?page=1",
      "last": "/v2/delegates/boldninja/voters?page=10"
    },
    "data": [
      {
        "address": "D5mbS6mpP5UheuciNscpDLgC127kYjRtkK",
        "publicKey": "03f7e0b1ab14985990416f72ed0b206c20b9efa35156e4528c8ff749fa0eea5d5a",
        "balance": 400000000,
        "isDelegate": false
      }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, voters(_, _, _)).Times(1).WillOnce(Return(expected_response));

  const auto delegateVotersResponse = connection.api.delegates.voters("boldninja", 5, 1);

  DynamicJsonDocument doc(836);
  DeserializationError error = deserializeJson(doc, delegateVotersResponse);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto address = dataZero["address"];
  ASSERT_STREQ("D5mbS6mpP5UheuciNscpDLgC127kYjRtkK", address);

  const auto publicKey = dataZero["publicKey"];
  ASSERT_STREQ(
      "03f7e0b1ab14985990416f72ed0b206c20b9efa35156e4528c8ff749fa0eea5d5a",
      publicKey);

  bool isDelegate = dataZero["isDelegate"];
  ASSERT_FALSE(isDelegate);
}

/**/

TEST(api, test_delegates) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
    "meta": {
            "count": 2,
            "pageCount": 99,
            "totalCount": 197,
            "next": "/v2/delegates?page=2",
            "previous": null,
            "self": "/v2/delegates?page=1",
            "first": "/v2/delegates?page=1",
            "last": "/v2/delegates?page=99"
    },
    "data": [
      {
        "username": "dark_jmc",
        "address": "D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz",
        "publicKey": "02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586",
        "votes": 0,
        "rank": 1,
        "blocks": {
          "produced": 0,
          "missed": 0,
          "last": {
            "id": "12383884455448354193",
            "timestamp": {
              "epoch": 31784600,
              "unix": 1521885800,
              "human": "2018-03-24T10:03:20Z"
            }
          }
        },
        "production": {
          "approval": "0.08",
          "productivity": "0.00"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, all(5, 1)).Times(1).WillOnce(Return(expected_response));

  const auto delegates = connection.api.delegates.all(5, 1);

  DynamicJsonDocument doc(1340);
  DeserializationError error = deserializeJson(doc, delegates);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto username = dataZero["username"];
  ASSERT_STREQ("dark_jmc", username);

  const auto address = dataZero["address"];
  ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", address);

  const auto publicKey = dataZero["publicKey"];
  ASSERT_STREQ(
      "02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586",
      publicKey);

  uint64_t votes = dataZero["votes"];
  ASSERT_TRUE(0ULL == votes);
}
