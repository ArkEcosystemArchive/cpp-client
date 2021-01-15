
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, locks_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/locks?page=1&limit=5";
  const auto response = connection.api.locks.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, locks_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/locks/"
      "bc3ee5fe72cb4c73521aef576d6d53ba3323dd9cb652f33bf613d22e7f7185a8";
  constexpr auto lockId =
      "bc3ee5fe72cb4c73521aef576d6d53ba3323dd9cb652f33bf613d22e7f7185a8";
  const auto response = connection.api.locks.get(lockId);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, locks_unlocked) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/locks/unlocked/"
      "bc3ee5fe72cb4c73521aef576d6d53ba3323dd9cb652f33bf613d22e7f7185a8";
  constexpr auto identifier =
      "bc3ee5fe72cb4c73521aef576d6d53ba3323dd9cb652f33bf613d22e7f7185a8";
  const auto response = connection.api.locks.unlocked(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
