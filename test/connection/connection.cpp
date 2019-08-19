
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"
#include "host/host.h"
#include "http/http.h"
#include "api/base.h"

namespace {
using namespace Ark::Client;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
constexpr const char* tHost = "167.114.29.55:4003";
constexpr const int tUPort = -1;
}  // namespace

/**/

namespace {
class IMockTestApi : public Ark::Client::api::Base {
 public:
  virtual ~IMockTestApi() = default;
  virtual std::string get() = 0;
 protected:
  IMockTestApi(Ark::Client::Host& host, Ark::Client::IHTTP& http)
      : Ark::Client::api::Base(host, http) {}
};
/**/
class MockTestApi : public IMockTestApi {
 public:
  MockTestApi(Ark::Client::Host& host, Ark::Client::IHTTP& http)
      : IMockTestApi(host, http) {}
  std::string get() override { return "test"; };
};
/**/
class tApi : public Ark::Client::api::Abstract {
 public:
  tApi(): Abstract(new MockHTTP()), test_(host_, *http_) {}

  MockTestApi test() { return this->test_; };
 private:
  MockTestApi test_;
};
/**/
constexpr const char* tMockApi2Response = "test";
}  // namespace

/**/

TEST(connection, constructor_default) {
  Connection<MockApi> connection;
  ASSERT_TRUE(connection.host.ip().empty());
  ASSERT_EQ(connection.host.port(), tUPort);
}

/**/

TEST(connection, constructor_api) {
  Connection<MockApi> connection1;
  auto connection2 = (Connection<tApi>());

  ASSERT_STREQ(connection2.api.test().get().c_str(), tMockApi2Response);
}

/**/

TEST(connection, constructor_ip_port) {
  Connection<MockApi> connection(tIp, tPort);
  const auto hostIp = connection.host.ip();
  ASSERT_STREQ(hostIp.c_str(), tIp);
  ASSERT_EQ(connection.host.port(), tPort);
  ASSERT_STREQ(connection.host.toString().c_str(), tHost);
}
