
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

TEST(api, test_block) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "52bf612923a1cc314de553f64f40597f89284e6d06d6b652a0eb00f6890f5d69",
      "version": 0,
      "height": 2918583,
      "previous": "56aea32861cdc55b9826601341c41a2d5c44447bc55654a55c51fa41ee4906f7",
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
        "username": "lemii",
        "address": "DAWNRvnMNPWodLjQwhphJwUpTW2KJXBzVR",
        "publicKey": "03dcb84917cf6d7b742f58c04693c5e00c56a4ae83feec129b3e3cc27111796232"
      },
      "signature": "3045022100e5e97a5b00375892ba5359a65943aebb9a2be29df5b6e030c275d61474447e7f02206ce93dbfbdb46535eb7ac53b78689b18f62665928b1f26b9422a5eb15e2f4cbc",
      "confirmations": 8,
      "transactions": 0,
      "timestamp": {
        "epoch": 72724048,
        "unix": 1562825248,
        "human": "2019-07-11T06:07:28.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.blocks, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto block = connection.api.blocks.get("2918583");

  auto responseMatches = strcmp(expected_response.c_str(),
                                block.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_block_first) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "13114381566690093367",
      "version": 0,
      "height": 1,
      "previous": "0",
      "forged": {
        "reward": "0",
        "fee": "0",
        "total": "0",
        "amount": "12500000000000000"
      },
      "payload": {
        "hash": "2a44f340d76ffc3df204c5f38cd355b7496c9065a1ade2ef92071436bd72e867",
        "length": 11395
      },
      "generator": {
        "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
        "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff"
      },
      "signature": "3044022035694a9b99a9236655c658eb07fc3b02ce5edcc24b76424a7287c54ed3822b0602203621e92defb360490610f763d85e94c2db2807a4bd7756cc8a6a585463ef7bae",
      "confirmations": 4346566,
      "transactions": 52,
      "timestamp": {
        "epoch": 0,
        "unix": 1490101200,
        "human": "2017-03-21T13:00:00.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.blocks, first())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto block = connection.api.blocks.first();

  auto responseMatches = strcmp(expected_response.c_str(),
                                block.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_block_last) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "5768900e27621b95dc201fc4e6ce16e72a39e0c625a1c659a23e83eac69605e0",
      "version": 0,
      "height": 4346647,
      "previous": "4deae70324c919d3a79f0f065cfa085a475a7245bcd04d4e558d3205658fc706",
      "forged": {
        "reward": "200000000",
        "fee": "10000000",
        "total": "210000000",
        "amount": "900000000"
      },
      "payload": {
        "hash": "b48f23356cc70d13b0a0c0ba6811be0144a9fc673cc9f723f036187c3bb67f2d",
        "length": 32
      },
      "generator": {
        "username": "genesis_40",
        "address": "D8xN3Nsa3KfC3H68Ek9xnkfdSwzv8Kkh3q",
        "publicKey": "026a423b3323de175dd82788c7eab57850c6a37ea6a470308ebadd7007baf8ceb3"
      },
      "signature": "304402203b6251780c8baead56882aa5aee188f85f8941a1bca272ef6ff3bf9d26cfeed602207634d5268a130937603b774a7282e44065370785dc4b809cf0e98f0e56252bcc",
      "confirmations": 0,
      "transactions": 1,
      "timestamp": {
        "epoch": 92536208,
        "unix": 1582637408,
        "human": "2020-02-25T13:30:08.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.blocks, last())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto block = connection.api.blocks.last();

  auto responseMatches = strcmp(expected_response.c_str(),
                                block.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_block_transactions) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "099d852e9c346370838c68915226a553ff89babbf3065645d98fcab47b9db8c0",
      "version": 0,
      "height": 2890293,
      "previous": "2d21a61a5adad84fc64268b92f98d8b48238fbe05fc4585433fce42385eee743",
      "forged": {
        "reward": "200000000",
        "fee": "1275666",
        "total": "201275666",
        "amount": "500000000"
      },
      "payload": {
        "hash": "abbd2293d21682fb6678a500e436cd6381f697f7b8769fe3c42d13df0dd2cbe5",
        "length": 32
      },
      "generator": {
        "username": "darkdrakeler",
        "address": "DDZaj5qRyrsVT9fqhuRq1D2Z5JvbAGdrdN",
        "publicKey": "0286b465fa963d758118cff91b4afe7c89cb777621bf5eae8876166ae65ed658a0"
      },
      "signature": "304402200324a6b25b6ed83d11930647a9b0ef207d589a9bdf88f0bf416f6792b5d5204702204eebb4c586bdd65f56aa8584e6142c28e0ad7a5b560fb8bcc253587a8b07a790",
      "confirmations": 28450,
      "transactions": 1,
      "timestamp": {
        "epoch": 72496608,
        "unix": 1562597808,
        "human": "2019-07-08T14:56:48.000Z"
      }
    }
  })";

  EXPECT_CALL(connection.api.blocks, transactions(_)).Times(1).WillOnce(Return(expected_response));

  const auto transactions = connection.api.blocks.transactions(
      "099d852e9c346370838c68915226a553ff89babbf3065645d98fcab47b9db8c0");

  auto responseMatches = strcmp(expected_response.c_str(),
                                transactions.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_blocks) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
        "totalCountIsEstimate": false,
        "count": 1,
        "pageCount": 2918749,
        "totalCount": 2918749,
        "next": "/api/blocks?limit=1&page=2&transform=true",
        "previous": null,
        "self": "/api/blocks?limit=1&page=1&transform=true",
        "first": "/api/blocks?limit=1&page=1&transform=true",
        "last": "/api/blocks?limit=1&page=2918749&transform=true"
    },
    "data": [
      {
        "id": "804da254073cad1c2386acbd3c3365c7532cd44ed43f9a4ad6b47541e4a62a2e",
        "version": 0,
        "height": 2918749,
        "previous": "38b9b9fbf9cf8891e1b4f94c73c122199c8871c447bb59ab7c07fe0cedc75ea6",
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
          "username": "zillion",
          "address": "DFWTC6qyGgWPFp3NvWtmtvZV1mKF9ASVMk",
          "publicKey": "0366da7ed85cc1e73a13fafb8007d2609d92239355847343cc7b12d85a65d25502"
        },
        "signature": "3045022100c7965c32f881fd6f4f691e9e479c8768a7ba13679cf449ae78174906431154ce02202ad413d16ce61ca19ef795dad431670ac2392b8980bfe5fc6e802a34e741c940",
        "confirmations": 0,
        "transactions": 0,
        "timestamp": {
          "epoch": 72725376,
          "unix": 1562826576,
          "human": "2019-07-11T06:29:36.000Z"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.blocks, all("?limit=1&page=1"))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto blocks = connection.api.blocks.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                blocks.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
