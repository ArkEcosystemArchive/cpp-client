
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::_;
using testing::Return;

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
}  // namespace

/**/

TEST(api, test_wallet) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "address": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
      "publicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34",
      "username": "genesis_1",
      "balance": "10035728150000",
      "isDelegate": true,
      "vote": "035c14e8c5f0ee049268c3e75f02f05b4246e746dc42f99271ff164b7be20cf5b8"
    }
  })";

  EXPECT_CALL(connection.api.wallets, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto wallet = connection.api.wallets.get(
      "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK");

  auto responseMatches = strcmp(expected_response.c_str(),
                                wallet.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);
  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 196457,
      "totalCount": 196457,
      "next": "/api/wallets?limit=1&page=2",
      "previous": null,
      "self": "/api/wallets?limit=1&page=1",
      "first": "/api/wallets?limit=1&page=1",
      "last": "/api/wallets?limit=1&page=196457"
    },
    "data": [
      {
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "balance": "9898440219335676",
        "isDelegate": false
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, all(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto wallets = connection.api.wallets.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                wallets.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_top) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 196457,
      "totalCount": 196457,
      "next": "/api/wallets/top?page=2&limit=1",
      "previous": null,
      "self": "/api/wallets/top?page=1&limit=1",
      "first": "/api/wallets/top?page=1&limit=1",
      "last": "/api/wallets/top?page=196457&limit=1"
    },
    "data": [
      {
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "balance": "9898440219335676",
        "isDelegate": false
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, top(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto wallets = connection.api.wallets.top("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                wallets.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_locks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/api/wallets/03db91f46dcd94311ab51efc9ca352e2628c27ffce63d1a609a14b8473c0db5b5d/locks?page=1&limit=100",
      "first": "/api/wallets/03db91f46dcd94311ab51efc9ca352e2628c27ffce63d1a609a14b8473c0db5b5d/locks?page=1&limit=100",
      "last": "/api/wallets/03db91f46dcd94311ab51efc9ca352e2628c27ffce63d1a609a14b8473c0db5b5d/locks?page=1&limit=100"
    },
    "data": [
      {
        "lockId": "d8c1d95462081fa211a8c56e717a3cdfaa53fd4985fc44473e392ab5458b336c",
        "amount": "1",
        "secretHash": "09b9a28393efd02fcd76a21b0f0f55ba2aad8f3640ff8cae86de033a9cfbd78c",
        "senderPublicKey": "03db91f46dcd94311ab51efc9ca352e2628c27ffce63d1a609a14b8473c0db5b5d",
        "recipientId": "D6eAmMh6FFynorCSjHS1Qx75rXiN89soa7",
        "timestamp": {
          "epoch": 81911280,
          "unix": 1572012480,
          "human": "2019-10-25T14:08:00.000Z"
        },
        "expirationType": 2,
        "expirationValue": 6000000,
        "vendorField": "0.7712082776486138"
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, locks(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto locks = connection.api.wallets.locks(
      "D9SAVjqkxwWQmb82iqAedJPccFjDUnMSi9", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                locks.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 7,
      "totalCount": 7,
      "next": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions?limit=1&page=1&transform=true",
      "first": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions?limit=1&page=1&transform=true",
      "last": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions?limit=1&page=7&transform=true"
    },
    "data": [
      {
        "id": "a8c0b8b9acabcb742e1760ce16aef5e92f0863bd035fd9bcb341b30d546abdad",
        "blockId": "17044958519703434496",
        "version": 1,
        "type": 0,
        "amount": "100000000",
        "fee": "10000000",
        "sender": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "senderPublicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "recipient": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "signature": "3045022100cde3452fa74e8d9c2ed8187467edd631e55eb9bde5de4a62b7f52ec3d57399a602201827ead48ae19255770d10608fad103dc497f47458737edfae6abebbdd82245e",
        "confirmations": 2920745,
        "timestamp": {
          "epoch": 45021207,
          "unix": 1535122407,
          "human": "2018-08-24T14:53:27.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactions(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto transactions = connection.api.wallets.transactions(
      "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                transactions.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_transactions_received) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 7,
      "totalCount": 7,
      "next": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/received?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/received?limit=1&page=1&transform=true",
      "first": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/received?limit=1&page=1&transform=true",
      "last": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/received?limit=1&page=7&transform=true"
    },
    "data": [
      {
        "id": "6b3d348a4341de3ea281d0af584d04ba78f14154955ac14af044a11bd43388cd",
        "blockId": "35da9ef1a5ffb396a180a1ccb7b40ee32ddfced5b6c24cb7133c926e8e66796a",
        "version": 1,
        "type": 3,
        "amount": "0",
        "fee": "10000000",
        "sender": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "senderPublicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34",
        "recipient": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "signature": "3044022052b1d1f49c2efcbd306906449f6f46824db31110e3afbc0ed6fdca2ca5b3d59c0220039dfc70a8b48d49c5df12a7cbbb0cadc969078786d4824d25e8ff251360e763",
        "asset": {
          "votes": [
            "+035c14e8c5f0ee049268c3e75f02f05b4246e746dc42f99271ff164b7be20cf5b8"
          ]
        },
        "confirmations": 218052,
        "timestamp": {
          "epoch": 70926445,
          "unix": 1561027645,
          "human": "2019-06-20T10:47:25.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactionsReceived(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto received = connection.api.wallets.transactionsReceived(
      "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                received.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_transactions_sent) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 4,
      "totalCount": 4,
      "next": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/sent?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/sent?limit=1&page=1&transform=true",
      "first": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/sent?limit=1&page=1&transform=true",
      "last": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/transactions/sent?limit=1&page=4&transform=true"
    },
    "data": [
      {
        "id": "6b3d348a4341de3ea281d0af584d04ba78f14154955ac14af044a11bd43388cd",
        "blockId": "35da9ef1a5ffb396a180a1ccb7b40ee32ddfced5b6c24cb7133c926e8e66796a",
        "version": 1,
        "type": 3,
        "amount": "0",
        "fee": "10000000",
        "sender": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "senderPublicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34",
        "recipient": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "signature": "3044022052b1d1f49c2efcbd306906449f6f46824db31110e3afbc0ed6fdca2ca5b3d59c0220039dfc70a8b48d49c5df12a7cbbb0cadc969078786d4824d25e8ff251360e763",
        "asset": {
          "votes": [
            "+035c14e8c5f0ee049268c3e75f02f05b4246e746dc42f99271ff164b7be20cf5b8"
          ]
        },
        "confirmations": 218061,
        "timestamp": {
          "epoch": 70926445,
          "unix": 1561027645,
          "human": "2019-06-20T10:47:25.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, transactionsSent(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto sent = connection.api.wallets.transactionsSent(
      "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                sent.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_wallets_votes) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 3,
      "totalCount": 3,
      "next": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/votes?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/votes?limit=1&page=1&transform=true",
      "first": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/votes?limit=1&page=1&transform=true",
      "last": "/api/wallets/DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK/votes?limit=1&page=3&transform=true"
    },
    "data": [
      {
        "id": "6b3d348a4341de3ea281d0af584d04ba78f14154955ac14af044a11bd43388cd",
        "blockId": "35da9ef1a5ffb396a180a1ccb7b40ee32ddfced5b6c24cb7133c926e8e66796a",
        "version": 1,
        "type": 3,
        "amount": "0",
        "fee": "10000000",
        "sender": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "senderPublicKey": "02511f16ffb7b7e9afc12f04f317a11d9644e4be9eb5a5f64673946ad0f6336f34",
        "recipient": "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK",
        "signature": "3044022052b1d1f49c2efcbd306906449f6f46824db31110e3afbc0ed6fdca2ca5b3d59c0220039dfc70a8b48d49c5df12a7cbbb0cadc969078786d4824d25e8ff251360e763",
        "asset": {
          "votes": [
            "+035c14e8c5f0ee049268c3e75f02f05b4246e746dc42f99271ff164b7be20cf5b8"
          ]
        },
        "confirmations": 218065,
        "timestamp": {
          "epoch": 70926445,
          "unix": 1561027645,
          "human": "2019-06-20T10:47:25.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.wallets, votes(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

const auto votes = connection.api.wallets.votes(
    "DL6wmfnA2acPLpBjKS4zPGsSwxkTtGANsK", "?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                votes.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
