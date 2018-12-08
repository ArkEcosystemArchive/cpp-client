
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

namespace
{
    const auto arkAddress = "AeLpRK8rFVtBeyBVqBtdQpWDfLzaiNujKr"; // genesis_1
}

TEST(api, test_one_accounts_account)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto accountResponse = connection.api.accounts.get(arkAddress);

    DynamicJsonBuffer jsonBuffer(accountResponse.size());
    JsonObject& root = jsonBuffer.parseObject(accountResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonObject& account = root["account"];

    const char* address = account["address"];
    ASSERT_STREQ("AeLpRK8rFVtBeyBVqBtdQpWDfLzaiNujKr", address);
    
    uint64_t unconfirmedBalance = account["unconfirmedBalance"];
    ASSERT_TRUE(unconfirmedBalance >= 0);

    uint64_t balance = account["balance"];
    ASSERT_TRUE(balance >= 0);

    const char* publicKey = account["publicKey"];
    ASSERT_STREQ("03c075494ad044ab8c0b2dc7ccd19f649db844a4e558e539d3ac2610c4b90a5139", publicKey);
    
    int unconfirmedSignature = account["unconfirmedSignature"];
    ASSERT_EQ(0, unconfirmedSignature);

    int secondSignature = account["secondSignature"];
    ASSERT_EQ(0, secondSignature); 

}

TEST(api, test_one_accounts_balance)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto accountBalanceResponse = connection.api.accounts.balance(arkAddress);

    DynamicJsonBuffer jsonBuffer(accountBalanceResponse.size());
    JsonObject& root = jsonBuffer.parseObject(accountBalanceResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t balance = root["balance"];
    ASSERT_TRUE(balance >= 0);

    const char* unconfirmedBalance = root["unconfirmedBalance"];
    ASSERT_STRNE("", unconfirmedBalance);
}

TEST(api, test_one_accounts_delegates)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegateResponse = connection.api.accounts.delegates(arkAddress);

    DynamicJsonBuffer jsonBuffer(delegateResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegateResponse);

    JsonObject& delegatesZero = root["delegates"][0];

    const char* username = delegatesZero["username"];
    ASSERT_EQ(nullptr, username);
    
    const char* address = delegatesZero["address"];
    ASSERT_EQ(nullptr, address);
    
    const char* publicKey = delegatesZero["publicKey"];
    ASSERT_EQ(nullptr, publicKey);

    const char* vote = delegatesZero["vote"];
    ASSERT_EQ(nullptr, vote);

    int producedblocks = delegatesZero["producedblocks"];
    ASSERT_EQ(0, producedblocks);

    int missedblocks = delegatesZero["missedblocks"];
    ASSERT_EQ(0, missedblocks);

    int rate = delegatesZero["rate"];
    ASSERT_EQ(0, rate);

    double approval = delegatesZero["approval"];
    ASSERT_EQ(0.0, approval);

    double productivity = delegatesZero["productivity"];
    ASSERT_EQ(0.0, productivity);
}

TEST(api, test_one_accounts_delegates_fee)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto delegatesFeeResponse = connection.api.accounts.delegatesFee(arkAddress);

    DynamicJsonBuffer jsonBuffer(delegatesFeeResponse.size());
    JsonObject& root = jsonBuffer.parseObject(delegatesFeeResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    uint64_t delegatesFee = root["fee"];
    ASSERT_TRUE(delegatesFee == 2500000000);
}

TEST(api, test_one_accounts_public_key)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto pubkeyResponse = connection.api.accounts.publickey(arkAddress);

    DynamicJsonBuffer jsonBuffer(pubkeyResponse.size());
    JsonObject& root = jsonBuffer.parseObject(pubkeyResponse);

    const char* publicKey = root["publicKey"];
    ASSERT_STREQ("03c075494ad044ab8c0b2dc7ccd19f649db844a4e558e539d3ac2610c4b90a5139", publicKey);
}
