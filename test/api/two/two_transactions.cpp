
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

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
TEST(api, test_two_transaction)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto transaction = connection.api.transactions.get("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850");

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
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

/* test_two_transactions_transaction_unconfirmed
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
TEST(api, test_two_transaction_unconfirmed)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto transactionUnconfirmed = connection.api.transactions.getUnconfirmed("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");

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

/* test_two_transactions_transactions
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
TEST(api, test_two_transactions)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

/* test_two_transactions_transactions_unconfirmed
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
TEST(api, test_two_transactions_unconfirmed)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

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

/* test_two_transactions_transactions_search
 * 
 * Expected Response:
 */
TEST(api, test_two_transactions_search)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto transactions = connection.api.transactions.get("4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48", 5, 1);

    // DynamicJsonBuffer jsonBuffer(transactions.size());
    // JsonObject& root = jsonBuffer.parseObject(transactions);
}
