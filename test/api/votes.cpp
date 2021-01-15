
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, votes_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/votes?page=1&limit=5";
  const auto response = connection.api.votes.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, votes_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/votes/"
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  constexpr auto voteTxId =
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  const auto response = connection.api.votes.get(voteTxId);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
