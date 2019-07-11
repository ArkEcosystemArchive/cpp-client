
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
        "block": {
            "height": 2922163,
            "id": "84125ec94ba3f3a2d6fd6643d50c98ed2f3c8fa62d8c939355974f404e9b3906"
        },
        "supply": "13082272800000000"
    }
  })";

  EXPECT_CALL(connection.api.blockchain, get())
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto blockchain = connection.api.blockchain.get();

  auto responseMatches = strcmp(expected_response.c_str(),
                                blockchain.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
