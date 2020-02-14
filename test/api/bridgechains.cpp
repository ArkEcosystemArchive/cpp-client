
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

TEST(api, test_bridgechain) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "bridgechainId": "8",
      "businessId": 12,
      "name": "Another Bridgechain",
      "seedNodes": [
        "3.3.3.3"
      ],
      "genesisHash": "c6512e5b7697cbedb0e1e5b250a983057c6c98cc48d64c1cfa475ca81f7518a7",
      "bridgechainRepository": "https://github.com/ArkEcosystem/core"
    }
  })";

  EXPECT_CALL(connection.api.bridgechains, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto bridgechain = connection.api.bridgechains.get("8");

  auto responseMatches = strcmp(expected_response.c_str(),
                                bridgechain.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_bridgechains) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 8,
      "totalCount": 8,
      "next": "/api/bridgechains?limit=1&page=2",
      "previous": null,
      "self": "/api/bridgechains?limit=1&page=1",
      "first": "/api/bridgechains?limit=1&page=1",
      "last": "/api/bridgechains?limit=1&page=8"
    },
    "data": [
      {
        "bridgechainId": "8",
        "businessId": 12,
        "name": "Another Bridgechain",
        "seedNodes": [
          "3.3.3.3"
        ],
        "genesisHash": "c6512e5b7697cbedb0e1e5b250a983057c6c98cc48d64c1cfa475ca81f7518a7",
        "bridgechainRepository": "https://github.com/ArkEcosystem/core"
      }
    ]
  })";

  EXPECT_CALL(connection.api.bridgechains, all("?limit=1&page=1"))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto bridgechains = connection.api.bridgechains.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                bridgechains.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_bridgechains_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 8,
      "totalCount": 8,
      "next": "/api/bridgechains/search?limit=1&page=2",
      "previous": null,
      "self": "/api/bridgechains/search?limit=1&page=1",
      "first": "/api/bridgechains/search?limit=1&page=1",
      "last": "/api/bridgechains/search?limit=1&page=29"
    },
    "data": [
      {
        "bridgechainId": "8",
        "businessId": 12,
        "name": "Another Bridgechain",
        "seedNodes": [
          "3.3.3.3"
        ],
        "genesisHash": "c6512e5b7697cbedb0e1e5b250a983057c6c98cc48d64c1cfa475ca81f7518a7",
        "bridgechainRepository": "https://github.com/ArkEcosystem/core"
      }
    ]
  })";

  EXPECT_CALL(connection.api.bridgechains, search(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const std::map<std::string, std::string> body = {};
  const auto bridgechains = connection.api.bridgechains.search(body, "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                bridgechains.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
