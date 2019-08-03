
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

TEST(api, test_transaction) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "8d41094befe91164c49f429aa7131cb9d3c5ef741495670d6cfee6d224c86974",
      "blockId": "849e579749dba0a9d5d8667b128a746c1c129c29c8718a4df18cb89802706a5a",
      "version": 1,
      "type": 0,
      "amount": "482750000",
      "fee": "450000",
      "sender": "DJpFwW39QnQvQRQJF2MCfAoKvsX4DJ28jq",
      "senderPublicKey": "027716e659220085e41389efc7cf6a05f7f7c659cf3db9126caabce6cda9156582",
      "recipient": "DEFfff5D258XAc7aSjfn9acs4BbXwSXjrr",
      "signature": "3045022100f0e545e9dc9a5f36017cc64f6b5ca9e4b8cead1e11c05b3736ac271208e64d2d02204c28eee85033a67e56c028628aa3e3e90a94268493b54b09915e186cd13ba4c4",
      "signSignature": "304402204484acf8bca39a58af944be54e370dd24eed5b1665012a952d46828a40da0d40022047c0ea4b8c5120316269dd6daf6262de689fbe3df525efcd44c3e9410a395a4c",
      "vendorField": "reserve",
      "confirmations": 3222,
      "timestamp": {
        "epoch": 72702109,
        "unix": 1562803309,
        "human": "2019-07-11T00:01:49.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.transactions, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto transaction = connection.api.transactions.get(
      "8d41094befe91164c49f429aa7131cb9d3c5ef741495670d6cfee6d224c86974");

  auto responseMatches = strcmp(expected_response.c_str(),
                                transaction.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transaction_types) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "Transfer": 0,
      "SecondSignature": 1,
      "DelegateRegistration": 2,
      "Vote": 3,
      "MultiSignature": 4,
      "Ipfs": 5,
      "TimelockTransfer": 6,
      "MultiPayment": 7,
      "DelegateResignation": 8
    }
  })";

  EXPECT_CALL(connection.api.transactions, types())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto types = connection.api.transactions.types();

  auto responseMatches = strcmp(expected_response.c_str(),
                                types.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transaction_unconfirmed) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "5685946299c426f68c6a6f007059e8f5f015538575b5ef05584963b5837b4c5d",
      "version": 1,
      "type": 0,
      "amount": 100000000,
      "fee": 673078,
      "sender": "DTQgqpnRkkJ2jKNB8DTNjAhhcwZx1JZrgx",
      "senderPublicKey": "033e6e27afd6336946b21a3f4fc1a03205a9a561fbd982ce38e6dfd771c983e70c",
      "recipient": "DFSByMjuFNQy1MkRyyBPxEr6fqsu2w5ava",
      "signature": "3045022100e47f4f1b33cc9376138d87529c24e37afd37a36c87f0b53a1700d1d24c6d629e022009bf60d8a99e9048b07bc9bedaef7c41b28154a0dff147ae10891b5f45bb4954",
      "vendorField": "🐭",
      "confirmations": 0,
      "timestamp": {
        "epoch": 70597829,
        "unix": 1560699029,
        "human": "2019-06-16T15:30:29.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.transactions, getUnconfirmed(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto unconfirmed = connection.api.transactions.getUnconfirmed("dummy");

  auto responseMatches = strcmp(expected_response.c_str(),
                                unconfirmed.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 778588,
      "totalCount": 778588,
      "next": "/api/transactions?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/transactions?limit=1&page=1&transform=true",
      "first": "/api/transactions?limit=1&page=1&transform=true",
      "last": "/api/transactions?limit=1&page=778588&transform=true"
    },
    "data": [
      {
        "id": "ba022647988fd878c9962267c994f6f314f8483eb793da498c3732bec8486fcc",
        "blockId": "71f15e65f23554e5a57067cb18333d082641074c2a1a190df44a273eb04693d3",
        "version": 1,
        "type": 0,
        "amount": "1980000",
        "fee": "500000",
        "sender": "DUTnUVuUFrW3SuWQMbR5ibYkcJ16KhfNKM",
        "senderPublicKey": "02747353898e59c4f784542f357d5dd938a2872adb53abb94924091fddfdd83dc3",
        "recipient": "DQdpw8RPwZKri4HsHxgMVyuLi5memjxo97",
        "signature": "304402206c053265fa0d99418bc5ecbdba3d097e7828a790a1ab3ff53d26b977b48fb98a022015ba5c9b6c5b73e583f50603b6cf5b645e4169633368fa4ee63a6917e047a5da",
        "vendorField": "generaliroh - this is just leafy water",
        "confirmations": 82,
        "timestamp": {
          "epoch": 72727769,
          "unix": 1562828969,
          "human": "2019-07-11T07:09:29.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, all(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto transactions = connection.api.transactions.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                transactions.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transactions_unconfirmed) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "count": 1,
      "pageCount": 1,
      "totalCount": 1,
      "next": null,
      "previous": null,
      "self": "/api/transactions/unconfirmed?transform=true&page=1&limit=100",
      "first": "/api/transactions/unconfirmed?transform=true&page=1&limit=100",
      "last": "/api/transactions/unconfirmed?transform=true&page=1&limit=100"
    },
    "data": [
      {
        "id": "5685946299c426f68c6a6f007059e8f5f015538575b5ef05584963b5837b4c5d",
        "version": 1,
        "type": 0,
        "amount": 100000000,
        "fee": 673078,
        "sender": "DTQgqpnRkkJ2jKNB8DTNjAhhcwZx1JZrgx",
        "senderPublicKey": "033e6e27afd6336946b21a3f4fc1a03205a9a561fbd982ce38e6dfd771c983e70c",
        "recipient": "DFSByMjuFNQy1MkRyyBPxEr6fqsu2w5ava",
        "signature": "3045022100e47f4f1b33cc9376138d87529c24e37afd37a36c87f0b53a1700d1d24c6d629e022009bf60d8a99e9048b07bc9bedaef7c41b28154a0dff147ae10891b5f45bb4954",
        "vendorField": "🐭",
        "confirmations": 0,
        "timestamp": {
          "epoch": 70597829,
          "unix": 1560699029,
          "human": "2019-06-16T15:30:29.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, allUnconfirmed(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto unconfirmed = connection.api.transactions.allUnconfirmed("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                unconfirmed.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transactions_search) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 762344,
      "totalCount": 762344,
      "next": "/api/transactions/search?limit=1&page=2&transform=true",
      "previous": null,
      "self": "/api/transactions/search?limit=1&page=1&transform=true",
      "first": "/api/transactions/search?limit=1&page=1&transform=true",
      "last": "/api/transactions/search?limit=1&page=762344&transform=true"
    },
    "data": [
      {
        "id": "ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4",
        "blockId": "37c2f608910d0624ba114ba9855b3762b2095cd9c2866e1a6ead6c887ff5b07c",
        "version": 1,
        "type": 0,
        "amount": "1980000",
        "fee": "500000",
        "sender": "DUTnUVuUFrW3SuWQMbR5ibYkcJ16KhfNKM",
        "senderPublicKey": "02747353898e59c4f784542f357d5dd938a2872adb53abb94924091fddfdd83dc3",
        "recipient": "DFrnspWhQsJVQswy6qkWWgpyGm4Kj1FA8s",
        "signature": "30440220015f53fff9d86e0ca38f18066ec64b078b6391d420f27d452f2e530ca50571320220162e95d725c154bee54767ab5e9e10824ad9e77a97b47901381b820b33635b25",
        "vendorField": "generaliroh - uncle",
        "confirmations": 10,
        "timestamp": {
          "epoch": 72728617,
          "unix": 1562829817,
          "human": "2019-07-11T07:23:37.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.transactions, search(_, _))
      .Times(1)
      .WillOnce(Return(expected_response));

std::map<std::string, std::string> body{{
  "id", "ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4"
}};

  const auto transactions = connection.api.transactions.search(body,"?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                transactions.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_transactions_send) {  // NOLINT
    Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "accept": [
        "dummy"
      ],
      "broadcast": [
        "dummy"
      ],
      "excess": [],
      "invalid": []
    },
    "errors": null
  })";

  std::string jsonTransaction = R"({
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

  EXPECT_CALL(connection.api.transactions, send(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto transaction = connection.api.transactions.send(jsonTransaction);

  auto responseMatches = strcmp(expected_response.c_str(),
                                transaction.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
