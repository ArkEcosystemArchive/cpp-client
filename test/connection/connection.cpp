
#include "gtest/gtest.h"
#include "arkClient.h"

TEST(api, test_connection)
{
    Ark::Client::Connection<Ark::Client::API::Two> twoConnection("167.114.29.55", 4003);
    int twoVersion = twoConnection.api.version();
    ASSERT_EQ(2, twoVersion);

    const char* twoHost = twoConnection.host();
    ASSERT_STREQ("167.114.29.55", twoHost);

    int twoPort = twoConnection.port();
    ASSERT_EQ(4003, twoPort);
}
