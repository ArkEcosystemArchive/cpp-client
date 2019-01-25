
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "arkClient.h"

namespace {
Ark::Client::Host testHost("0.0.0.0", 4003);
}

TEST(paths, test_blocks) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Blocks::base();
  ASSERT_STREQ("/api/v2/blocks", base);

  const auto get = Ark::Client::API::Paths::Blocks::get(testHost, "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/blocks/58328125061111756", get.c_str());

  const auto all = Ark::Client::API::Paths::Blocks::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/blocks?limit=5&page=1", all.c_str());

  const auto transactions = Ark::Client::API::Paths::Blocks::transactions(testHost, "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/blocks/58328125061111756/transactions", transactions.c_str());

  const std::map<std::string, std::string> searchBody = {
      {"id", "8337447655053578871"}, {"previousBlock", "6440284271011893973"}, {"version", "0"}};
  const auto search = Ark::Client::API::Paths::Blocks::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/blocks/search?limit=5&page=1", search.first.c_str());
  ASSERT_STREQ("id=8337447655053578871&previousBlock=6440284271011893973&version=0", search.second.c_str());
}

/***/

TEST(paths, test_delegates) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Delegates::base();
  ASSERT_STREQ("/api/v2/delegates", base);

  const auto get = Ark::Client::API::Paths::Delegates::get(testHost, "boldninja");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/delegates/boldninja", get.c_str());

  const auto all = Ark::Client::API::Paths::Delegates::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/delegates?limit=5&page=1", all.c_str());

  const auto blocks = Ark::Client::API::Paths::Delegates::blocks(testHost, "boldninja", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/delegates/boldninja/blocks?limit=5&page=1", blocks.c_str());

  const auto voters = Ark::Client::API::Paths::Delegates::voters(testHost, "boldninja", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/delegates/boldninja/voters?limit=5&page=1", voters.c_str());
}

/***/

TEST(paths, test_node) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Node::base();
  ASSERT_STREQ("/api/v2/node", base);

  const auto configuration = Ark::Client::API::Paths::Node::configuration(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/node/configuration", configuration.c_str());

  const auto status = Ark::Client::API::Paths::Node::status(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/node/status", status.c_str());

  const auto syncing = Ark::Client::API::Paths::Node::syncing(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/node/syncing", syncing.c_str());
}

/***/

TEST(paths, test_peers) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Peers::base();
  ASSERT_STREQ("/api/v2/peers", base);

  const auto get = Ark::Client::API::Paths::Peers::get(testHost, "0.0.0.0");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/peers/0.0.0.0", get.c_str());

  const auto all = Ark::Client::API::Paths::Peers::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/peers?limit=5&page=1", all.c_str());
}

/***/

TEST(paths, test_transactions) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Transactions::base();
  ASSERT_STREQ("/api/v2/transactions", base);

  const auto getUnconfirmed = Ark::Client::API::Paths::Transactions::getUnconfirmed(
      testHost, "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/v2/transactions/unconfirmed/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
      getUnconfirmed.c_str());

  const auto all = Ark::Client::API::Paths::Transactions::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions?limit=5&page=1", all.c_str());

  const auto get = Ark::Client::API::Paths::Transactions::get(
      testHost, "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
               get.c_str());

  const auto allUnconfirmed = Ark::Client::API::Paths::Transactions::allUnconfirmed(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions/unconfirmed?limit=5&page=1", allUnconfirmed.c_str());

  const auto types = Ark::Client::API::Paths::Transactions::types(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions/types", types.c_str());

  const std::map<std::string, std::string> searchBody = {{"id", "dummy"}};
  const auto search = Ark::Client::API::Paths::Transactions::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions/search?limit=5&page=1", search.first.c_str());
  ASSERT_STREQ("id=dummy", search.second.c_str());

  std::string jsonTransaction = "{\"id\":\"5ab523d18ac948da82700a71fc0b3c9e764fc0cba91927cb1aa63354564ad23f\",\"signature\":\"3045022100a6da60f9b3e20c80f491d168b8c51a85e0ec56a2448f9e10fc4bcc05a2bf79b8022078fa21b7d46e14c62d38f07e408fdb52f7b6a671894c6d0762913ca4a55e7a99\",\"timestamp\":4076176416,\"type\":0,\"fee\":10000000,\"senderPublicKey\":\"02f21aca9b6d224ea86a1689f57910534af21c3cc9f80602fed252c13e275f0699\",\"amount\":1,\"recipientId\":\"DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA\",\"vendorField\":\"7ad0eeb302ee7d9b4e58cf52daa9ece7922ad92d14f0407e3881597bf3c9c1c6\"}";
  const auto send = Ark::Client::API::Paths::Transactions::send(testHost, jsonTransaction);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/transactions/", send.first.c_str());
  ASSERT_STREQ(jsonTransaction.c_str(), send.second.c_str());
}

/***/

TEST(paths, test_votes) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Votes::base();
  ASSERT_STREQ("/api/v2/votes", base);

  const auto get =
      Ark::Client::API::Paths::Votes::get(testHost, "d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/votes/d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2",
               get.c_str());

  const auto all = Ark::Client::API::Paths::Votes::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/votes?limit=5&page=1", all.c_str());
}

/***/

TEST(paths, test_wallets) {  // NOLINT
  const auto base = Ark::Client::API::Paths::Wallets::base();
  ASSERT_STREQ("/api/v2/wallets", base);

  const auto get = Ark::Client::API::Paths::Wallets::get(testHost, "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu", get.c_str());

  const auto all = Ark::Client::API::Paths::Wallets::all(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets?limit=5&page=1", all.c_str());

  const auto top = Ark::Client::API::Paths::Wallets::top(testHost, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/top?limit=5&page=1", top.c_str());

  const auto transactions =
      Ark::Client::API::Paths::Wallets::transactions(testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=5&page=1",
               transactions.c_str());

  const auto sent =
      Ark::Client::API::Paths::Wallets::transactionsSent(testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/sent?limit=5&page=1",
               sent.c_str());

  const auto received =
      Ark::Client::API::Paths::Wallets::transactionsReceived(testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=5&page=1",
               received.c_str());

  const auto votes = Ark::Client::API::Paths::Wallets::votes(testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/votes?limit=5&page=1", votes.c_str());

  const std::map<std::string, std::string> searchBody = {
      {"username", "baldninja"},
      {"address", "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T"},
      {"publicKey", "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d"}};
  const auto search = Ark::Client::API::Paths::Wallets::search(testHost, searchBody, 5, 1);
  ASSERT_STREQ("0.0.0.0:4003/api/v2/wallets/search?limit=5&page=1", search.first.c_str());
  ASSERT_STREQ(
      "address=DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T&publicKey="
      "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d&username=baldninja",
      search.second.c_str());
}
