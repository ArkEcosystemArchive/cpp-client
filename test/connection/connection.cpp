
#include "gtest/gtest.h"
#include "arkClient.h"

TEST(api, test_connection)
{
    Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.55", 4003);
    int version = connection.api.version();
    ASSERT_EQ(2, version);

    const char* host = connection.host();
    ASSERT_STREQ("167.114.29.55", host);

    int port = connection.port();
    ASSERT_EQ(4003, port);
}
