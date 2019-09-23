
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::_;
using testing::Return;

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
}  // namespace

/**/

TEST(api, test_round_delegates) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": [
      {
        "publicKey": "03ffc17c5528d490b045a9b710c754e00a536d05d9b0b78a9baa0533a246dcd98c",
        "votes": "156947252547993"
      }
    ]
  })";

  EXPECT_CALL(connection.api.rounds, delegates(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto delegates = connection.api.rounds.delegates("12345");

  auto responseMatches = strcmp(expected_response.c_str(),
                                delegates.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
