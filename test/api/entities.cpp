
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, entities_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/entities?page=1&limit=5";
  const auto response = connection.api.entities.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, entities_get) {  // NOLINT
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/entities/"
      "a997eba0f8e7d10a132585748f3f3b619a1cd1d21a089a8abf57c2fbcac88314";
  constexpr auto entityId =
      "a997eba0f8e7d10a132585748f3f3b619a1cd1d21a089a8abf57c2fbcac88314";
  const auto response = connection.api.entities.get(entityId);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
