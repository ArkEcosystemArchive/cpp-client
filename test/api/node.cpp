
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

TEST(api, test_node_configuration) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "nethash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
      "slip44": 1,
      "wif": 170,
      "token": "DARK",
      "symbol": "DѦ",
      "explorer": "https://dwallets.ark.io",
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

TEST(api, test_node_crypto) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "exceptions": {
        "blocks": [
          "6671890826474701031"
        ],
        "transactions": [
          "df8223e5443ed0decb7f8f3bcf7e822b7bbd3bea31f615d99c26909ac6d066f8"
        ]
      },
      "genesisBlock": {
        "version": 0,
        "totalAmount": "12500000000000000",
        "totalFee": "0",
        "reward": "0",
        "payloadHash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
        "timestamp": 0,
        "numberOfTransactions": 52,
        "payloadLength": 11395,
        "previousBlock": null,
        "generatorPublicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
        "transactions": [
          {
            "type": 0,
            "amount": "12500000000000000",
            "fee": "0",
            "recipientId": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
            "timestamp": 0,
            "asset": {},
            "senderPublicKey": "0208e6835a8f020cfad439c059b89addc1ce21f8cab0af6e6957e22d3720bff8a4",
            "signature": "304402203a3f0f80aad4e0561ae975f241f72a074245f1205d676d290d6e5630ed4c027502207b31fee68e64007c380a4b6baccd4db9b496daef5f7894676586e1347ac30a3b",
            "id": "3e3817fd0c35bc36674f3874c2953fa3e35877cbcdb44a08bdc6083dbd39d572"
          }
        ],
        "height": 1,
        "id": "13114381566690093367",
        "blockSignature": "3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae"
      },
      "milestones": [
        {
          "height": 1,
          "reward": 0,
          "activeDelegates": 51,
          "blocktime": 8,
          "block": {
            "version": 0,
            "maxTransactions": 50,
            "maxPayload": 2097152,
            "acceptExpiredTransactionTimestamps": true
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
          "ignoreInvalidSecondSignatureField": true,
          "ignoreExpiredTransactions": true,
          "vendorFieldLength": 64
        }
      ],
      "network": {
        "name": "devnet",
        "messagePrefix": "DARK message:\n",
        "bip32": {
          "public": 46090600,
          "private": 46089520
        },
        "pubKeyHash": 30,
        "nethash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
        "wif": 170,
        "slip44": 1,
        "aip20": 1,
        "client": {
          "token": "DARK",
          "symbol": "DѦ",
          "explorer": "https://dwallets.ark.io"
        }
      }
    }
  })";

  EXPECT_CALL(connection.api.node, crypto())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto crypto = connection.api.node.crypto();

  auto responseMatches = strcmp(expected_response.c_str(),
                                crypto.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_node_fees) {
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "days": 7
    },
    "data": [
      {
        "type": 0,
        "avg": "2159269",
        "min": "30000",
        "max": "17493405",
        "sum": "70675045972"
      },
      {
        "type": 1,
        "avg": "275000000",
        "min": "50000000",
        "max": "500000000",
        "sum": "550000000"
      },
      {
        "type": 2,
        "avg": "1200000000",
        "min": "1200000000",
        "max": "1200000000",
        "sum": "2400000000"
      },
      {
        "type": 3,
        "avg": "26815214",
        "min": "700000",
        "max": "186790786",
        "sum": "7427814405"
      }
    ]
  })";

  EXPECT_CALL(connection.api.node, fees(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto fees = connection.api.node.fees("?days=7");

  auto responseMatches = strcmp(expected_response.c_str(),
                                fees.c_str()) == 0;
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
