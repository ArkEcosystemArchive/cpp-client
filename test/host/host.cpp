
#include "gtest/gtest.h"

#include "host/host.h"

namespace {
using namespace Ark::Client;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
constexpr const char*  tHost = "167.114.29.55:4003";
constexpr const int tUPort = -1;
}  // namespace

/**/

TEST(host, constructor_default) {
  Host host;
  ASSERT_TRUE(host.ip().empty());
  ASSERT_EQ(host.port(), tUPort);
}

/**/

TEST(host, constructor_ip_port) {
  Host host(tIp, tPort);
  ASSERT_STREQ(host.ip().c_str(), tIp);
  ASSERT_EQ(host.port(), tPort);
}

/**/

TEST(host, get_ip) {
  Host host(tIp, tPort);
  ASSERT_STREQ(host.ip().c_str(), tIp);
}

/**/

TEST(host, get_port) {
  Host host(tIp, tPort);
  ASSERT_EQ(host.port(), tPort);
}

/**/

TEST(host, set_host) {
  Host host;
  ASSERT_TRUE(host.set(tIp, tPort));
  ASSERT_STREQ(host.ip().c_str(), tIp);
  ASSERT_EQ(host.port(), tPort);
}

/**/

TEST(host, to_string) {
  Host host(tIp, tPort);
  ASSERT_STREQ(host.toString().c_str(), tHost);
}
