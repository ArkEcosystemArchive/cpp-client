
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, delegates_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/delegates?page=1&limit=5";
  const auto response = connection.api.delegates.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, delegates_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/delegates/genesis_1";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.delegates.get(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, delegates_blocks) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/delegates/genesis_51/blocks?page=1&limit=5";
  constexpr auto identifier = "genesis_51";
  const auto response = connection.api.delegates.blocks(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, delegates_voters) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/delegates/genesis_51/voters?page=1&limit=5";
  constexpr auto identifier = "genesis_51";
  const auto response = connection.api.delegates.voters(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
