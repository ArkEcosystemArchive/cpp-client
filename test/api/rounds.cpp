
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, rounds_delegates) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/rounds/12345/delegates";
  constexpr auto roundId = "12345";
  const auto response = connection.api.rounds.delegates(roundId);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
