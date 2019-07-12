
#include "arkClient.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "mocks/mock_api.h"

TEST(api, test_connection) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const auto ip = connection.host.ip().c_str();
  ASSERT_STREQ("167.114.29.55", ip);

  int port = connection.host.port();
  ASSERT_EQ(4003, port);
}
