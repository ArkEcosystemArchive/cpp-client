
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, blockchain_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/blockchain";
  const auto response = connection.api.blockchain.get();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
