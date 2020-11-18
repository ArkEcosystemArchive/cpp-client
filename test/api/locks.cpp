
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

TEST(api, test_lock) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "lockId": "272f327cacad7ed4df34c879dbc731d99f6dda64e3ce5bd8dd7d07f87eb9bd94",
      "amount": "1",
      "secretHash": "09b9a28393efd02fcd76a21b0f0f55ba2aad8f3640ff8cae86de033a9cfbd78c",
      "senderPublicKey": "03dcb84917cf6d7b742f58c04693c5e00c56a4ae83feec129b3e3cc27111796232",
      "recipientId": "D6JpPhN7BehrhNy7AbSQ2u9mkSZb1k7Ens",
      "timestamp": {
        "epoch": 81911280,
        "unix": 1572012480,
        "human": "2019-10-25T14:08:00.000Z"
      },
      "expirationType": 2,
      "expirationValue": 6000000,
      "vendorField": "0.23803497996119338"
    }
  })";

  EXPECT_CALL(connection.api.locks, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto lock = connection.api.locks.get(
    "272f327cacad7ed4df34c879dbc731d99f6dda64e3ce5bd8dd7d07f87eb9bd94");

  auto responseMatches = strcmp(expected_response.c_str(),
                                lock.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_locks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({{
    "meta": {
      "count": 1,
      "pageCount": 7,
      "totalCount": 7,
      "next": "/api/locks?limit=1&page=2",
      "previous": null,
      "self": "/api/locks?limit=1&page=1",
      "first": "/api/locks?limit=1&page=1",
      "last": "/api/locks?limit=1&page=7"
    },
    "data": [
      {
        "lockId": "272f327cacad7ed4df34c879dbc731d99f6dda64e3ce5bd8dd7d07f87eb9bd94",
        "amount": "1",
        "secretHash": "09b9a28393efd02fcd76a21b0f0f55ba2aad8f3640ff8cae86de033a9cfbd78c",
        "senderPublicKey": "03dcb84917cf6d7b742f58c04693c5e00c56a4ae83feec129b3e3cc27111796232",
        "recipientId": "D6JpPhN7BehrhNy7AbSQ2u9mkSZb1k7Ens",
        "timestamp": {
          "epoch": 81911280,
          "unix": 1572012480,
          "human": "2019-10-25T14:08:00.000Z"
        },
        "expirationType": 2,
        "expirationValue": 6000000,
        "vendorField": "0.23803497996119338"
      }
    ]
  })";

  EXPECT_CALL(connection.api.locks, all("?limit=1&page=1"))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto locks = connection.api.locks.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                locks.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_locks_unlocked) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 0,
      "pageCount": 1,
      "totalCount": 0,
      "next": null,
      "previous": null,
      "self": "/api/locks/unlocked?limit=1&page=1",
      "first": "/api/locks/unlocked?limit=1&page=1",
      "last": null
    },
    "data": []
  })";

  std::string jsonIds = R"({
    "ids": ["1916b6da532193a1703e53783b146835a98127445941efadb2d973932e2b8d33"]
  })";

  EXPECT_CALL(connection.api.locks, unlocked(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto locks = connection.api.locks.unlocked(jsonIds, "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                locks.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
