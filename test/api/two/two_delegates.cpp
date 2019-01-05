
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

/* test_two_delegates_delegate
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja
 * Expected Response:
    {
        "data": {
            "username": "string",
            "address": "string",
            "publicKey": "string",
            "votes": uint64_t,
            "rank": ing,
            "blocks": {
                "produced": int,
                "missed": int,
                "last": {
                    "id": "string",
                    "timestamp": {
                        "epoch": int,
                        "unix": int,
                        "human": "string"
                    }
                }
            },
            "production": {
                "approval": double,
                "productivity": double
            }
        }
    }
 */
TEST(api, test_two_delegate) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto delegateResponse = connection.api.delegates.get("boldninja");

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& data = root["data"];

    const char* username = data["username"];
    ASSERT_STREQ("boldninja", username);

    const char* address = data["address"];
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const char* publicKey = data["publicKey"];
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);

    uint64_t votes = data["votes"];
    ASSERT_GE(votes, 0);

    int rank = data["rank"];
    ASSERT_NE(0, rank);


    JsonObject& blocks = data["blocks"];

    int produced = blocks["produced"];
    ASSERT_NE(0, produced);

    int missed = blocks["missed"];
    ASSERT_GE(missed, 0);


    JsonObject& production = data["production"];

    double approval = production["approval"];
    ASSERT_NE(100.00, approval);

    double productivity = production["productivity"];
    ASSERT_NE(100.00, productivity);
}

/* test_two_delegates_delegate_blocks
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/blocks?limit=3&page=1
 * 
 * currently returning:
 *  {
 *      "statusCode": 500,
 *      "error": "Internal Server Error",
 *      "message": "An internal server error occurred"
 *  }
 * 
 * -
 * 
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/delegates/boldninja/blocks?limit=3&page=1",
        "first": "/api/v2/delegates/boldninja/blocks?limit=3&page=1",
        "last": "/api/v2/delegates/boldninja/blocks?limit=3&page=1"
    },
    "data": [
        {
        "id": "string",
        "version": int,
        "height": uint64_t,
        "previous": "string",
        "forged": {
            "reward": uint64_t,
            "fee": uint64_t,
            "total": uint64_t
        },
        "payload": {
            "hash": "string",
            "length": int
        },
        "generator": {
            "username": "string",
            "address": "string",
            "publicKey": "string"
        },
        "signature": "string",
        "transactions": int,
        "timestamp": {
            "epoch": int,
            "unix": int,
            "human": "string"
        }
        }
    ]
    }
 */
TEST(api, test_two_delegate_blocks) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    const auto delegateBlocksResponse = connection.api.delegates.blocks("boldninja", 3, 1);

    DynamicJsonBuffer jsonBuffer(delegateBlocksResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateBlocksResponse);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);

    const char* id = root["data"][0]["id"];
    ASSERT_STRNE("", id);

    int version = root["data"][0]["version"];
    ASSERT_EQ(0, version);

    uint64_t height = root["data"][0]["height"];
    ASSERT_TRUE(height >= 0);

    const char* previous = root["data"][0]["previous"];
    ASSERT_STRNE("0", previous);

    const char* username = root["data"][0]["generator"]["username"];
    ASSERT_STREQ("boldninja", username);

    const char* address = root["data"][0]["generator"]["address"];
    ASSERT_STREQ("DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", address);

    const char* publicKey = root["data"][0]["generator"]["publicKey"];
    ASSERT_STREQ("023ee98f453661a1cb765fd60df95b4efb1e110660ffb88ae31c2368a70f1f7359", publicKey);
}


/* test_two_delegates_delegate_voters
 * https://dexplorer.ark.io:8443/api/v2/delegates/boldninja/voters?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/delegates/boldninja/voters?limit=5&page=1",
        "first": "/api/v2/delegates/boldninja/voters?limit=5&page=1",
        "last": "/api/v2/delegates/boldninja/voters?limit=5&page=1"
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
TEST(api, test_two_delegate_voters) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto delegateVotersResponse = connection.api.delegates.voters("boldninja", 5, 1);

    DynamicJsonBuffer jsonBuffer(delegateVotersResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateVotersResponse);

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

    bool isDelegate = dataZero["isDelegate"];
    ASSERT_TRUE(isDelegate || !isDelegate);
}

/* test_two_delegates_delegates
 * https://dexplorer.ark.io:8443/api/v2/delegates?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "/api/v2/delegates?limit=5&page=2",
        "previous": null,
        "self": "/api/v2/delegates?limit=5&page=1",
        "first": "/api/v2/delegates?limit=5&page=1",
        "last": "/api/v2/delegates?limit=5&page=23"
    },
    "data": [
        {
        "username": "string",
        "address": "string",
        "publicKey": "string",
        "votes": uint64_t,
        "rank": int,
        "blocks": {
            "produced": int,
            "missed": int,
            "last": {
                "id": "string",
                "timestamp": {
                    "epoch": int,
                    "unix": int,
                    "human": "string"
                }
            }
        },
        "production": {
            "approval": double,
            "productivity": double
        }
        }
    ]
    }
 */
TEST(api, test_two_delegates) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto delegates = connection.api.delegates.all(5, 1);

    DynamicJsonBuffer jsonBuffer(delegates.size());
    JsonObject& root = jsonBuffer.parseObject(delegates);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);

    JsonObject& dataZero = root["data"][0];

    const char* username = dataZero["username"];
    ASSERT_STRNE("", username);

    const char* address = dataZero["address"];
    ASSERT_STRNE("", address);

    const char* publicKey = dataZero["publicKey"];
    ASSERT_STRNE("", publicKey);

    uint64_t votes = dataZero["votes"];
    ASSERT_TRUE(votes >= 0);
}
