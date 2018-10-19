
#include "gtest/gtest.h"
#include "arkClient.h"
#include "utils/json.h"

namespace
{
    const auto transactionID = "d53926b7baea056163c5cca839be20f43eafb9236445c812e484cddc788ebb35";
}

TEST(api, test_one_transactions_transaction)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto transactionResponse = connection.api.transactions.get(transactionID);

    DynamicJsonBuffer jsonBuffer(transactionResponse.size());
    JsonObject& root = jsonBuffer.parseObject(transactionResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);


    JsonObject& transaction = root["transaction"];

    const char* id = transaction["id"];
    ASSERT_STREQ("d53926b7baea056163c5cca839be20f43eafb9236445c812e484cddc788ebb35", id);
    
    const char* blockid = transaction["blockid"];
    ASSERT_STREQ("4115750139916005265", blockid);
    
    int height = transaction["height"];
    ASSERT_STREQ("2695914", toString(height).c_str());
    
    int type = transaction["type"];
    ASSERT_EQ(0, type);
    
    int timestamp = transaction["timestamp"];
    ASSERT_EQ(21820365, timestamp);
    
    uint64_t amount = transaction["amount"];
    ASSERT_TRUE(amount == 97470000000);
    
    uint64_t fee = transaction["fee"];
    ASSERT_TRUE(fee == 10000000);
    
    const char* vendorField = transaction["vendorField"];
    ASSERT_STREQ(NULL, vendorField);
    
    const char* senderId = transaction["senderId"];
    ASSERT_STREQ("AKzB7dWkCsYnt4u9P4Sch6iKyZ7QnDjBav", senderId);
    
    const char* recipientId = transaction["recipientId"];
    ASSERT_STREQ("AVsRZ7DN9uw4MEC9JjYpGupoXstuCrm8ni", recipientId);
    
    const char* senderPublicKey = transaction["senderPublicKey"];
    ASSERT_STREQ("03e6397071866c994c519f114a9e7957d8e6f06abc2ca34dc9a96b82f7166c2bf9", senderPublicKey);

    const char* signature = transaction["signature"];
    ASSERT_STREQ("3044022071b272d2dc8011e269e691b70aba4bc5b299bdc275fdf96cff98ee0132fdfee702201ff4db13d3aeb3969e207754c14796a36611f112e4cb7cfab8a6280c5c9d7f2b", signature);

    int confirmations = transaction["confirmations"];
    ASSERT_TRUE(confirmations >= 0);
}

TEST(api, test_one_transactions_transactions)
{
    Ark::Client::Connection<Ark::Client::API::One> connection("5.39.9.250", 4001);

    const auto transactionsResponse = connection.api.transactions.all();

    DynamicJsonBuffer jsonBuffer(transactionsResponse.size());
    JsonObject& root = jsonBuffer.parseObject(transactionsResponse);

    bool success = root["success"];
    ASSERT_TRUE(success);

    JsonArray& transactions = root["transactions"];

    for (int i = 0; i < 5; i++)
    {
        const char* id = transactions[i]["id"];
        ASSERT_STRNE("", id);

        const char* blockid = transactions[i]["blockid"];
        ASSERT_STRNE("", blockid);

        int type = transactions[i]["type"];
        ASSERT_TRUE(type >= 0);

        int timestamp = transactions[i]["timestamp"];
        ASSERT_TRUE(timestamp >= 0);

        uint64_t amount = transactions[i]["amount"];
        ASSERT_TRUE(amount >= 0);

        uint64_t fee = transactions[i]["fee"];
        ASSERT_TRUE(fee >= 0);

        const char* vendorField = transactions[i]["vendorField"];
        // ASSERT_STRNE("", vendorField);

        const char* senderId = transactions[i]["senderId"];
        ASSERT_STRNE("", senderId);

        const char* recipientId = transactions[i]["recipientId"];
        ASSERT_STRNE("", recipientId);

        const char* senderPublicKey = transactions[i]["senderPublicKey"];
        ASSERT_STRNE("", senderPublicKey);

        const char* signature = transactions[i]["signature"];
        ASSERT_STRNE("", signature);

        int confirmations = transactions[i]["confirmations"];
        ASSERT_TRUE(confirmations >= 0);
    };
}
