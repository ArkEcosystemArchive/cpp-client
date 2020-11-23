
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

TEST(api, test_entities_get) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "data": {
      "id": "89d4afb16f4c30554ef0dfdc500e6e6b2df949f56374e3fdc09c2ebe9504e2a2",
      "address": "DArvWfH5nMDT38tWmo5k461vMQpRXHQWX9",
      "publicKey": "022a40ea35d53eedf0341ffa17574fca844d69665ce35f224e9a6b1385575044fd",
      "isResigned": false,
      "type": 2,
      "subType": 0,
      "data": {
        "name": "ArkBreeze",
        "ipfsData": "QmZT9UmghfLRwDFtthcEDLLXKiFqRtCLhXc3PvqqRFTtTp"
      }
    }
  })";

  EXPECT_CALL(connection.api.entities, get(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto entity = connection.api.entities.get("89d4afb16f4c30554ef0dfdc500e6e6b2df949f56374e3fdc09c2ebe9504e2a2");

  auto responseMatches = strcmp(expected_response.c_str(), entity.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}

/**/

TEST(api, test_entities_all) {  // NOLINT
  Ark::Client::Connection<MockApi> connection(tIp, tPort);

  const std::string expected_response = R"({
    "meta": {
      "totalCountIsEstimate": false,
      "count": 1,
      "pageCount": 2,
      "totalCount": 2,
      "next": "/entities?isResigned=true&limit=1&page=2",
      "previous": null,
      "self": "/entities?isResigned=true&limit=1&page=1",
      "first": "/entities?isResigned=true&limit=1&page=1",
      "last": "/entities?isResigned=true&limit=1&page=2"
    },
    "data": [
      {
        "id": "d67a6a295be4f1eb0fa58416b0e039d45fa24e9e7c8f73400cc8b552378981cb",
        "address": "DArvWfH5nMDT38tWmo5k461vMQpRXHQWX9",
        "publicKey": "022a40ea35d53eedf0341ffa17574fca844d69665ce35f224e9a6b1385575044fd",
        "isResigned": true,
        "type": 0,
        "subType": 0,
        "data": {
          "name": "Business123",
          "ipfsData": "QmNYqeceAdNWc4XMMxm7XRng1R2f4KSFDiG65vVbyFUJob"
        }
      }
    ]
  })";

  EXPECT_CALL(connection.api.entities, all(_))
      .Times(1)
      .WillOnce(Return(expected_response));

  const auto entity = connection.api.entities.all("?isResigned&limit=1&page=1");

  auto responseMatches = strcmp(expected_response.c_str(), entity.c_str()) == 0;
  ASSERT_TRUE(responseMatches);
}
