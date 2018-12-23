
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;

/* test_two_transactions_transaction
 * https://dexplorer.ark.io:8443/api/v2/transactions/b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850
 * Expected Response:
    {
    "data": {
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
    }
 */
TEST(api, test_transaction)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.transactions, get("5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa"))
      .Times(1)
      .WillOnce(Return(response));

    const auto transaction = connection.api.transactions.get("5c6ce775447a5acd22050d72e2615392494953bb1fb6287e9ffb3c33eaeb79aa");

    DynamicJsonBuffer jsonBuffer(transaction.size());
    JsonObject& root = jsonBuffer.parseObject(transaction);

    JsonObject& data = root["data"];

    const char* id = data["id"];
    ASSERT_STREQ("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850", id);

    const char* blockId = data["blockId"];
    ASSERT_STREQ("4375573732170746923", blockId);

    int type = data["type"];
    ASSERT_EQ(3, type);

    uint64_t amount = data["amount"];
    ASSERT_TRUE(amount == 0);

    uint64_t fee = data["fee"];
    ASSERT_TRUE(fee == 100000000);

    const char* sender = data["sender"];
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", sender);

    const char* recipient = data["recipient"];
    ASSERT_STREQ("DKcFDN6mhLAheRAfmN6LT1e4AeyF1Fd9bY", recipient);

    const char* signature = data["signature"];
    ASSERT_STREQ("3045022100dc27398f4f3a24e55dc1ee87900de988254daa3fed71e82f4d6ef85ed4f9d9f8022025d71158cc15672863b2263622026ec19fa9cc9d2e8c78fa79eb2d8f4ef45fc7", signature);

    int confirmations = data["confirmations"];
    ASSERT_GT(confirmations, 0);


    JsonObject& timestamp = data["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_EQ(45024866, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_EQ(1535126066, timestampUnix);

    const char* human = timestamp["human"];
    ASSERT_STREQ("2018-08-24T15:54:26.000Z", human);
}

/* test_transactions_transaction_types
 * https://dexplorer.ark.io:8443/api/v2/transactions/types
 * Expected Response:
    {
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
    }
 */
TEST(api, test_transaction_types)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
			  "data": {
			    "TRANSFER": 0,
			    "SECOND_SIGNATURE": 1,
			    "DELEGATE_REGISTRATION": 2,
			    "VOTE": 3,
			    "MULTI_SIGNATURE": 4,
			    "IPFS": 5,
			    "TIMELOCK_TRANSFER": 6,
			    "MULTI_PAYMENT": 7,
			    "DELEGATE_RESIGNATION": 8
			  }
			})";

    EXPECT_CALL(connection.api.transactions, types())
      .Times(1)
      .WillOnce(Return(response));

    const auto types = connection.api.transactions.types();

    DynamicJsonBuffer jsonBuffer(types.size());
    JsonObject& root = jsonBuffer.parseObject(types);

    JsonObject& data = root["data"];

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

/* test_transactions_transaction_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "first": "/api/v2/transactions/unconfirmed?id=4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48&page=1&limit=100",
        "last": null
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_transaction_unconfirmed)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.transactions, getUnconfirmed("dummy"))
      .Times(1)
      .WillOnce(Return(response));

    const auto transactionUnconfirmed = connection.api.transactions.getUnconfirmed("dummy");

    DynamicJsonBuffer jsonBuffer(transactionUnconfirmed.size());
    JsonObject& root = jsonBuffer.parseObject(transactionUnconfirmed);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_GE(count, 0);

    int pageCount = meta["pageCount"];
    ASSERT_GE(pageCount, 0);

    int totalCount = meta["totalCount"];
    ASSERT_GE(totalCount, 0);
}

/* test_transactions_transactions
 * https://dexplorer.ark.io:8443/api/v2/transactions?limit=2&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions?limit=2&page=1",
        "first": "/api/v2/transactions?limit=2&page=1",
        "last": "/api/v2/transactions?limit=2&page=1"
    },
    "data": [
        {
        "id": "string",
        "blockId": "string",
        "type": ing,
        "amount": uint64_t,
        "fee": uint64_t,
        "sender": "string",
        "recipient": "string",
        "signature": "string",
        "vendorField": "string",
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
#if 0
TEST(api, test_transactions)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.transactions, all(2, 1)
      .Times(1)
      .WillOnce(Return(response));

    const auto transactions = connection.api.transactions.all(2, 1);

    DynamicJsonBuffer jsonBuffer(transactions.size());
    JsonObject& root = jsonBuffer.parseObject(transactions);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int type = dataZero["type"];
    ASSERT_EQ(0, type);

    uint64_t fee = dataZero["fee"];
    ASSERT_TRUE(fee >= 0);
}
#endif

/* test_transactions_transactions_unconfirmed
 * https://dexplorer.ark.io:8443/api/v2/transactions/unconfirmed?limit=2&page=1
 * Expected Response (if unconfirmed tx is not found):
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/transactions/unconfirmed?limit=2&page=1",
        "first": "/api/v2/transactions/unconfirmed?limit=2&page=1",
        "last": "string"
    },
    "data": [
        
    ]
    }
 */
TEST(api, test_transactions_unconfirmed)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.transactions, allUnconfirmed(5, 1))
      .Times(1)
      .WillOnce(Return(response));

    const auto transactionsUnconfirmed = connection.api.transactions.allUnconfirmed(5, 1);

    DynamicJsonBuffer jsonBuffer(transactionsUnconfirmed.size());
    JsonObject& root = jsonBuffer.parseObject(transactionsUnconfirmed);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_TRUE(count >= 0);

    int pageCount = meta["pageCount"];
    ASSERT_TRUE(pageCount >= 0);

    int totalCount = meta["totalCount"];
    ASSERT_TRUE(totalCount >= 0);
}

/* test_two_transactions_transactions_search_all
 *
 * Expected Response:
 */
TEST(api, test_two_transactions_search_all)
{
  Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::map<std::string, std::string> body = { };
  const auto transactions = connection.api.transactions.search(body, 5, 1);

  DynamicJsonBuffer jsonBuffer(transactions.size());
  JsonObject& root = jsonBuffer.parseObject(transactions);

  JsonObject& meta = root["meta"];

  int count = meta["count"];
  ASSERT_TRUE(count >= 0);

  int pageCount = meta["pageCount"];
  ASSERT_TRUE(pageCount >= 0);

  int totalCount = meta["totalCount"];
  ASSERT_TRUE(totalCount >= 0);
}

#if 0 // TODO
/* test_two_transactions_transactions_search
 * 
 * Expected Response:
 {
 "meta":{
  "count":1,
  "pageCount":1,
  "totalCount":1,
  "next":null,
  "previous":null,
  "self":"/api/v2/transactions/search?limit=5&page=1",
  "first":"/api/v2/transactions/search?limit=5&page=1",
  "last":"/api/v2/transactions/search?limit=5&page=1"},
  "data":[
    {
    "id":"927ab6da141cc4fa9f1a4b5765ee9ecdf92d47a9cd3aada35aa136ad7d3d3e37",
    "blockId":"13624088937920625389",
    "version":1,
    "type":3,
    "amount":0,
    "fee":84219776,
    "sender":"DMdq8j6uzxErZxESGu7JfkaCFt3qx11fqj",
    "recipient":"DMdq8j6uzxErZxESGu7JfkaCFt3qx11fqj",
    "signature":"3044022073337aefa7727cc1cf39e478ffe65cf5c66c5761b5848418d87307df250a68a5022053d4d5264b329e63cadad84fc6ec479fe5e430eaabd6177db1e9c283027ec2fa",
    "asset":
      {
      "votes":["+0389301207e25addec690be9efa3b2ca2d111b86386da7ff5fcc1c0344954b2acc"]
      },
    "confirmations":871,
    "timestamp":{"epoch":55498801,"unix":1545600001,"human":"2018-12-23T21:20:01.000Z"}
    }
  ]
}
 */
TEST(api, test_transactions_search)
{
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

    EXPECT_CALL(connection.api.transactions, search(5, 1))
      .Times(1)
      .WillOnce(Return(response));
	const std::map<std::string, std::string> body = {
	  {"id", "927ab6da141cc4fa9f1a4b5765ee9ecdf92d47a9cd3aada35aa136ad7d3d3e37"}
	};
	const auto transactions = connection.api.transactions.search(body, 5, 1);

	DynamicJsonBuffer jsonBuffer(transactions.size());
	JsonObject& root = jsonBuffer.parseObject(transactions);

	JsonObject& meta = root["meta"];

	int count = meta["count"];
	ASSERT_TRUE(count >= 0);

	int pageCount = meta["pageCount"];
	ASSERT_TRUE(pageCount >= 0);

	int totalCount = meta["totalCount"];
	ASSERT_TRUE(totalCount >= 0);

	JsonObject& data = root["data"][0];

	const char* id = data["id"];
	ASSERT_STREQ("927ab6da141cc4fa9f1a4b5765ee9ecdf92d47a9cd3aada35aa136ad7d3d3e37", id);

	int version = data["version"];
	ASSERT_EQ(1, version);

	const char* sender = data["sender"];
	ASSERT_STREQ("DMdq8j6uzxErZxESGu7JfkaCFt3qx11fqj", sender);

	const char* recipient = data["recipient"];
	ASSERT_STREQ("DMdq8j6uzxErZxESGu7JfkaCFt3qx11fqj", recipient);

	const char* signature = data["signature"];
	ASSERT_STREQ("3044022073337aefa7727cc1cf39e478ffe65cf5c66c5761b5848418d87307df250a68a5022053d4d5264b329e63cadad84fc6ec479fe5e430eaabd6177db1e9c283027ec2fa", signature);
}
#endif
