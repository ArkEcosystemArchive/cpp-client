#include "gtest/gtest.h"
#include "host/host.h"

TEST(api, test_host)
{
    Ark::Client::Host host("167.114.29.55", 4003);

    const char* ip = host.ip();
    ASSERT_STREQ("167.114.29.55", ip);

    int port = host.port();
    ASSERT_EQ(4003, port);

    const auto host_string = host.toString().c_str();
    ASSERT_STREQ("167.114.29.55:4003", host_string);
}