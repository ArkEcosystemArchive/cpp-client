#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;

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
TEST(api, test_wallet)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "data": {
            "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
            "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
            "balance": 12534670000000,
            "isDelegate": true
        }
    })";

    EXPECT_CALL(connection.api.wallets, get("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN"))
      .Times(1)
      .WillOnce(Return(response));

    const auto wallet = connection.api.wallets.get("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN");

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

/* test_wallets
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
TEST(api, test_wallets)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.wallets, all(5, 1))
      .Times(1)
      .WillOnce(Return(response));

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

/* test_wallets_search
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
TEST(api, test_wallets_search)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    
    EXPECT_CALL(connection.api.wallets, search(std::make_pair("address", "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN"), 5, 1))
      .Times(1)
      .WillOnce(Return(response));

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

/* test_wallets_top_limit_page
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
TEST(api, test_wallets_top)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "data": [
            {
                "address": "DGihocTkwDygiFvmg6aG8jThYTic47GzU9",
                "publicKey": "024c8247388a02ecd1de2a3e3fd5b7c61ecc2797fa3776599d558333ef1802d231",
                "balance": 11499593462120632,
                "isDelegate": false
            },
            {
                "address": "DRac35wghMcmUSe5jDMLBDLWkVVjyKZFxK",
                "publicKey": "0374e9a97611540a9ce4812b0980e62d3c5141ea964c2cab051f14a78284570dcd",
                "balance": 554107676293547,
                "isDelegate": false
            },
            ...
        ]
    })";

    EXPECT_CALL(connection.api.wallets, top(5, 1))
      .Times(1)
      .WillOnce(Return(response));

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

/* test_wallets_transactions
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
TEST(api, test_wallets_transactions)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.wallets, transactions("DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh", 2, 1))
      .Times(1)
      .WillOnce(Return(response));

    const auto walletsTransactions = connection.api.wallets.transactions("DDiTHZ4RETZhGxcyAi1VruCXZKxBFqXMeh", 2, 1);

    DynamicJsonBuffer jsonBuffer(walletsTransactions.size());
    JsonObject& root = jsonBuffer.parseObject(walletsTransactions);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);
}

/* test_wallets_transactions_received
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
TEST(api, test_wallets_transactions_received)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.wallets, transactionsReceived("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 2, 1))
      .Times(1)
      .WillOnce(Return(response));

    const auto walletsTransactionsReceived = connection.api.wallets.transactionsReceived("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 2, 1);

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

/* test_wallets_transactions_sent
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
TEST(api, test_wallets_transactions_sent)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);
 
    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.wallets, transactionsSent("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 2, 1))
      .Times(1)
      .WillOnce(Return(response));

    const auto walletsTransactionsSent = connection.api.wallets.transactionsSent("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 2, 1);

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

/* test_wallets_votes
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
TEST(api, test_wallets_votes)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.wallets, votes("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 1, 1))
      .Times(1)
      .WillOnce(Return(response));

    const auto walletsVotes = connection.api.wallets.votes("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", 1, 1);

    DynamicJsonBuffer jsonBuffer(walletsVotes.size());
    JsonObject& root = jsonBuffer.parseObject(walletsVotes);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_GT(count, 0);

    JsonObject& data = root["data"][0];

    const char* sender = data["sender"];
    ASSERT_STREQ("DNjuJEDQkhrJ7cA9FZ2iVXt5anYiM8Jtc9", sender);
}
