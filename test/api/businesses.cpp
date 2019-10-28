
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

TEST(api, test_business) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "businessId": 12,
      "name": "My First Business",
      "website": "http://business.org"
    }
  })";

  EXPECT_CALL(connection.api.businesses, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto business = connection.api.businesses.get("1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                business.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_business_bridgechains) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 2,
      "totalCount": 2,
      "next": "/api/businesses/12/bridgechains?page=2&limit=1",
      "previous": null,
      "self": "/api/businesses/12/bridgechains?page=1&limit=1",
      "first": "/api/businesses/12/bridgechains?page=1&limit=1",
      "last": "/api/businesses/12/bridgechains?page=1&limit=1"
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

  EXPECT_CALL(connection.api.businesses, bridgechains(_,_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto bridgechains = connection.api.businesses.bridgechains("12", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                bridgechains.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_businesses) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 29,
      "totalCount": 29,
      "next": "/api/businesses?limit=1&page=2",
      "previous": null,
      "self": "/api/businesses?limit=1&page=1",
      "first": "/api/businesses?limit=1&page=1",
      "last": "/api/businesses?limit=1&page=29"
    },
    "data": [
      {
        "businessId": 29,
        "name": "12",
        "website": "http://hi.com"
      }
    ]
  })";

  EXPECT_CALL(connection.api.businesses, all("?limit=1&page=1"))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto businesses = connection.api.businesses.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                businesses.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_businesses_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 29,
      "totalCount": 29,
      "next": "/api/businesses/search?limit=1&page=2",
      "previous": null,
      "self": "/api/businesses/search?limit=1&page=1",
      "first": "/api/businesses/search?limit=1&page=1",
      "last": "/api/businesses/search?limit=1&page=29"
    },
    "data": [
      {
        "businessId": 29,
        "name": "12",
        "website": "http://hi.com"
      }
    ]
  })";

  EXPECT_CALL(connection.api.businesses, search(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const std::map<std::string, std::string> body = {};
  const auto businesses = connection.api.businesses.search(body, "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                businesses.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
