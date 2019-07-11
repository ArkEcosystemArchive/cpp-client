
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::_;
using testing::Return;

TEST(api, test_delegate) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "data": {
        "username": "munich",
        "address": "DKfEF2sykKCZzom3vFg1dp9D2kisB8hM2Q",
        "publicKey": "036a520acf24036ff691a4f8ba19514828e9b5aa36ca4ba0452e9012023caccfef",
        "votes": "30756514325531",
        "rank": 8,
        "blocks": {
            "produced": 39154,
            "last": {
                "id": "9ece2a535ad471766c4bd5b6d0e8f342301b7f744a1ec200ddbc150da0d8c669",
                "height": 2919031,
                "timestamp": {
                    "epoch": 72727632,
                    "unix": 1562828832,
                    "human": "2019-07-11T07:07:12.000Z"
                }
            }
        },
        "production": {
            "approval": 0.25
        },
        "forged": {
            "fees": "5933484566",
            "rewards": "7830800000000",
            "total": "7836733484566"
        }
    }
  })";

  EXPECT_CALL(connection.api.delegates, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto delegate = connection.api.delegates.get("munich");

  auto responseMatches = strcmp(expected_response.c_str(),
                                delegate.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_delegate_blocks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
        "totalCountIsEstimate": false,
        "count": 1,
        "pageCount": 39154,
        "totalCount": 39154,
        "next": "/api/delegates/munich/blocks?limit=1&page=2&transform=true",
        "previous": null,
        "self": "/api/delegates/munich/blocks?limit=1&page=1&transform=true",
        "first": "/api/delegates/munich/blocks?limit=1&page=1&transform=true",
        "last": "/api/delegates/munich/blocks?limit=1&page=39154&transform=true"
    },
    "data": [
        {
            "id": "9ece2a535ad471766c4bd5b6d0e8f342301b7f744a1ec200ddbc150da0d8c669",
            "version": 0,
            "height": 2919031,
            "previous": "90a3928a6daf34109107545fe0d27775b47a3821e0e1e9cb3f9567ceb9b26237",
            "forged": {
                "reward": "200000000",
                "fee": "0",
                "total": "200000000",
                "amount": "0"
            },
            "payload": {
                "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
                "length": 0
            },
            "generator": {
                "username": "munich",
                "address": "DKfEF2sykKCZzom3vFg1dp9D2kisB8hM2Q",
                "publicKey": "036a520acf24036ff691a4f8ba19514828e9b5aa36ca4ba0452e9012023caccfef"
            },
            "signature": "3045022100f0f2c0856eb8d86dbd86e4b5db47217d9558aa2df6cf6a33a3217a8b30ef631c022045808b473d00732c75a6af98d600cc57839bbdeab8dd22f70ab41afcde39e180",
            "confirmations": 16,
            "transactions": 0,
            "timestamp": {
                "epoch": 72727632,
                "unix": 1562828832,
                "human": "2019-07-11T07:07:12.000Z"
            }
        }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, blocks(_, _, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto blocks = connection.api.delegates.blocks("munich", 1, 1);

  auto responseMatches = strcmp(expected_response.c_str(),
                                blocks.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_delegate_voters) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
        "count": 1,
        "pageCount": 1,
        "totalCount": 1,
        "next": null,
        "previous": null,
        "self": "/api/delegates/munich/voters?limit=1&page=1&transform=true",
        "first": "/api/delegates/munich/voters?limit=1&page=1&transform=true",
        "last": "/api/delegates/munich/voters?limit=1&page=1&transform=true"
    },
    "data": [
        {
            "address": "DKfEF2sykKCZzom3vFg1dp9D2kisB8hM2Q",
            "publicKey": "036a520acf24036ff691a4f8ba19514828e9b5aa36ca4ba0452e9012023caccfef",
            "username": "munich",
            "balance": "30756514325531",
            "isDelegate": true,
            "vote": "036a520acf24036ff691a4f8ba19514828e9b5aa36ca4ba0452e9012023caccfef"
        }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, voters(_, _, _))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto voters = connection.api.delegates.voters("munich", 1, 1);

  auto responseMatches = strcmp(expected_response.c_str(),
                                voters.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_delegates) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
        "count": 1,
        "pageCount": 392,
        "totalCount": 392,
        "next": "/api/delegates?limit=1&page=2",
        "previous": null,
        "self": "/api/delegates?limit=1&page=1",
        "first": "/api/delegates?limit=1&page=1",
        "last": "/api/delegates?limit=1&page=392"
    },
    "data": [
        {
            "username": "alessio",
            "address": "DSyG9hK9CE8eyfddUoEvsga4kNVQLdw2ve",
            "publicKey": "033a5474f68f92f254691e93c06a2f22efaf7d66b543a53efcece021819653a200",
            "votes": "2000712345332209",
            "rank": 1,
            "blocks": {
                "produced": 46928,
                "last": {
                    "id": "97a2b8aa2a5c6542e10289705a028bc74b0088fb0f11773f9b38b2bb3a5751c1",
                    "height": 2919050,
                    "timestamp": {
                        "epoch": 72727784,
                        "unix": 1562828984,
                        "human": "2019-07-11T07:09:44.000Z"
                    }
                }
            },
            "production": {
                "approval": 15.99
            },
            "forged": {
                "fees": "468407250508",
                "rewards": "9346000000000",
                "total": "9814407250508"
            }
        }
    ]
  })";

  EXPECT_CALL(connection.api.delegates, all(1, 1))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto delegates = connection.api.delegates.all(1, 1);

  auto responseMatches = strcmp(expected_response.c_str(),
                                delegates.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
