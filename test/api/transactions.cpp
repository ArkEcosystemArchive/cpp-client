#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

TEST(api, test_transaction) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "data": {
      "id": "5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa",
      "blockId": "4271682877946294396",
      "type": 0,
      "amount": 32106400000,
      "fee": 10000000,
      "sender": "DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh",
      "recipient": "DQnQNoJuNCvpjYhxL7fsnGepHBqrumgsyP",
      "signature": "3044022047c39f6f45a46a87f91ca867f9551dbebf0035adcfcbdc1370222c7a1517fc0002206fb5ecc10460e0352a8b626a508e2fcc76e39e490b0a2581dd772ebc8079696e",
      "confirmations": 1928,
      "timestamp": {
        "epoch": 32794053,
        "unix": 1522895253,
        "human": "2018-04-05T02:27:33Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.transactions, get(_)).Times(1).WillOnce(Return(response));

  const auto transaction = connection.api.transactions.get(
      "5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa");

  DynamicJsonDocument doc(868);
  DeserializationError error = deserializeJson(doc, transaction);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto id = data["id"];
  ASSERT_STREQ("5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa", id);

  const auto blockId = data["blockId"];
  ASSERT_STREQ("4271682877946294396", blockId);

  int type = data["type"];
  ASSERT_EQ(0, type);

  uint64_t amount = data["amount"];
  ASSERT_TRUE(amount == 32106400000);

  uint64_t fee = data["fee"];
  ASSERT_TRUE(fee == 10000000);

  const auto sender = data["sender"];
  ASSERT_STREQ("DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh", sender);

  const auto recipient = data["recipient"];
  ASSERT_STREQ("DQnQNoJuNCvpjYhxL7fsnGepHBqrumgsyP", recipient);

  const auto signature = data["signature"];
  ASSERT_STREQ(
      "3044022047c39f6f45a46a87f91ca867f9551dbebf0035adcfcbdc1370222c7a1517fc0002206fb5ecc10460e0352a8b626a508e2fcc76e39e490b0a2581dd772ebc8079696e",
      signature);

  int confirmations = data["confirmations"];
  ASSERT_EQ(confirmations, 1928);

  JsonObject timestamp = data["timestamp"];

  int epoch = timestamp["epoch"];
  ASSERT_EQ(32794053, epoch);

  int timestampUnix = timestamp["unix"];
  ASSERT_EQ(1522895253, timestampUnix);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2018-04-05T02:27:33Z", human);
}

/**/

TEST(api, test_transaction_types) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "data": {
      "Transfer": 0,
      "SecondSignature": 1,
      "DelegateRegistration": 2,
      "Vote": 3,
      "MultiSignature": 4,
      "Ipfs": 5,
      "TimelockTransfer": 6,
      "MultiPayment": 7,
      "DelegateResignation": 8
    }
  })";

  EXPECT_CALL(connection.api.transactions, types()).Times(1).WillOnce(Return(response));

  const auto types = connection.api.transactions.types();

  DynamicJsonDocument doc(444);
  DeserializationError error = deserializeJson(doc, types);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  int Transfer = data["Transfer"];
  ASSERT_EQ(0, Transfer);

  int SecondSignature = data["SecondSignature"];
  ASSERT_EQ(1, SecondSignature);

  int DelegateRegistration = data["DelegateRegistration"];
  ASSERT_EQ(2, DelegateRegistration);

  int Vote = data["Vote"];
  ASSERT_EQ(3, Vote);

  int MultiSignature = data["MultiSignature"];
  ASSERT_EQ(4, MultiSignature);

  int Ipfs = data["Ipfs"];
  ASSERT_EQ(5, Ipfs);

  int TimelockTransfer = data["TimelockTransfer"];
  ASSERT_EQ(6, TimelockTransfer);

  int MultiPayment = data["MultiPayment"];
  ASSERT_EQ(7, MultiPayment);

  int DelegateResignation = data["DelegateResignation"];
  ASSERT_EQ(8, DelegateResignation);
}

/**/

TEST(api, test_transaction_unconfirmed) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "data": {
      "id": "dummy",
      "blockId": "dummy",
      "type": 0,
      "amount": 10000000,
      "fee": 10000000,
      "sender": "dummy",
      "recipient": "dummy",
      "signature": "dummy",
      "vendorField": "dummy",
      "confirmations": 10,
      "timestamp": {
        "epoch": 40505460,
        "unix": 1530606660,
        "human": "2018-07-03T08:31:00Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.transactions, getUnconfirmed(_)).Times(1).WillOnce(Return(response));

  const auto transactionUnconfirmed = connection.api.transactions.getUnconfirmed("dummy");

  DynamicJsonDocument doc(652);
  DeserializationError error = deserializeJson(doc, transactionUnconfirmed);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto id = data["id"];
  ASSERT_STREQ("dummy", id);

  const auto blockId = data["blockId"];
  ASSERT_STREQ("dummy", blockId);

  int type = data["type"];
  ASSERT_EQ(0, type);

  uint64_t amount = data["amount"];
  ASSERT_TRUE(10000000ULL == amount);

  uint64_t fee = data["fee"];
  ASSERT_TRUE(10000000ULL == fee);

  const auto sender = data["sender"];
  ASSERT_STREQ("dummy", sender);

  const auto recipient = data["recipient"];
  ASSERT_STREQ("dummy", recipient);

  const auto signature = data["signature"];
  ASSERT_STREQ("dummy", signature);

  const auto vendorField = data["vendorField"];
  ASSERT_STREQ("dummy", vendorField);

  int confirmations = data["confirmations"];
  ASSERT_EQ(10, confirmations);

  JsonObject timestamp = data["timestamp"];

  uint64_t epoch = timestamp["epoch"];
  ASSERT_TRUE(40505460ULL == epoch);

  uint64_t unix_timestamp = timestamp["unix"];
  ASSERT_TRUE(1530606660ULL == unix_timestamp);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2018-07-03T08:31:00Z", human);
}

/**/

TEST(api, test_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 127430,
      "totalCount": 254860,
      "next": "/v2/transactions?page=2",
      "previous": null,
      "self": "/v2/transactions?page=1",
      "first": "/v2/transactions?page=1",
      "last": "/v2/transactions?page=127430"
    },
    "data": [
      {
        "id": "5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa",
        "blockId": "4271682877946294396",
        "type": 0,
        "amount": 32106400000,
        "fee": 10000000,
        "sender": "DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh",
        "recipient": "DQnQNoJuNCvpjYhxL7fsnGepHBqrumgsyP",
        "signature": "3044022047c39f6f45a46a87f91ca867f9551dbebf0035adcfcbdc1370222c7a1517fc0002206fb5ecc10460e0352a8b626a508e2fcc76e39e490b0a2581dd772ebc8079696e",
        "confirmations": 1924,
        "timestamp": {
          "epoch": 32794053,
          "unix": 1522895253,
          "human": "2018-04-05T02:27:33Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, all(_, _)).Times(1).WillOnce(Return(response));

  const auto transactions = connection.api.transactions.all(2, 1);

  DynamicJsonDocument doc(1348);
  DeserializationError error = deserializeJson(doc, transactions);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  int type = dataZero["type"];
  ASSERT_EQ(0, type);

  uint64_t fee = dataZero["fee"];
  ASSERT_TRUE(fee >= 0);
}

/**/

TEST(api, test_transactions_unconfirmed) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/api/transactions/unconfirmed?page=1&limit=1",
      "first": "/api/transactions/unconfirmed?page=1&limit=1",
      "last": "/api/transactions/unconfirmed?page=1&limit=1"
    },
    "data": [
      {
        "id": "dummy",
        "blockId": "dummy",
        "type": 0,
        "amount": 10000000,
        "fee": 10000000,
        "sender": "dummy",
        "recipient": "dummy",
        "signature": "dummy",
        "vendorField": "dummy",
        "confirmations": 10,
        "timestamp": {
          "epoch": 40505460,
          "unix": 1530606660,
          "human": "2018-07-03T08:31:00Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, allUnconfirmed(_, _)).Times(1).WillOnce(Return(response));

  const auto transactionsUnconfirmed = connection.api.transactions.allUnconfirmed(5, 1);

  DynamicJsonDocument doc(1164);
  DeserializationError error = deserializeJson(doc, transactionsUnconfirmed);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_TRUE(count >= 0);

  int pageCount = meta["pageCount"];
  ASSERT_TRUE(pageCount >= 0);

  int totalCount = meta["totalCount"];
  ASSERT_TRUE(totalCount >= 0);
}

/**/

TEST(api, test_transactions_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/api/transactions/search?page=1&limit=1",
      "first": "/api/transactions/search?page=1&limit=1",
      "last": "/api/transactions/search?page=1&limit=1"
    },
    "data": [
      {
        "id": "dummy",
        "blockId": "dummy",
        "type": 0,
        "amount": 10000000,
        "fee": 10000000,
        "sender": "dummy",
        "recipient": "dummy",
        "signature": "dummy",
        "vendorField": "dummy",
        "confirmations": 10,
        "timestamp": {
          "epoch": 40505460,
          "unix": 1530606660,
          "human": "2018-07-03T08:31:00Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, search(_, _, _)).Times(1).WillOnce(Return(response));

  const std::map<std::string, std::string> body = {
    { "id", "dummy" }
  };
  const auto transactions = connection.api.transactions.search(body, 5, 1);

  DynamicJsonDocument doc(1148);
  DeserializationError error = deserializeJson(doc, transactions);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_TRUE(count >= 0);

  int pageCount = meta["pageCount"];
  ASSERT_TRUE(pageCount >= 0);

  int totalCount = meta["totalCount"];
  ASSERT_TRUE(totalCount >= 0);

  JsonObject data = doc["data"][0];

  const auto id = data["id"];
  ASSERT_STREQ("dummy", id);

  const auto blockId = data["blockId"];
  ASSERT_STREQ("dummy", blockId);

  int type = data["type"];
  ASSERT_EQ(0, type);

  const auto sender = data["sender"];
  ASSERT_STREQ("dummy", sender);

  const auto recipient = data["recipient"];
  ASSERT_STREQ("dummy", recipient);

  const auto signature = data["signature"];
  ASSERT_STREQ("dummy", signature);
}

/**/

TEST(api, test_transactions_send) {  // NOLINT
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    const std::string response = R"({
      "data": {
        "accept": [
          "dummy"
        ],
        "broadcast": [
          "dummy"
        ],
        "excess": [],
        "invalid": []
      },
      "errors": null
    })";

  EXPECT_CALL(connection.api.transactions, send(_)).Times(1).WillOnce(Return(response));

  std::string jsonTransaction = "{"
    "\"transactions\":["
      "{"
        "\"type\":0,"
        "\"amount\":1,"
        "\"fee\":10000000,"
        "\"id\":\"bc5bb5cd23521c041fca17b5f78d6f3621fc07ab8f6581aff1b6eb86fa4bafe2\","
        "\"recipientId\":\"DNSrsDUq5injGBdNXPV7v7u1Qy9LZfWEdM\","
        "\"senderPublicKey\":\"0216fa03d378b6ad01325e186ad2cbb9d18976d5b27d0ca74b4f92bb6bf9a6d4d9\","
        "\"signature\":\"3044022014204515b82cdd47513377d3e80e6b5f4fd1ab0fb6b4c181e09a7a30428d542502205ba076a332997053e1d31b506777a99f93bcb11294cd678ebe2da313eb02cae2\","
        "\"timestamp\":58351951,"
        "\"vendorField\":\"7ad0eeb302ee7d9b4e58cf52daa9ece7922ad92d14f0407e3881597bf3c9c1c6\""
      "}"
    "]"
  "}";

  const auto transaction = connection.api.transactions.send(jsonTransaction);

  DynamicJsonDocument doc(324);
  DeserializationError error = deserializeJson(doc, transaction);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  std::string accept = data["accept"];
  ASSERT_NE(accept.length(), 0);

  std::string broadcast = data["broadcast"];
  ASSERT_NE(broadcast.length(), 0);

  std::string excess = data["excess"];
  ASSERT_EQ(excess.length(), 2);

  std::string invalid = data["invalid"];
  ASSERT_EQ(invalid.length(), 2);

  std::string errors = data["errors"];
  ASSERT_EQ(errors.length(), 4);
}
