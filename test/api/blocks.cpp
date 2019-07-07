
#include "arkClient.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mocks/mock_api.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

TEST(api, test_block) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "data": {
      "id": "58328125061111756",
      "version": 0,
      "height": 3035362,
      "previous": "3741191868092856237",
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
        "username": "genesis_6",
        "address": "D5e2FzTPqdEHridjzpFZCCVyepAu6Vpmk4",
        "publicKey": "023e577a7b3362e0aba70e6911d230e86d729b4cb640f0e0b25637b812a3e38b53"
      },
      "signature": "3044022047aeb0c9cfbb5709aba4c177009bfdc7804ef597073fb9ca6cb614d7e3d1af2d02207234119d02ca26600ece045c59266945081b4c8237370576aaad7c61a09fe0ad",
      "transactions": 0,
      "timestamp": {
        "epoch": 32816544,
        "unix": 1522917744,
        "human": "2018-04-05T08:42:24Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.blocks, get(_)).Times(1).WillOnce(Return(expected_response));

  const auto blockResponse = connection.api.blocks.get("58328125061111756");

  DynamicJsonDocument doc(1244);
  DeserializationError error = deserializeJson(doc, blockResponse);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto id = data["id"];
  ASSERT_STREQ("58328125061111756", id);

  int version = data["version"];
  ASSERT_EQ(0, version);

  int height = data["height"];
  ASSERT_EQ(3035362, height);

  JsonObject forged = data["forged"];

  uint64_t reward = forged["reward"];
  ASSERT_TRUE(reward == 200000000);

  uint64_t fee = forged["fee"];
  ASSERT_TRUE(fee == 0);

  uint64_t total = forged["total"];
  ASSERT_TRUE(total == 200000000);

  JsonObject payload = data["payload"];

  const auto hash = payload["hash"];
  ASSERT_STREQ(
      "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
      hash);

  int length = payload["length"];
  ASSERT_EQ(0, length);

  JsonObject generator = data["generator"];

  const auto username = generator["username"];
  ASSERT_STREQ("genesis_6", username);

  const auto address = generator["address"];
  ASSERT_STREQ("D5e2FzTPqdEHridjzpFZCCVyepAu6Vpmk4", address);

  const auto publicKey = generator["publicKey"];
  ASSERT_STREQ(
      "023e577a7b3362e0aba70e6911d230e86d729b4cb640f0e0b25637b812a3e38b53",
      publicKey);

  const auto signature = data["signature"];
  ASSERT_STREQ(
      "3044022047aeb0c9cfbb5709aba4c177009bfdc7804ef597073fb9ca6cb614d7e3d1af2d02207234119d02ca26600ece045c59266945081b4c8237370576aaad7c61a09fe0ad",
      signature);

  int transactions = data["transactions"];
  ASSERT_EQ(0, transactions);

  JsonObject timestamp = data["timestamp"];

  int epoch = timestamp["epoch"];
  ASSERT_EQ(32816544, epoch);

  int timestampUnix = timestamp["unix"];
  ASSERT_EQ(1522917744, timestampUnix);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2018-04-05T08:42:24Z", human);
}

/**/

TEST(api, test_block_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/v2/blocks/14126007750611341900/transactions?page=1",
      "first": "/v2/blocks/14126007750611341900/transactions?page=1",
      "last": "/v2/blocks/14126007750611341900/transactions?page=1"
    },
    "data": [
      {
        "id": "57415c61e6e7f10a6f9820d5124b3916f3c3a036b360f4802f0eb484f86f3369",
        "blockId": "14126007750611341900",
        "type": 0,
        "amount": 1000000000000000,
        "fee": 10000000,
        "sender": "DGihocTkwDygiFvmg6aG8jThYTic47GzU9",
        "recipient": "DRac35wghMcmUSe5jDMLBDLWkVVjyKZFxK",
        "signature": "3045022100878335a71ab6769f3c1e2895041ad24d6c58cdcfe1151c639e65289e5287b0a8022010800bcfdc3223a9c59a6b014e8adf72f1c34df8a46afe655b021930b03e214e",
        "vendorField": "yo",
        "confirmations": 3034848,
        "timestamp": {
          "epoch": 3909196,
          "unix": 1494010396,
          "human": "2017-05-05T18:53:16Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.blocks, transactions(_)).Times(1).WillOnce(Return(expected_response));

  const auto blockTransactionsResponse = connection.api.blocks.transactions("14126007750611341900");

  DynamicJsonDocument doc(1452);
  DeserializationError error = deserializeJson(doc, blockTransactionsResponse);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_EQ(1, count);

  int pageCount = meta["pageCount"];
  ASSERT_EQ(1, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_EQ(1, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto id = dataZero["id"];
  ASSERT_STREQ(
      "57415c61e6e7f10a6f9820d5124b3916f3c3a036b360f4802f0eb484f86f3369",
      id);

  const auto blockId = dataZero["blockId"];
  ASSERT_STREQ("14126007750611341900", blockId);

  int type = dataZero["type"];
  ASSERT_EQ(0, type);

  uint64_t amount = dataZero["amount"];
  ASSERT_TRUE(amount = 1000000000000000);

  uint64_t fee = dataZero["fee"];
  ASSERT_TRUE(fee == 10000000);

  const auto sender = dataZero["sender"];
  ASSERT_STREQ("DGihocTkwDygiFvmg6aG8jThYTic47GzU9", sender);

  const auto signature = dataZero["signature"];
  ASSERT_STREQ(
      "3045022100878335a71ab6769f3c1e2895041ad24d6c58cdcfe1151c639e65289e5287b0a8022010800bcfdc3223a9c59a6b014e8adf72f1c34df8a46afe655b021930b03e214e",
      signature);

  int confirmations = dataZero["confirmations"];
  ASSERT_EQ(3034848, confirmations);

  JsonObject timestamp = dataZero["timestamp"];

  int epoch = timestamp["epoch"];
  ASSERT_EQ(3909196, epoch);

  int timestampUnix = timestamp["unix"];
  ASSERT_EQ(1494010396, timestampUnix);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2017-05-05T18:53:16Z", human);
}

/**/

TEST(api, test_blocks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
      "count": 2,
      "pageCount": 1517682,
      "totalCount": 3035363,
      "next": "/v2/blocks?limit=2&page=2",
      "previous": null,
      "self": "/v2/blocks?limit=2&page=1",
      "first": "/v2/blocks?limit=2&page=1",
      "last": "/v2/blocks?limit=2&page=1517682"
    },
    "data": [
      {
        "id": "6402736103893238690",
        "version": 0,
        "height": 3035363,
        "previous": "58328125061111756",
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
          "username": "shawmishrak",
          "address": "D7P41dV7s259L3P7BVPNyqExqNDC7vdfx9",
          "publicKey": "030fa94238eb63db0247a9bd6a3fd810f690b449ee9ce4eb654b94b22875a9a612"
        },
        "signature": "304402204d0dbeb4e71a99a0f128a3480350014f0a9f250818dae908edd15bce99f49be00220257bf240c5d8578e9ffe144e7dbf0c2259d34e6571e6a83402edc01daec6228e",
        "transactions": 0,
        "timestamp": {
          "epoch": 32816552,
          "unix": 1522917752,
          "human": "2018-04-05T08:42:32Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.blocks, all(5, 1)).Times(1).WillOnce(Return(expected_response));

  const auto blocksResponse = connection.api.blocks.all(5, 1);

  DynamicJsonDocument doc(1740);
  DeserializationError error = deserializeJson(doc, blocksResponse);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  int version = dataZero["version"];
  ASSERT_EQ(0, version);
}

/**/

TEST(api, test_blocks_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/v2/blocks/14126007750611341900/transactions/search?page=1",
      "first": "/v2/blocks/14126007750611341900/transactions/search?page=1",
      "last": "/v2/blocks/14126007750611341900/transactions/search?page=1"
    },
    "data": [
      {
        "id": "57415c61e6e7f10a6f9820d5124b3916f3c3a036b360f4802f0eb484f86f3369",
        "blockId": "14126007750611341900",
        "type": 0,
        "amount": 1000000000000000,
        "fee": 10000000,
        "sender": "DGihocTkwDygiFvmg6aG8jThYTic47GzU9",
        "recipient": "DRac35wghMcmUSe5jDMLBDLWkVVjyKZFxK",
        "signature": "3045022100878335a71ab6769f3c1e2895041ad24d6c58cdcfe1151c639e65289e5287b0a8022010800bcfdc3223a9c59a6b014e8adf72f1c34df8a46afe655b021930b03e214e",
        "vendorField": "yo",
        "confirmations": 3034848,
        "timestamp": {
          "epoch": 3909196,
          "unix": 1494010396,
          "human": "2017-05-05T18:53:16Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.blocks, search(_, _, _)).Times(1).WillOnce(Return(expected_response));

  const std::map<std::string, std::string> body = {
    { "id", "8337447655053578871" },
    { "previousBlock", "6440284271011893973" },
    { "version", "0" }};
  const auto walletsSearch = connection.api.blocks.search(body, 5, 1);

  DynamicJsonDocument doc(1476);
  DeserializationError error = deserializeJson(doc, walletsSearch);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto id = dataZero["id"];
  ASSERT_STREQ(
      "57415c61e6e7f10a6f9820d5124b3916f3c3a036b360f4802f0eb484f86f3369",
      id);

  const auto blockId = dataZero["blockId"];
  ASSERT_STREQ("14126007750611341900", blockId);

  int type = dataZero["type"];
  ASSERT_EQ(0, type);

  uint64_t amount = dataZero["amount"];
  ASSERT_TRUE(1000000000000000ULL == amount);

  uint64_t fee = dataZero["fee"];
  ASSERT_TRUE(10000000ULL == fee);

  const auto sender = dataZero["sender"];
  ASSERT_STREQ("DGihocTkwDygiFvmg6aG8jThYTic47GzU9", sender);

  const auto recipient = dataZero["recipient"];
  ASSERT_STREQ("DRac35wghMcmUSe5jDMLBDLWkVVjyKZFxK", recipient);

  const auto signature = dataZero["signature"];
  ASSERT_STREQ(
      "3045022100878335a71ab6769f3c1e2895041ad24d6c58cdcfe1151c639e65289e5287b0a8022010800bcfdc3223a9c59a6b014e8adf72f1c34df8a46afe655b021930b03e214e",
      signature);

  const auto vendorField = dataZero["vendorField"];
  ASSERT_STREQ("yo", vendorField);

  int confirmations = dataZero["confirmations"];
  ASSERT_EQ(3034848, confirmations);

  JsonObject timestamp = dataZero["timestamp"];

  uint64_t epoch = timestamp["epoch"];
  ASSERT_TRUE(3909196ULL == epoch);

  uint64_t unix_timestamp = timestamp["unix"];
  ASSERT_TRUE(1494010396ULL == unix_timestamp);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2017-05-05T18:53:16Z", human);
}
