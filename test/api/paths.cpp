
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "arkClient.h"

namespace {
Ark::Client::Host testHost("0.0.0.0", 4003);
using namespace Ark::Client::API;
}

/**/

TEST(paths, test_blocks) {  // NOLINT
  const auto base = Paths::Blocks::base();
  ASSERT_STREQ("/api/blocks", base);

  const auto get = Paths::Blocks::get(testHost, "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/58328125061111756", get.c_str());

  const auto all = Paths::Blocks::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/blocks?limit=5&page=1", all.c_str());

  const auto transactions = Paths::Blocks::transactions(testHost,
                                                        "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/58328125061111756/transactions",
               transactions.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "id", "8337447655053578871" },
    { "previousBlock", "6440284271011893973" },
    { "version", "0" }
  };
  const auto search = Paths::Blocks::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/search?limit=5&page=1",
               search.first.c_str());
  ASSERT_STREQ(
      "id=8337447655053578871&previousBlock=6440284271011893973&version=0",
      search.second.c_str());
}

/**/

TEST(paths, test_delegates) {  // NOLINT
  const auto base = Paths::Delegates::base();
  ASSERT_STREQ("/api/delegates", base);

  const auto get = Paths::Delegates::get(testHost, "boldninja");
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja", get.c_str());

  const auto all = Paths::Delegates::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/delegates?limit=5&page=1", all.c_str());

  const auto blocks = Paths::Delegates::blocks(testHost, "boldninja", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja/blocks?limit=5&page=1",
               blocks.c_str());

  const auto voters = Paths::Delegates::voters(testHost, "boldninja", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja/voters?limit=5&page=1",
               voters.c_str());
}

/**/

TEST(paths, test_node) {  // NOLINT
  const auto base = Paths::Node::base();
  ASSERT_STREQ("/api/node", base);

  const auto configuration = Paths::Node::configuration(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/configuration", configuration.c_str());

  const auto status = Paths::Node::status(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/status", status.c_str());

  const auto syncing = Paths::Node::syncing(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/syncing", syncing.c_str());
}

/**/

TEST(paths, test_peers) {  // NOLINT
  const auto base = Paths::Peers::base();
  ASSERT_STREQ("/api/peers", base);

  const auto get = Paths::Peers::get(testHost, "0.0.0.0");
  ASSERT_STREQ("0.0.0.0:4003/api/peers/0.0.0.0", get.c_str());

  const auto all = Paths::Peers::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/peers?limit=5&page=1", all.c_str());
}

/**/

TEST(paths, test_transactions) {  // NOLINT
  const auto base = Paths::Transactions::base();
  ASSERT_STREQ("/api/transactions", base);

  const auto getUnconfirmed = Paths::Transactions::getUnconfirmed(
      testHost,
      "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/transactions/unconfirmed/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
      getUnconfirmed.c_str());

  const auto all = Paths::Transactions::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions?limit=5&page=1", all.c_str());

  const auto get = Paths::Transactions::get(
      testHost,
      "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/transactions/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
      get.c_str());

  const auto allUnconfirmed = Paths::Transactions::allUnconfirmed(
      testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/unconfirmed?limit=5&page=1",
               allUnconfirmed.c_str());

  const auto types = Paths::Transactions::types(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/types", types.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "id", "dummy" },
    { "key", "value" }
  };
  const auto search = Paths::Transactions::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/search?limit=5&page=1",
               search.first.c_str());
  ASSERT_STREQ("id=dummy&key=value", search.second.c_str());

  std::string jsonTransaction = "{"
    "\"id\":\"5ab523d18ac948da82700a71fc0b3c9e764fc0cba91927cb1aa63354564ad23f\","
    "\"signature\":\"3045022100a6da60f9b3e20c80f491d168b8c51a85e0ec56a2448f9e10fc4bcc05a2bf79b8022078fa21b7d46e14c62d38f07e408fdb52f7b6a671894c6d0762913ca4a55e7a99\","
    "\"timestamp\":4076176416,"
    "\"type\":0,"
    "\"fee\":10000000,"
    "\"senderPublicKey\":\"02f21aca9b6d224ea86a1689f57910534af21c3cc9f80602fed252c13e275f0699\","
    "\"amount\":1,"
    "\"recipientId\":\"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\","
    "\"vendorField\":\"7ad0eeb302ee7d9b4e58cf52daa9ece7922ad92d14f0407e3881597bf3c9c1c6\""
  "}";
  const auto send = Paths::Transactions::send(testHost, jsonTransaction);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions", send.first.c_str());
  ASSERT_STREQ(jsonTransaction.c_str(), send.second.c_str());
}

/**/

TEST(paths, test_votes) {  // NOLINT
  const auto base = Paths::Votes::base();
  ASSERT_STREQ("/api/votes", base);

  const auto get = Paths::Votes::get(
      testHost,
      "d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/votes/d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2",
      get.c_str());

  const auto all = Paths::Votes::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/votes?limit=5&page=1", all.c_str());
}

/**/

TEST(paths, test_wallets) {  // NOLINT
  const auto base = Paths::Wallets::base();
  ASSERT_STREQ("/api/wallets", base);

  const auto get = Paths::Wallets::get(testHost,
                                       "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
               get.c_str());

  const auto all = Paths::Wallets::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/wallets?limit=5&page=1", all.c_str());

  const auto top = Paths::Wallets::top(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/top?limit=5&page=1", top.c_str());

  const auto transactions = Paths::Wallets::transactions(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=5&page=1",
      transactions.c_str());

  const auto sent = Paths::Wallets::transactionsSent(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/sent?limit=5&page=1",
      sent.c_str());

  const auto received = Paths::Wallets::transactionsReceived(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=5&page=1",
      received.c_str());

  const auto votes = Paths::Wallets::votes(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/votes?limit=5&page=1",
      votes.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "username", "baldninja" },
    { "address", "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T" },
    { "publicKey", "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d" }
  };
  const auto search = Paths::Wallets::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/search?limit=5&page=1",
               search.first.c_str());
  ASSERT_STREQ(
      "address=DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T&publicKey=03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d&username=baldninja",
      search.second.c_str());
}
