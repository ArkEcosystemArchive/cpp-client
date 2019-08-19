
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::_;
using testing::Return;

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
}  // namespace

/**/

TEST(api, test_peer) {
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "ip": "167.114.29.49",
      "port": 4002,
      "ports": {
        "@arkecosystem/core-exchange-json-rpc": -1,
        "@arkecosystem/core-webhooks": -1,
        "@arkecosystem/core-wallet-api": 4040,
        "@arkecosystem/core-api": 4003
      },
      "version": "2.5.0-next.9",
      "height": 2919091,
      "latency": 237
    }
  })";

  EXPECT_CALL(connection.api.peers, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto peer = connection.api.peers.get("167.114.29.49");

  auto responseMatches = strcmp(expected_response.c_str(),
                                peer.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_peers) {
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 219,
      "totalCount": 219,
      "next": "/api/peers?limit=1&page=2",
      "previous": null,
      "self": "/api/peers?limit=1&page=1",
      "first": "/api/peers?limit=1&page=1",
      "last": "/api/peers?limit=1&page=219"
    },
    "data": [
      {
        "ip": "213.32.9.98",
        "port": 4002,
        "ports": {},
        "version": "2.5.0-next.9",
        "height": 2919099,
        "latency": 9
      }
    ]
  })";

  EXPECT_CALL(connection.api.peers, all(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto peers = connection.api.peers.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                peers.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
