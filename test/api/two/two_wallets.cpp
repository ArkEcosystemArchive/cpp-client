
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

/* test_two_vote_identifier
 * https://dexplorer.ark.io:8443/api/v2/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu
 * Expected Response:
    {
    "data": {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": uint64_t,
        "isDelegate": bool
    }
    }
 */
TEST(api, test_two_wallet) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto wallet = connection.api.wallets.get("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");

    DynamicJsonBuffer jsonBuffer(wallet.size());
    JsonObject& root = jsonBuffer.parseObject(wallet);

    JsonObject& data = root["data"];

    const char* address = data["address"];
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const char* publicKey = data["publicKey"];
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);

    uint64_t balance = data["balance"];
    ASSERT_TRUE(balance >= 0);

    bool isDelegate = data["isDelegate"];
    ASSERT_TRUE((isDelegate == true || isDelegate == false) == true);
}

/* test_two_wallets
 * https://dexplorer.ark.io:8443/api/v2/wallets?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/wallets?limit=5&page=2",
        "previous": "string",
        "self": "/api/v2/wallets?limit=5&page=1",
        "first": "/api/v2/wallets?limit=5&page=1",
        "last": "/api/v2/wallets?limit=5&page=19"
    },
    "data": [
        {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": uint64_t,
        "isDelegate": bool
        }
    ]
    }
 */
TEST(api, test_two_wallets) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto wallets = connection.api.wallets.all(5, 1);

    DynamicJsonBuffer jsonBuffer(wallets.size());
    JsonObject& root = jsonBuffer.parseObject(wallets);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    const char* address = dataZero["address"];
    ASSERT_STRNE("", address);

    const char* publicKey = dataZero["publicKey"];
    ASSERT_STRNE("", publicKey);

    uint64_t balance = dataZero["balance"];
    ASSERT_TRUE(balance >= 0);

    bool isDelegate = dataZero["isDelegate"];
    ASSERT_TRUE((isDelegate == true || isDelegate == false) == true);
}

/* test_two_wallets_search
 *
 * Expected Response:
    {
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/search?limit=5&page=1",
        "first": "\/api\/v2\/wallets\/search?limit=5&page=1",
        "last": "\/api\/v2\/wallets\/search?limit=5&page=1"
    },
    "data": [
        {
        "address": "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T",
        "publicKey": "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d",
        "secondPublicKey": null,
        "balance": 532210000000,
        "isDelegate": true
        }
    ]
    }
 */
TEST(api, test_two_wallets_search) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::map<std::string, std::string> body_parameters = {
      {"username", "baldninja"},
      {"address", "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T"},
      {"publicKey", "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"}
    };

    const auto walletsSearch = connection.api.wallets.search(body_parameters);

    DynamicJsonBuffer jsonBuffer(walletsSearch.size());
    JsonObject& root = jsonBuffer.parseObject(walletsSearch);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];;

    const char* address = dataZero["address"];
    ASSERT_STRNE("", address);

    const char* publicKey = dataZero["publicKey"];
    ASSERT_STRNE("", publicKey);
}

/* test_two_wallets_top_limit_page
 * https://dexplorer.ark.io:8443/api/v2/wallets/top?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/wallets/top?limit=5&page=2",
        "previous": "string",
        "self": "/api/v2/wallets/top?limit=5&page=1",
        "first": "/api/v2/wallets/top?limit=5&page=1",
        "last": "/api/v2/wallets/top?limit=5&page=19"
    },
    "data": [
        {
        "address": "string",
        "publicKey": "string",
        "secondPublicKey": "string",
        "balance": uint64_t,
        "isDelegate": bool
        }
    ]
    }
 */
TEST(api, test_two_wallets_top) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsTop = connection.api.wallets.top(5, 1);

    DynamicJsonBuffer jsonBuffer(walletsTop.size());
    JsonObject& root = jsonBuffer.parseObject(walletsTop);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    const char* address = dataZero["address"];
    ASSERT_STRNE("", address);

    uint64_t balance = dataZero["balance"];
    ASSERT_TRUE(balance >= 0);

    bool isDelegate = dataZero["isDelegate"];
    // as long as data was read, we don't really care (or know) what the expected value is
    ASSERT_TRUE(isDelegate || !isDelegate);
}

/* test_two_wallets_transactions
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1
 * Expected Response:
  {
    "meta": {
      "count": int,
      "pageCount": int,
      "totalCount": "string",
      "next": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=2",
      "previous": "string",
      "self": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1",
      "first": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=2&page=1",
      "last": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\transactions?limit=2&page=3"
    },
    "data": [
      {
        "id": "string",
        "blockId": "string",
        "type": int,
        "amount": uint64_t,
        "fee": uint64_t,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "confirmations": int,
        "timestamp": {
          "epoch": int,
          "unix": int,
          "human": "string"
        }
      }
    ]
  }
 */
TEST(api, test_two_wallets_transactions) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsTransactions = connection.api.wallets.transactions("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    DynamicJsonBuffer jsonBuffer(walletsTransactions.size());
    JsonObject& root = jsonBuffer.parseObject(walletsTransactions);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);
}

/* test_two_wallets_transactions_received
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1",
        "first": "/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=2&page=1",
        "last": "string"
    },
    "data": [

    ]
    }
 */
TEST(api, test_two_wallets_transactions_received) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsTransactionsReceived = connection.api.wallets.transactionsReceived("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    DynamicJsonBuffer jsonBuffer(walletsTransactionsReceived.size());
    JsonObject& root = jsonBuffer.parseObject(walletsTransactionsReceived);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);
}

/* test_two_wallets_transactions_sent
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/sent?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": 0,
        "pageCount": 0,
        "totalCount": 0,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/sent?limit=2&page=1",
        "first": "\/api\/v2\/wallets\/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk\/transactions\/sent?limit=2&page=1",
        "last": null
    },
    "data": [

    ]
    }
 */
TEST(api, test_two_wallets_transactions_sent) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);
 
    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsTransactionsSent = connection.api.wallets.transactionsSent("DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 2, 1);

    DynamicJsonBuffer jsonBuffer(walletsTransactionsSent.size());
    JsonObject& root = jsonBuffer.parseObject(walletsTransactionsSent);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);
}

/* test_two_wallets_votes
 * https://dexplorer.ark.io:8443/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=1&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1",
        "first": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1",
        "last": "/api/v2/wallets/DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9/votes?limit=2&page=1"
    },
    "data": [
        {
        "id": "string",
        "blockId": "string",
        "type": int,
        "amount": uint64_t,
        "fee": uint64_t,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "asset": {
            "votes": [
            "string"
            ]
        },
        "confirmations": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
        }
    ]
    }
 */
TEST(api, test_two_wallets_votes) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsVotes = connection.api.wallets.votes("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", 1, 1);

    DynamicJsonBuffer jsonBuffer(walletsVotes.size());
    JsonObject& root = jsonBuffer.parseObject(walletsVotes);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_GT(count, 0);

    JsonObject& data = root["data"][0];

    const char* sender = data["sender"];
    ASSERT_STREQ("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", sender);
}
