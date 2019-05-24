
#include "host/host.h"
#include "gtest/gtest.h"

TEST(api, test_host) {  // NOLINT
  const auto expectedIp = "167.114.29.55";
  const auto expectedPort = 4003;
  const auto expectedHost = "167.114.29.55:4003";

  // create a test host
  Ark::Client::Host host(expectedIp, expectedPort);

  // check the host //
  // check the IP
  const auto ip = host.ip().c_str();
  ASSERT_STREQ(expectedIp, ip);
  // check the Port
  int port = host.port();
  ASSERT_EQ(expectedPort, port);
  // check the host string
  const auto hostString = host.toString().c_str();
  ASSERT_STREQ(expectedHost, hostString);

  // test setting the host //
  Ark::Client::Host setHost;
  setHost.set(expectedIp, expectedPort);
  ASSERT_STREQ(setHost.toString().c_str(), host.toString().c_str());

  // test the copy constructor //
  Ark::Client::Host copiedHost(host);
  ASSERT_STREQ(copiedHost.toString().c_str(), host.toString().c_str());

  // test the assignment constructor //
  Ark::Client::Host assignedHost(host);
  ASSERT_STREQ(assignedHost.toString().c_str(), host.toString().c_str());
}
