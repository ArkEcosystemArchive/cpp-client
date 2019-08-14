
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <arkClient.h>

#include "mocks/mock_api.h"

using testing::_;
using testing::Return;

TEST(api, test_vote) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "data": {
        "id": "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67",
        "blockId": "9df8800ab375cfda3782b90bb8e14326e029cecfb22742c6a7c3100c7209a30b",
        "version": 1,
        "type": 3,
        "amount": "0",
        "fee": "97013913",
        "sender": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
        "senderPublicKey": "034da006f958beba78ec54443df4a3f52237253f7ae8cbdb17dccf3feaa57f3126",
        "recipient": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
        "signature": "3045022100b92598f344d3d3d6b0224cfd2058fb35318aac127b8bde529e01fe3868018b610220041cb63436f84bbf93b11c040f9389ebaf8293d63cc685255cea13f48a3f48f6",
        "asset": {
            "votes": [
                "+02aea83a44f1d6b073e5bcffb4176bbe3c51dcd0e96a793a88f3a6135600224adf"
            ]
        },
        "confirmations": 223,
        "timestamp": {
            "epoch": 72739207,
            "unix": 1562840407,
            "human": "2019-07-11T10:20:07.000Z"
        }
    }
  })";

  EXPECT_CALL(connection.api.votes, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto vote = connection.api.votes.get(
      "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67");

  auto responseMatches = strcmp(expected_response.c_str(),
                                vote.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_votes) {  // NOLINT
  Ark::Client::Connection<MockApi> connection("167.114.29.55", 4003);

  const std::string expected_response = R"({
    "meta": {
        "totalCountIsEstimate": false,
        "count": 1,
        "pageCount": 15137,
        "totalCount": 15137,
        "next": "/api/votes?limit=1&page=2&transform=true",
        "previous": null,
        "self": "/api/votes?limit=1&page=1&transform=true",
        "first": "/api/votes?limit=1&page=1&transform=true",
        "last": "/api/votes?limit=1&page=15137&transform=true"
    },
    "data": [
        {
            "id": "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67",
            "blockId": "9df8800ab375cfda3782b90bb8e14326e029cecfb22742c6a7c3100c7209a30b",
            "version": 1,
            "type": 3,
            "amount": "0",
            "fee": "97013913",
            "sender": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
            "senderPublicKey": "034da006f958beba78ec54443df4a3f52237253f7ae8cbdb17dccf3feaa57f3126",
            "recipient": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
            "signature": "3045022100b92598f344d3d3d6b0224cfd2058fb35318aac127b8bde529e01fe3868018b610220041cb63436f84bbf93b11c040f9389ebaf8293d63cc685255cea13f48a3f48f6",
            "asset": {
                "votes": [
                    "+02aea83a44f1d6b073e5bcffb4176bbe3c51dcd0e96a793a88f3a6135600224adf"
                ]
            },
            "confirmations": 229,
            "timestamp": {
                "epoch": 72739207,
                "unix": 1562840407,
                "human": "2019-07-11T10:20:07.000Z"
            }
        }
    ]
  })";

  EXPECT_CALL(connection.api.votes, all(_))
        .Times(1)
        .WillOnce(Return(expected_response));

  const auto votes = connection.api.votes.all("?limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(),
                                votes.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
