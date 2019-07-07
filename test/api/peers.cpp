
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mocks/mock_api.h"

#include "arkClient.h"
#include "utils/json.h"

using testing::_;
using testing::Return;

TEST(api, test_peer) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.54", 4003);

  const std::string response = R"({
    "data": {
      "ip": "167.114.29.55",
      "port": 4002,
      "version": "1.1.1",
      "status": 200,
      "os": "linux",
      "latency": 355
    }
  })";

  EXPECT_CALL(connection.api.peers, get(_)).Times(1).WillOnce(Return(response));

  const auto peer = connection.api.peers.get("167.114.29.49");

  DynamicJsonDocument doc(292);
  DeserializationError error = deserializeJson(doc, peer);
  if (error) { exit(0); }

  JsonObject data = doc["data"];

  const auto ip = data["ip"];
  ASSERT_STREQ("167.114.29.55", ip);

  int port = data["port"];
  ASSERT_EQ(4002, port);

  const auto version = data["version"];
  ASSERT_STREQ("1.1.1", version);

  int status = data["status"];
  ASSERT_EQ(200, status);

  const auto os = data["os"];
  ASSERT_STREQ("linux", os);

  int latency = data["latency"];
  ASSERT_EQ(355, latency);
}

/**/

TEST(api, test_peers) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string response = R"({
    "meta": {
      "count": 2,
      "pageCount": 1,
      "totalCount": 2,
      "next": null,
      "previous": null,
      "self": "/v2/peers?page=1",
      "first": "/v2/peers?page=1",
      "last": "/v2/peers?page=1"
    },
    "data": [
      {
        "ip": "167.114.29.53",
        "port": 4002,
        "version": "1.1.1",
        "status": 200,
        "os": "linux",
        "latency": 1390
      }
    ]
  })";

  EXPECT_CALL(connection.api.peers, all(_, _)).Times(1).WillOnce(Return(response));

  const auto peers = connection.api.peers.all(5, 1);

  DynamicJsonDocument doc(724);
  DeserializationError error = deserializeJson(doc, peers);
  if (error) { exit(0); }

  JsonObject meta = doc["meta"];

  int count = meta["count"];
  ASSERT_NE(0, count);

  int pageCount = meta["pageCount"];
  ASSERT_NE(0, pageCount);

  int totalCount = meta["totalCount"];
  ASSERT_NE(0, totalCount);

  JsonObject dataZero = doc["data"][0];

  const auto ip = dataZero["ip"];
  ASSERT_STREQ("167.114.29.53", ip);

  int port = dataZero["port"];
  ASSERT_EQ(4002, port);

  const auto version = dataZero["version"];
  ASSERT_STREQ("1.1.1", version);

  int status = dataZero["status"];
  ASSERT_EQ(200, status);

  const auto os = dataZero["os"];
  ASSERT_STREQ("linux", os);

  int latency = dataZero["latency"];
  ASSERT_EQ(1390, latency);
}
