
#include "gtest/gtest.h"
#include "arkClient.h"

TEST(api, test_connection)
{
    Ark::Client::Connection<Ark::Client::API::One> oneConnection("5.39.9.250", 4001);
    int oneVersion = oneConnection.api.version();
    ASSERT_EQ(1, oneVersion);

    const char* oneHost = oneConnection.http->host();
    ASSERT_STREQ("5.39.9.250", oneHost);

    int onePort = oneConnection.http->port();
    ASSERT_EQ(4001, onePort);


    Ark::Client::Connection<Ark::Client::API::Two> twoConnection("167.114.29.55", 4003);
    int twoVersion = twoConnection.api.version();
    ASSERT_EQ(2, twoVersion);

    const char* twoHost = twoConnection.http->host();
    ASSERT_STREQ("167.114.29.55", twoHost);

    int twoPort = twoConnection.http->port();
    ASSERT_EQ(4003, twoPort);
}
