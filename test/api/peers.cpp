
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, peers_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/peers?page=1&limit=5";
  const auto response = connection.api.peers.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, peers_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/peers/167.114.29.55";
  constexpr auto peerIp = "167.114.29.55";
  const auto response = connection.api.peers.get(peerIp);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
