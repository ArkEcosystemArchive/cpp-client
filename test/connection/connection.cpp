
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

////////////////////////////////////////////////////////////////////////////////
constexpr auto DEFAULT_PEER_APN = "https://wallets.ark.io";
constexpr auto ADN_PEER = "167.114.29.55";
constexpr int ADN_API_PORT = 4003;

////////////////////////////////////////////////////////////////////////////////
TEST(api_connection, constructor_default) {
  Connection<Api> connection;

  ASSERT_TRUE(strcmp(connection.getPeer().c_str(), DEFAULT_PEER_ADN) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_connection, constructor_custom_peer) {
  Connection<Api> connection(DEFAULT_PEER_APN);

  ASSERT_TRUE(strcmp(connection.getPeer().c_str(), DEFAULT_PEER_APN) == 0);
}

TEST(api_connection, constructor_ip_port) {
  Connection<Api> connection(ADN_PEER, ADN_API_PORT);

  constexpr auto expected = "167.114.29.55:4003";

  ASSERT_TRUE(strcmp(connection.getPeer().c_str(), expected) == 0);
}
