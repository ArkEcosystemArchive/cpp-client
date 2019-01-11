
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mocks/mock_api.h"
#include "arkClient.h"

TEST(api, test_connection) { // NOLINT
    Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);
    int version = connection.api.version();
    ASSERT_EQ(2, version);

    const char* ip = connection.host.ip();
    ASSERT_STREQ("167.114.29.55", ip);

    int port = connection.host.port();
    ASSERT_EQ(4003, port);
}
