
#include "gtest/gtest.h"

#include <arkClient.h>

#include "mocks/mock_http.hpp"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
}  // namespace

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_all) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/transactions?page=1&limit=5";
  const auto response = connection.api.transactions.all();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_all_unconfirmed) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/transactions/unconfirmed?page=1&limit=5";
  const auto response = connection.api.transactions.allUnconfirmed();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_get) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/transactions/"
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  constexpr auto identifier =
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  const auto response = connection.api.transactions.get(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_get_unconfirmed) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected =
      "https://dwallets.ark.io/api/transactions/unconfirmed/"
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  constexpr auto identifier =
      "50c36505f56bd17f4d3c84e03cdc6d4a6cf4d767858db441af5355adf0dae4d3";
  const auto response = connection.api.transactions.getUnconfirmed(identifier);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_fees) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/transactions/fees";
  const auto response = connection.api.transactions.fees();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_types) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = "https://dwallets.ark.io/api/transactions/types";
  const auto response = connection.api.transactions.types();

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}

////////////////////////////////////////////////////////////////////////////////
TEST(api_resources, transactions_send) {
  Connection<Api> connection(DEFAULT_PEER_ADN, getNewMockHttp());

  constexpr auto expected = R"(url: https://dwallets.ark.io/api/transactions
body: {
    "transactions":[
      {
        "type":0,
        "amount":"1",
        "fee":"10000000",
        "id":"bc5bb5cd23521c041fca17b5f78d6f3621fc07ab8f6581aff1b6eb86fa4bafe2",
        "recipientId":"DNSrsDUq5injGBdNXPV7v7u1Qy9LZfWEdM",
        "senderPublicKey":"0216fa03d378b6ad01325e186ad2cbb9d18976d5b27d0ca74b4f92bb6bf9a6d4d9",
        "signature":"3044022014204515b82cdd47513377d3e80e6b5f4fd1ab0fb6b4c181e09a7a30428d542502205ba076a332997053e1d31b506777a99f93bcb11294cd678ebe2da313eb02cae2",
        "timestamp":58351951,
        "vendorField":"7ad0eeb302ee7d9b4e58cf52daa9ece7922ad92d14f0407e3881597bf3c9c1c6"
      }
    ]
  })";

  constexpr auto jsonTransaction = R"({
    "transactions":[
      {
        "type":0,
        "amount":"1",
        "fee":"10000000",
        "id":"bc5bb5cd23521c041fca17b5f78d6f3621fc07ab8f6581aff1b6eb86fa4bafe2",
        "recipientId":"DNSrsDUq5injGBdNXPV7v7u1Qy9LZfWEdM",
        "senderPublicKey":"0216fa03d378b6ad01325e186ad2cbb9d18976d5b27d0ca74b4f92bb6bf9a6d4d9",
        "signature":"3044022014204515b82cdd47513377d3e80e6b5f4fd1ab0fb6b4c181e09a7a30428d542502205ba076a332997053e1d31b506777a99f93bcb11294cd678ebe2da313eb02cae2",
        "timestamp":58351951,
        "vendorField":"7ad0eeb302ee7d9b4e58cf52daa9ece7922ad92d14f0407e3881597bf3c9c1c6"
      }
    ]
  })";

  const auto response = connection.api.transactions.send(jsonTransaction);

  ASSERT_TRUE(strcmp(expected, response.c_str()) == 0);
}
