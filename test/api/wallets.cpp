#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

TEST(api, test_wallet) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "data": {
      "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
      "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
      "balance": 12534670000000,
      "isDelegate": true
    }
  })";

  EXPECT_CALL(connection.api.wallets, get(_)).Times(1).WillOnce(Return(response));

  const auto wallet = connection.api.wallets.get("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN");

  DynamicJsonDocument doc(300);
  DeserializationError error = deserializeJson(doc, wallet);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto address = data["address"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", address);

  const auto publicKey = data["publicKey"];
  ASSERT_STREQ(
      "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
      publicKey);

  uint64_t balance = data["balance"];
  ASSERT_TRUE(balance == 12534670000000);

  bool isDelegate = data["isDelegate"];
  ASSERT_TRUE(isDelegate);
}

/**/

TEST(api, test_wallets) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 421,
      "totalCount": 841,
      "next": "/v2/wallets?page=2",
      "previous": null,
      "self": "/v2/wallets?page=1",
      "first": "/v2/wallets?page=1",
      "last": "/v2/wallets?page=421"
    },
    "data": [
      {
        "address": "D59NTfV92ca9QevUydvMiFMFdubbCaAVCV",
        "publicKey": "037d035f08b3bad0d5bb605232c7aa41555693c480044dbeb797270a44c339da5a",
        "balance": 1023145260990,
        "isDelegate": false
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, all(_, _)).Times(1).WillOnce(Return(response));

  const auto wallets = connection.api.wallets.all(5, 1);

  DynamicJsonDocument doc(764);
  DeserializationError error = deserializeJson(doc, wallets);
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
  ASSERT_STREQ("D59NTfV92ca9QevUydvMiFMFdubbCaAVCV", address);

  const auto publicKey = dataZero["publicKey"];
  ASSERT_STREQ(
      "037d035f08b3bad0d5bb605232c7aa41555693c480044dbeb797270a44c339da5a",
      publicKey);

  uint64_t balance = dataZero["balance"];
  ASSERT_TRUE(balance >= 0);

  bool isDelegate = dataZero["isDelegate"];
  ASSERT_FALSE(isDelegate);
}

/**/

TEST(api, test_wallets_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 2,
      "totalCount": 3,
      "next": "/v2/wallets/search?page=2",
      "previous": null,
      "self": "/v2/wallets/search?page=1",
      "first": "/v2/wallets/search?page=1",
      "last": "/v2/wallets/search?page=2"
    },
    "data": [
      {
        "id": "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
        "blockId": "14847399772737279404",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "recipient": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "signature": "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
        "asset": {
          "votes": [
            "+0257b7724e97cd832e0c28533a86da5220656f9b5122141daab20e8526decce01f"
          ]
        },
        "confirmations": 1636029,
        "timestamp": {
          "epoch": 17094358,
          "unix": 1507195558,
          "human": "2017-10-05T09:25:58Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, search(_, _, _)).Times(1).WillOnce(Return(response));

  const std::map<std::string, std::string> body_parameters = {
    { "username", "baldninja" },
    { "address", "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T" },
    { "publicKey", "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d" }};
  const auto walletsSearch = connection.api.wallets.search(body_parameters, 5, 1);

  DynamicJsonDocument doc(1524);
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
      "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
      id);

  const auto blockId = dataZero["blockId"];
  ASSERT_STREQ("14847399772737279404", blockId);

  int type = dataZero["type"];
  ASSERT_EQ(3, type);

  uint64_t amount = dataZero["amount"];
  ASSERT_TRUE(0ULL == amount);

  uint64_t fee = dataZero["fee"];
  ASSERT_TRUE(100000000ULL == fee);

  const auto sender = dataZero["sender"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", sender);

  const auto recipient = dataZero["recipient"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", recipient);

  const auto signature = dataZero["signature"];
  ASSERT_STREQ(
      "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
      signature);

  int confirmations = dataZero["confirmations"];
  ASSERT_EQ(1636029, confirmations);

  JsonObject timestamp = dataZero["timestamp"];

  int epoch = timestamp["epoch"];
  ASSERT_EQ(17094358, epoch);

  int timestampUnix = timestamp["unix"];
  ASSERT_EQ(1507195558, timestampUnix);

  const auto human = timestamp["human"];
  ASSERT_STREQ("2017-10-05T09:25:58Z", human);
}

/**/

TEST(api, test_wallets_top) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
  "meta": {
    "count": 2,
    "pageCount": 97849,
    "totalCount": 195698,
    "next": "\/api\/v2\/wallets\/top?limit=2&page=2",
    "previous": null,
    "self": "\/api\/v2\/wallets\/top?limit=2&page=1",
    "first": "\/api\/v2\/wallets\/top?limit=2&page=1",
    "last": "\/api\/v2\/wallets\/top?limit=2&page=97849"
  },
  "data": [
    {
      "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
      "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
      "balance": 10105417471949050,
      "isDelegate": false
    },
    {
      "address": "DEyaFhDuaoQyKbFH4gJtYZvKkB6umyrEUj",
      "publicKey": "033c59dcdc36944cc28f68c1e4b47ac370fe326e53f9adf5f07764d3e8b74b1838",
      "username": "whalessio",
      "secondPublicKey": "03820f214bd49a09c636fa366b4b3c1a0dbd2953d14aac7e68a596e0636e662dfb",
      "balance": 2000035929999638,
      "isDelegate": true
    }
  ]
})";

  EXPECT_CALL(
      connection.api.wallets,
      top(_, _))
        .Times(1)
        .WillOnce(Return(response));

  const auto walletsTop = connection.api.wallets.top(2, 1);

  DynamicJsonDocument doc(1292);
  DeserializationError error = deserializeJson(doc, walletsTop);
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
  ASSERT_STREQ("D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax", address);

  const auto publicKey = dataZero["publicKey"];
  ASSERT_STREQ(
      "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
      publicKey);

  unsigned long long balance = dataZero["balance"];
  ASSERT_EQ(balance, 10105417471949050ULL);

  bool isDelegate = dataZero["isDelegate"];
  ASSERT_FALSE(isDelegate);

  JsonObject dataOne = doc["data"][1];

  const auto addressOne = dataOne["address"];
  ASSERT_STREQ("DEyaFhDuaoQyKbFH4gJtYZvKkB6umyrEUj", addressOne);

  const auto publicKeyOne = dataOne["publicKey"];
  ASSERT_STREQ(
      "033c59dcdc36944cc28f68c1e4b47ac370fe326e53f9adf5f07764d3e8b74b1838",
      publicKeyOne);

  unsigned long long balanceOne = dataOne["balance"];
  ASSERT_EQ(balanceOne, 2000035929999638ULL);

  const bool isDelegateOne = dataOne["isDelegate"];
  ASSERT_TRUE(isDelegateOne);
}

/**/

TEST(api, test_wallets_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 127430,
      "totalCount": 254860,
      "next": "/v2/wallets/boldninja/transactions?page=2",
      "previous": null,
      "self": "/v2/wallets/boldninja/transactions?page=1",
      "first": "/v2/wallets/boldninja/transactions?page=1",
      "last": "/v2/wallets/boldninja/transactions?page=127430"
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
        "confirmations": 1683,
        "timestamp": {
          "epoch": 32794053,
          "unix": 1522895253,
          "human": "2018-04-05T02:27:33Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactions(_, _, _)).Times(1).WillOnce(Return(response));

  const auto walletsTransactions = connection.api.wallets.transactions(
      "DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh",
      2, 1);

  DynamicJsonDocument doc(1420);
  DeserializationError error = deserializeJson(doc, walletsTransactions);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_EQ(2, count);
}

/**/

TEST(api, test_wallets_transactions_received) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 4,
      "totalCount": 8,
      "next": "/v2/wallets/boldninja/transactions/received?page=2",
      "previous": null,
      "self": "/v2/wallets/boldninja/transactions/received?page=1",
      "first": "/v2/wallets/boldninja/transactions/received?page=1",
      "last": "/v2/wallets/boldninja/transactions/received?page=4"
    },
    "data": [
      {
        "id": "c46a6a83f7a358f269691c16f050beeab669767643634086bc12ad1182d54413",
        "blockId": "17271524574301696572",
        "type": 0,
        "amount": 5000000000,
        "fee": 10000000,
        "sender": "DK6Q1Lufhb939H9EshLViYbaaKUkswMiUz",
        "recipient": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "signature": "304402204b81411e507273f2a27e6135510abda5bff00a0d3121977df09363227c8fd2360220503cab4484a7db785d91a7adcfad681811e3d73f2d00b4dab7e4190ecd41cb34",
        "vendorField": "More monopoly money for EVERYONE!!",
        "confirmations": 1482069,
        "timestamp": {
          "epoch": 18382414,
          "unix": 1508483614,
          "human": "2017-10-20T07:13:34Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactionsReceived(_, _, _)).Times(1).WillOnce(Return(response));

  const auto walletsTransactionsReceived = connection.api.wallets.transactionsReceived(
      "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
      2, 1);

  DynamicJsonDocument doc(1532);
  DeserializationError error = deserializeJson(doc, walletsTransactionsReceived);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);
}

/**/

TEST(api, test_wallets_transactions_sent) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 2,
      "totalCount": 4,
      "next": "/v2/wallets/boldninja/transactions/sent?page=2",
      "previous": null,
      "self": "/v2/wallets/boldninja/transactions/sent?page=1",
      "first": "/v2/wallets/boldninja/transactions/sent?page=1",
      "last": "/v2/wallets/boldninja/transactions/sent?page=2"
    },
    "data": [
      {
        "id": "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
        "blockId": "14847399772737279404",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "recipient": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "signature": "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
        "asset": {
          "votes": [
            "+0257b7724e97cd832e0c28533a86da5220656f9b5122141daab20e8526decce01f"
          ]
        },
        "confirmations": 1636232,
        "timestamp": {
          "epoch": 17094358,
          "unix": 1507195558,
          "human": "2017-10-05T09:25:58Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactionsSent(_, _, _)).Times(1).WillOnce(Return(response));

  const auto walletsTransactionsSent = connection.api.wallets.transactionsSent(
      "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
      2, 1);

  DynamicJsonDocument doc(1612);
  DeserializationError error = deserializeJson(doc, walletsTransactionsSent);
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
    "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
    id);

  const auto blockId = dataZero["blockId"];
  ASSERT_STREQ("14847399772737279404", blockId);

  const auto sender = dataZero["sender"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", sender);

  const auto recipient = dataZero["recipient"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", recipient);

  const auto signature = dataZero["signature"];
  ASSERT_STREQ(
      "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
      signature);
}

/**/

TEST(api, test_wallets_votes) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 2,
      "totalCount": 3,
      "next": "/v2/wallets/boldninja/votes?page=2",
      "previous": null,
      "self": "/v2/wallets/boldninja/votes?page=1",
      "first": "/v2/wallets/boldninja/votes?page=1",
      "last": "/v2/wallets/boldninja/votes?page=2"
    },
    "data": [
      {
        "id": "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
        "blockId": "14847399772737279404",
        "type": 3,
        "amount": 0,
        "fee": 100000000,
        "sender": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "recipient": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
        "signature": "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
        "asset": {
          "votes": [
            "+0257b7724e97cd832e0c28533a86da5220656f9b5122141daab20e8526decce01f"
          ]
        },
        "confirmations": 1636029,
        "timestamp": {
          "epoch": 17094358,
          "unix": 1507195558,
          "human": "2017-10-05T09:25:58Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, votes(_, _, _)).Times(1).WillOnce(Return(response));

  const auto walletsVotes = connection.api.wallets.votes("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 1, 1);

  DynamicJsonDocument doc(1612);
  DeserializationError error = deserializeJson(doc, walletsVotes);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_GT(count, 0);

  JsonObject dataZero = doc["data"][0];

  const auto id = dataZero["id"];
  ASSERT_STREQ(
    "08c6b23f9edd97b613f17153fb97a316a4fb83136e9842655dafc8262f363e0e",
    id);

  const auto blockId = dataZero["blockId"];
  ASSERT_STREQ("14847399772737279404", blockId);

  const auto sender = dataZero["sender"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", sender);

  const auto recipient = dataZero["recipient"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", recipient);

  const auto signature = dataZero["signature"];
  ASSERT_STREQ(
      "304402207ba0e8aaee93695360081b7ce713f13d62b544038ac440bd46357398af86cae6022059ac74586738be1ef622e0baba992d0e417d9aed7ab980f374eb0c9d53e25f8e",
      signature);
}
