
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "arkClient.h"

TEST(api, test_connection) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::One> oneConnection("5.196.105.32", 4003);
    int oneVersion = oneConnection.api.version();
    ASSERT_EQ(1, oneVersion);

    const char* ip = connection.host.ip();
    ASSERT_STREQ("167.114.29.55", ip);

    int port = connection.host.port();
    ASSERT_EQ(4003, port);
}
