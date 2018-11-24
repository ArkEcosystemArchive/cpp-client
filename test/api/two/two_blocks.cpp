
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

/* test_two_blocks_block
 * https://dexplorer.ark.io:8443/api/v2/blocks/13114381566690093367
 * Expected Response:
    {
        "data": {
            "id": "string",
            "version": ing,
            "height": uint64_t,
            "previous": "string",
            "forged": {
                "reward": int,
                "fee": int,
                "total": int
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
    }
 */
TEST(api, test_two_block)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto blockResponse = connection.api.blocks.get("13114381566690093367");

    DynamicJsonBuffer jsonBuffer(blockResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockResponse);
 
    JsonObject& data = root["data"];

    const char* id = data["id"];
    ASSERT_STREQ("13114381566690093367", id);

    int version = data["version"];
    ASSERT_EQ(0, version);

    int height = data["height"];
    ASSERT_EQ(1, height);


    JsonObject& forged = data["forged"];

    uint64_t reward = forged["reward"];
    ASSERT_TRUE(reward >= 0);

    uint64_t fee = forged["fee"];
    ASSERT_TRUE(fee == 0);

    uint64_t total = forged["total"];
    ASSERT_TRUE(total == 0);


    JsonObject& payload = data["payload"];

    const char* hash = payload["hash"];
    ASSERT_STREQ("2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867", hash);

    int length = payload["length"];
    ASSERT_EQ(11395, length);


    JsonObject& generator = data["generator"];

    const char* address = generator["address"];
    ASSERT_STREQ("D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax", address);

    const char* publicKey = generator["publicKey"];
    ASSERT_STREQ("03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff", publicKey);


    const char* signature = data["signature"];
    ASSERT_STREQ("3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae", signature);

    int transactions = data["transactions"];
    ASSERT_EQ(52, transactions);


    JsonObject& timestamp = data["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_EQ(0, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_EQ(1490101200, timestampUnix);

    const char* human = timestamp["human"];
    ASSERT_STREQ("2017-03-21T13:00:00Z", human);
}

/* test_two_blocks_block_transactions
 * https://dexplorer.ark.io:8443/api/v2/blocks/9269622721511437262/transactions
 * Espected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": int,
        "next": null,
        "previous": null,
        "self": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
        "first": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100",
        "last": "\/api\/v2\/blocks\/13114381566690093367\/transactions?page=1&limit=100"
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
TEST(api, test_two_block_transactions)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto blockTransactionsResponse = connection.api.blocks.transactions("9269622721511437262");

    DynamicJsonBuffer jsonBuffer(blockTransactionsResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blockTransactionsResponse);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_EQ(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_EQ(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_EQ(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int id = dataZero["id"];
    ASSERT_NE(0, id);

    const char* blockId = dataZero["blockId"];
    ASSERT_STRNE("", blockId);

    int type = dataZero["type"];
    ASSERT_NE(0, type);

    uint64_t amount = dataZero["amount"];
    ASSERT_TRUE(amount >= 0);

    uint64_t fee = dataZero["fee"];
    ASSERT_TRUE(fee >= 0);

    const char* sender = dataZero["sender"];
    ASSERT_STRNE("", sender);

    const char* signature = dataZero["signature"];
    ASSERT_STRNE("", signature);

    int confirmations = dataZero["confirmations"];
    ASSERT_NE(0, confirmations);


    JsonObject& timestamp = dataZero["timestamp"];

    int epoch = timestamp["epoch"];
    ASSERT_NE(0, epoch);

    int timestampUnix = timestamp["unix"];
    ASSERT_NE(0, timestampUnix);

    const char* human = timestamp["human"];
    ASSERT_STRNE("", human);
}

/* test_two_blocks_blocks
 * https://dexplorer.ark.io:8443/api/v2/blocks
 * Expected Response:
    {
        "meta": {
            "count": int,
            "pageCount": int,
            "totalCount": int,
            "next": "string",
            "previous": "string",
            "self": "/api/v2/blocks?limit=10&page=1",
            "first": "/api/v2/blocks?limit=10&page=1",
            "last": "/api/v2/blocks?limit=10&page=1"
        },
        "data": [
        {
            "id": "string",
            "version": int,
            "height": int,
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
TEST(api, test_two_blocks)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto blocksResponse = connection.api.blocks.all();

    DynamicJsonBuffer jsonBuffer(blocksResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blocksResponse);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int version = dataZero["version"];
    ASSERT_NE(0, version);
}

/* test_two_blocks_blocks_limit_page
 * https://dexplorer.ark.io:8443/api/v2/blocks?limit=10&page=1
 * Expected Response:
    {
        "meta": {
            "count": int,
            "pageCount": int,
            "totalCount": int,
            "next": null,
            "previous": null,
            "self": "\api/v2/blocks?limit=10&page=1",
            "first": "/api/v2/blocks?limit=10&page=1",
            "last": "/api/v2/blocks?limit=10&page=1"
        },
        "data":
        [
            {
                "id": "string",
                "version": int,
                "height": int,
                "previous": "string",
                "forged": {
                    "reward": uint64_t,
                    "fee": uint64_t,
                    "total": uint64_t
                },
                "payload": {
                    "hash": "string",
                    "length": ing
                },
                "generator": {
                    "username": "string",
                    "address": "string",
                    "publicKey": "string"
                },
                "signature": "string",
                "transactions": ing,
                "timestamp": {
                    "epoch": int,
                    "unix": int,
                    "human": "string"
                }
            }
        ]
    }
 */
TEST(api, test_two_blocks_limit_page)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto blocksResponse = connection.api.blocks.all(5, 1);

    DynamicJsonBuffer jsonBuffer(blocksResponse.size());
    JsonObject& root = jsonBuffer.parseObject(blocksResponse);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    int version = dataZero["version"];
    ASSERT_NE(0, version);
}

/* test_two_blocks_search
 *
 * Expected Response:
    {
    "meta": {
        "count": int,
        "pageCount": int,
        "totalCount": "1",
        "next": "string",
        "previous": "string",
        "self": "/api/v2/blocks/search?limit=5&page=1",
        "first": "/api/v2/blocks/search?limit=5&page=1",
        "last": "/api/v2/blocks/search?limit=5&page=1"
    },
    "data": [
        {
        "id": "8337447655053578871",
        "version": 0,
        "height": 118783,
        "previous": "6440284271011893973",
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
            "username": "genesis_46",
            "address": "DGKgCQ1srb8HZyr47RqQqMvGZ4cDyr4eMo",
            "publicKey": "029a20963b506afabb2bd805830a46cef8d59218cd88c0dca9d2a0158045b1c3e0"
        },
        "signature": "304402201ec15a9bec30bad58c7d9f5ccf1447bccb36b39901d0b91f09217bb4c3efcf6a02207232bdfe9ab6e4d80eb2668d642b431ca704cf4ba8ce9958cfd202070e31f2c8",
        "transactions": 0,
        "timestamp": {
            "epoch": 45988754,
            "unix": 1536089954,
            "human": "2018-09-04T19:39:14Z"
        }
        }
    ]
    }
 */
TEST(api, test_two_blocks_search)
{
    Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.55", 4003);

    auto apiVersion = connection.api.version();
    ASSERT_EQ(2, apiVersion);

    const auto walletsSearch = connection.api.blocks.search({"id", "8337447655053578871"});

    DynamicJsonBuffer jsonBuffer(walletsSearch.size());
    JsonObject& root = jsonBuffer.parseObject(walletsSearch);

    JsonObject& meta = root["meta"];

    int count = meta["count"];
    ASSERT_NE(0, count);

    int pageCount = meta["pageCount"];
    ASSERT_NE(0, pageCount);

    int totalCount = meta["totalCount"];
    ASSERT_NE(0, totalCount);


    JsonObject& dataZero = root["data"][0];

    const char* id = dataZero["id"];
    ASSERT_STREQ("8337447655053578871", id);

    const char* previous = dataZero["previous"];
    ASSERT_STREQ("6440284271011893973", previous);


    JsonObject& generator = dataZero["generator"];

    const char* username = generator["username"];
    ASSERT_STREQ("genesis_46", username);
}
