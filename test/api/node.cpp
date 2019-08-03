
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::Return;

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
constexpr const char* tIp = "167.114.29.55";
constexpr const int tPort = 4003;
}  // namespace

/**/

TEST(api, test_node_configuration) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "nethash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
      "slip44": 1,
      "wif": 170,
      "token": "DARK",
      "symbol": "DѦ",
      "explorer": "https://dexplorer.ark.io",
      "version": 30,
      "ports": {
        "@arkecosystem/core-p2p": null,
        "@arkecosystem/core-api": 4003
      },
      "constants": {
        "height": 2850000,
        "reward": 200000000,
        "activeDelegates": 51,
        "blocktime": 8,
        "block": {
          "version": 0,
          "maxTransactions": 500,
          "maxPayload": 21000000,
          "acceptExpiredTransactionTimestamps": false,
          "idFullSha256": true
        },
        "epoch": "2017-03-21T13:00:00.000Z",
        "fees": {
          "staticFees": {
            "transfer": 10000000,
            "secondSignature": 500000000,
            "delegateRegistration": 2500000000,
            "vote": 100000000,
            "multiSignature": 500000000,
            "ipfs": 0,
            "timelockTransfer": 0,
            "multiPayment": 0,
            "delegateResignation": 2500000000
          }
        },
        "ignoreInvalidSecondSignatureField": false,
        "ignoreExpiredTransactions": false,
        "vendorFieldLength": 255
      },
      "transactionPool": {
        "dynamicFees": {
          "enabled": true,
          "minFeePool": 1000,
          "minFeeBroadcast": 1000,
          "addonBytes": {
            "transfer": 100,
            "secondSignature": 250,
            "delegateRegistration": 400000,
            "vote": 100,
            "multiSignature": 500,
            "ipfs": 250,
            "timelockTransfer": 500,
            "multiPayment": 500,
            "delegateResignation": 100
          }
        }
      }
    }
  })";

  EXPECT_CALL(connection.api.node, configuration())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto configuration = connection.api.node.configuration();

  auto responseMatches = strcmp(expected_response.c_str(),
                                configuration.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_node_status) {
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "synced": true,
      "now": 2919069,
      "blocksCount": -1,
      "timestamp": 72727946
    }
  })";

  EXPECT_CALL(connection.api.node, status())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto status = connection.api.node.status();

  auto responseMatches = strcmp(expected_response.c_str(),
                                status.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_node_syncing) {
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "syncing": false,
      "blocks": -1,
      "height": 2919074,
      "id": "54167104076192c87659c6a9733555328dba615b4bb1093329185e5d1d1f8666"
    }
  })";

  EXPECT_CALL(connection.api.node, syncing())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto syncing = connection.api.node.syncing();

  auto responseMatches = strcmp(expected_response.c_str(),
                                syncing.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
