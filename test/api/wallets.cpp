
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets?page=1&limit=5";
  const auto response = connection.api.wallets.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/wallets/genesis_1";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.get(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_locks) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/genesis_1/locks";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.locks(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_top) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/top?page=1&limit=5";
  const auto response = connection.api.wallets.top();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_votes) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/genesis_1/votes?page=1&limit=5";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.votes(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_transactions) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/genesis_1/"
      "transactions?page=1&limit=5";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.transactions(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_transactions_sent) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/genesis_1/transactions/"
      "sent?page=1&limit=5";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.transactionsSent(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, wallets_transactions_received) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/wallets/genesis_1/transactions/"
      "received?page=1&limit=5";
  constexpr auto identifier = "genesis_1";
  const auto response = connection.api.wallets.transactionsReceived(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
