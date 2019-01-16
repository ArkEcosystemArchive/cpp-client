#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::Return;
using testing::_;

/* test_vote
 * https://dexplorer.ark.io:8443/api/v2/votes/d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2
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
TEST(api, test_vote) { // NOLINT
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "data": {
            "id": "beb8dd43c640f562704090159154b2742afba7eacada9e8edee447e34e7675c6",
            "blockId": "13661015019049808045",
            "type": 3,
            "amount": 0,
            "fee": 100000000,
            "sender": "DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ",
            "recipient": "DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ",
            "signature": "3045022100e9a743c5aa0df427f49af61d35fe617182479f7e8d368ce23b7ec43ab6d269c80220193aafd4ccb3eedbd76ded7ea99f31629013dc3af60540029fe98b274d42d284",
            "asset": {
                "votes": [
                    "+032fe001dff675a6edfe3d0e51201b2900d3b5050a46d770306aefaa574c022672"
                ]
            },
            "confirmations": 48189,
            "timestamp": {
                "epoch": 32338609,
                "unix": 1522439809,
                "human": "2018-03-30T19:56:49Z"
            }
        }
    })";

    EXPECT_CALL(connection.api.votes, get(_))
      .Times(1)
      .WillOnce(Return(response));

    const auto vote = connection.api.votes.get("beb8dd43c640f562704090159154b2742afba7eacada9e8edee447e34e7675c6");

    DynamicJsonBuffer jsonBuffer(vote.size());
    JsonObject& root = jsonBuffer.parseObject(vote);

    JsonObject& data = root["data"];

    const char* id = data["id"];
    ASSERT_STREQ("beb8dd43c640f562704090159154b2742afba7eacada9e8edee447e34e7675c6", id);

    const char* blockId = data["blockId"];
    ASSERT_STREQ("13661015019049808045", blockId);

    int type = data["type"];
    ASSERT_EQ(3, type);

    uint64_t amount = data["amount"];
    ASSERT_TRUE(amount == 0);

    uint64_t fee = data["fee"];
    ASSERT_TRUE(fee == 100000000);

    const char* sender = data["sender"];
    ASSERT_STREQ("DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ", sender);

    const char* recipient = data["recipient"];
    ASSERT_STREQ("DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ", recipient);

    const char* signature = data["signature"];
    ASSERT_STREQ("3045022100e9a743c5aa0df427f49af61d35fe617182479f7e8d368ce23b7ec43ab6d269c80220193aafd4ccb3eedbd76ded7ea99f31629013dc3af60540029fe98b274d42d284", signature);

    int confirmations = data["confirmations"];
    ASSERT_EQ(48189, confirmations);

    JsonObject& timestamp = data["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_EQ(32338609, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_EQ(1522439809, timestampUnix);

    const char* human = timestamp["human"];
    ASSERT_STREQ("2018-03-30T19:56:49Z", human);
}

/* test_votes
 * https://dexplorer.ark.io:8443/api/v2/votes?limit=5&page=1
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": "string",
        "previous": "string",
        "self": "/api/v2/votes?limit=5&page=1",
        "first": "/api/v2/votes?limit=5&page=1",
        "last": "/api/v2/votes?limit=5&page=1"
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
            "+string"
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
TEST(api, test_votes) { // NOLINT
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const std::string response = R"({
        "meta": {
            "count": 2,
            "pageCount": 658,
            "totalCount": 1315,
            "next": "/v2/votes?page=2",
            "previous": null,
            "self": "/v2/votes?page=1",
            "first": "/v2/votes?page=1",
            "last": "/v2/votes?page=658"
        },
        "data": [
            {
                "id": "560959e435cbf8eec60691890f3dd55d141e76077e1fe803f65d137c91099240",
                "blockId": "12872155462883631430",
                "type": 3,
                "amount": 0,
                "fee": 100000000,
                "sender": "DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ",
                "recipient": "DAp7JjULVgqzd4jLofkUyLRovHRPUTQwiZ",
                "signature": "30440220522eadff84b5b4b2fc6a3ef611bf093dbd0a06963c32c767ee28729898d0a1d302203f851594e5b2271a987e98daa4fc8b5f384fac65c41eb1c43739af2d4b5dc902",
                "asset": {
                    "votes": [
                        "-032fe001dff675a6edfe3d0e51201b2900d3b5050a46d770306aefaa574c022672"
                    ]
                },
                "confirmations": 39989,
                "timestamp": {
                    "epoch": 32414926,
                    "unix": 1522516126,
                    "human": "2018-03-31T17:08:46Z"
                }
            }
        ]
    })";

    EXPECT_CALL(connection.api.votes, all(_, _))
      .Times(1)
      .WillOnce(Return(response));

    const auto votes = connection.api.votes.all(5, 1);

    DynamicJsonBuffer jsonBuffer(votes.size());
    JsonObject& root = jsonBuffer.parseObject(votes);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int type = dataZero["type"];
    ASSERT_EQ(3, type);

    uint64_t fee = dataZero["fee"];
    ASSERT_GT(fee, 0);

    int confirmations = dataZero["confirmations"];
    ASSERT_NE(0, confirmations);
}
