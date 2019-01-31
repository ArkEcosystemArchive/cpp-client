
#include "arkClient.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mocks/mock_api.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

/* test_delegates_delegate
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
TEST(api, test_delegate) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
        "data": {
            "username": "boldninja",
            "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
            "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d",
            "votes": 0,
            "rank": 29,
            "blocks": {
                "produced": 0,
                "missed": 0,
                "last": {
                    "id": "10652480998435361357",
                    "timestamp": {
                        "epoch": 32816112,
                        "unix": 1522917312,
                        "human": "2018-04-05T08:35:12Z"
                    }
                }
            },
            "production": {
                "approval": "0.10",
                "productivity": "0.00"
            }
        }
    })";

  EXPECT_CALL(connection.api.delegates, get(_)).Times(1).WillOnce(Return(expected_response));

  const auto delegateResponse = connection.api.delegates.get("boldninja");

  DynamicJsonBuffer jsonBuffer(delegateResponse.size());
  JsonObject& root = jsonBuffer.parseObject(delegateResponse);

  JsonObject& data = root["data"];

  const char* username = data["username"];
  ASSERT_STREQ("boldninja", username);

  const char* address = data["address"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", address);

  const char* publicKey = data["publicKey"];
  ASSERT_STREQ("022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d", publicKey);

  uint64_t votes = data["votes"];
  ASSERT_EQ(0, votes);

  int rank = data["rank"];
  ASSERT_EQ(29, rank);

  JsonObject& blocks = data["blocks"];

  int produced = blocks["produced"];
  ASSERT_EQ(0, produced);

  int missed = blocks["missed"];
  ASSERT_EQ(0, missed);

  JsonObject& last = blocks["last"];

  const char* last_id = last["id"];
  ASSERT_STREQ("10652480998435361357", last_id);

  JsonObject& timestamp = last["timestamp"];

  uint64_t epoch = timestamp["epoch"];
  ASSERT_TRUE(32816112ull == epoch);

  uint64_t unix_timestamp = timestamp["unix"];
  ASSERT_TRUE(1522917312ull == unix_timestamp);

  const char* human = timestamp["human"];
  ASSERT_STREQ("2018-04-05T08:35:12Z", human);

  JsonObject& production = data["production"];

  double approval = production["approval"];
  ASSERT_EQ(0.10, approval);

  double productivity = production["productivity"];
  ASSERT_EQ(0.0, productivity);
}

/* test_delegates_delegate_blocks
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
TEST(api, test_delegate_blocks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
        "meta": {
            "count": 2,
            "pageCount": 29919,
            "totalCount": 59838,
            "next": "/v2/delegates/boldninja/blocks?page=2",
            "previous": null,
            "self": "/v2/delegates/boldninja/blocks?page=1",
            "first": "/v2/delegates/boldninja/blocks?page=1",
            "last": "/v2/delegates/boldninja/blocks?page=29919"
        },
        "data": [
            {
                "id": "10652480998435361357",
                "version": 0,
                "height": 3035318,
                "previous": "12548322724277171379",
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
                    "username": "boldninja",
                    "address": "DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN",
                    "publicKey": "022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d"
                },
                "signature": "3044022034e754a3ff70adba6323517e1297c6a9f30176df2ac589661e9206fe60a203120220182c38da201fee20e803bb7725fe9618d6707547e6d7b757d4108f546934fe1c",
                "transactions": 0,
                "timestamp": {
                    "epoch": 32816112,
                    "unix": 1522917312,
                    "human": "2018-04-05T08:35:12Z"
                }
            }
        ]
    })";

  EXPECT_CALL(connection.api.delegates, blocks(_, _, _)).Times(1).WillOnce(Return(expected_response));

  const auto delegateBlocksResponse = connection.api.delegates.blocks("boldninja", 3, 1);

  DynamicJsonBuffer jsonBuffer(delegateBlocksResponse.size());
  JsonObject& root = jsonBuffer.parseObject(delegateBlocksResponse);

  JsonObject& meta = root["meta"];

  int count = meta["count"];
  ASSERT_EQ(2, count);

  int pageCount = meta["pageCount"];
  ASSERT_EQ(29919, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_EQ(59838, totalCount);

  const char* id = root["data"][0]["id"];
  ASSERT_STREQ("10652480998435361357", id);

  int version = root["data"][0]["version"];
  ASSERT_EQ(0, version);

  uint64_t height = root["data"][0]["height"];
  ASSERT_TRUE(3035318ull == height);

  const char* previous = root["data"][0]["previous"];
  ASSERT_STREQ("12548322724277171379", previous);

  const char* username = root["data"][0]["generator"]["username"];
  ASSERT_STREQ("boldninja", username);

  const char* address = root["data"][0]["generator"]["address"];
  ASSERT_STREQ("DARiJqhogp2Lu6bxufUFQQMuMyZbxjCydN", address);

  const char* publicKey = root["data"][0]["generator"]["publicKey"];
  ASSERT_STREQ("022cca9529ec97a772156c152a00aad155ee6708243e65c9d211a589cb5d43234d", publicKey);
}

/* test_delegates_delegate_voters
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
TEST(api, test_delegate_voters) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
        "meta": {
            "count": 2,
            "pageCount": 10,
            "totalCount": 19,
            "next": "/v2/delegates/boldninja/voters?page=2",
            "previous": null,
            "self": "/v2/delegates/boldninja/voters?page=1",
            "first": "/v2/delegates/boldninja/voters?page=1",
            "last": "/v2/delegates/boldninja/voters?page=10"
        },
        "data": [
            {
                "address": "D5mbS6mpP5UheuciNscpDLgC127kYjRtkK",
                "publicKey": "03f7e0b1ab14985990416f72ed0b206c20b9efa35156e4528c8ff749fa0eea5d5a",
                "balance": 400000000,
                "isDelegate": false
            }
        ]
    })";

  EXPECT_CALL(connection.api.delegates, voters(_, _, _)).Times(1).WillOnce(Return(expected_response));

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
  ASSERT_STREQ("D5mbS6mpP5UheuciNscpDLgC127kYjRtkK", address);

  const char* publicKey = dataZero["publicKey"];
  ASSERT_STREQ("03f7e0b1ab14985990416f72ed0b206c20b9efa35156e4528c8ff749fa0eea5d5a", publicKey);

  bool isDelegate = dataZero["isDelegate"];
  ASSERT_FALSE(isDelegate);
}

/* test_delegates_delegates
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
TEST(api, test_delegates) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  auto apiVersion = connection.api.version();
  ASSERT_EQ(2, apiVersion);

  const std::string expected_response = R"({
        "meta": {
            "count": 2,
            "pageCount": 99,
            "totalCount": 197,
            "next": "/v2/delegates?page=2",
            "previous": null,
            "self": "/v2/delegates?page=1",
            "first": "/v2/delegates?page=1",
            "last": "/v2/delegates?page=99"
        },
        "data": [
            {
                "username": "dark_jmc",
                "address": "D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz",
                "publicKey": "02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586",
                "votes": 0,
                "rank": 1,
                "blocks": {
                    "produced": 0,
                    "missed": 0,
                    "last": {
                        "id": "12383884455448354193",
                        "timestamp": {
                            "epoch": 31784600,
                            "unix": 1521885800,
                            "human": "2018-03-24T10:03:20Z"
                        }
                    }
                },
                "production": {
                    "approval": "0.08",
                    "productivity": "0.00"
                }
            }
        ]
    })";

  EXPECT_CALL(connection.api.delegates, all(5, 1)).Times(1).WillOnce(Return(expected_response));

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
  ASSERT_STREQ("dark_jmc", username);

  const char* address = dataZero["address"];
  ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", address);

  const char* publicKey = dataZero["publicKey"];
  ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", publicKey);

  uint64_t votes = dataZero["votes"];
  ASSERT_TRUE(0ull == votes);
}
