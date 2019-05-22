#include "host/host.h"
#include "gtest/gtest.h"

TEST(api, test_host) {  // NOLINT
  Ark::Client::Host host("167.114.29.55", 4003);

  const auto ip = host.ip();
  const auto expectedIp = "167.114.29.55";
  ASSERT_STREQ(expectedIp, ip);

  int port = host.port();
  ASSERT_EQ(4003, port);

  const auto hostString = host.toString().c_str();
  const auto expectedHost = "167.114.29.55:4003";
  ASSERT_STREQ(expectedHost, hostString);
}
