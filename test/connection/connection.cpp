
#include "gtest/gtest.h"
#include "arkClient.h"

TEST(api, test_connection) { // NOLINT
    Ark::Client::Connection<Ark::Client::API::One> oneConnection("5.196.105.32", 4003);
    int oneVersion = oneConnection.api.version();
    ASSERT_EQ(1, oneVersion);

    const char* oneHost = oneConnection.host();
    ASSERT_STREQ("5.196.105.32", oneHost);

    int onePort = oneConnection.port();
    ASSERT_EQ(4003, onePort);


    Ark::Client::Connection<Ark::Client::API::Two> twoConnection("167.114.29.55", 4003);
    int twoVersion = twoConnection.api.version();
    ASSERT_EQ(2, twoVersion);

    const char* twoHost = twoConnection.host();
    ASSERT_STREQ("167.114.29.55", twoHost);

    int twoPort = twoConnection.port();
    ASSERT_EQ(4003, twoPort);
}
