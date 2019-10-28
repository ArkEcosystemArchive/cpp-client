
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "arkClient.h"

namespace {
using namespace Ark::Client;
using namespace Ark::Client::api;
constexpr const char* tIp = "0.0.0.0";
constexpr const int tPort = 4003;
constexpr const int tLimit = 5;
constexpr const int tPage = 1;
Host testHost(tIp, tPort);
}  // namespace

/**/

TEST(paths, test_blockchain) {
  const auto base = paths::Blockchain::base();
  ASSERT_STREQ("/api/blockchain", base);

  const auto get = paths::Blockchain::get(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/blockchain", get.c_str());
}

/**/

TEST(paths, test_blocks) {
  const auto base = paths::Blocks::base();
  ASSERT_STREQ("/api/blocks", base);

  const auto get = paths::Blocks::get(testHost, "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/58328125061111756", get.c_str());

  const auto all = paths::Blocks::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks?limit=1&page=5", all.c_str());

  const auto transactions = paths::Blocks::transactions(testHost,
                                                        "58328125061111756");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/58328125061111756/transactions",
               transactions.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "id", "8337447655053578871" },
    { "previousBlock", "6440284271011893973" },
    { "version", "0" }
  };
  const auto search = paths::Blocks::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/blocks/search?limit=1&page=5",
               search.first.c_str());
  ASSERT_STREQ(
      "id=8337447655053578871&previousBlock=6440284271011893973&version=0",
      search.second.c_str());
}

/**/

TEST(paths, test_businesses) {
  const auto base = paths::Businesses::base();
  ASSERT_STREQ("/api/businesses", base);

  const auto get = paths::Businesses::get(testHost, "12345");
  ASSERT_STREQ("0.0.0.0:4003/api/businesses/12345", get.c_str());

  const auto all = paths::Businesses::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/businesses?limit=1&page=5", all.c_str());

  const auto bridgechains = paths::Businesses::bridgechains(testHost,
                                                            "12345",
                                                            "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/businesses/12345/bridgechains?limit=1&page=5",
               bridgechains.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "businessId", "12345" }
  };
  const auto search = paths::Businesses::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/businesses/search?limit=1&page=5",
               search.first.c_str());
  ASSERT_STREQ(
      "businessId=12345",
      search.second.c_str());
}

/**/

TEST(paths, test_bridgechains) {
  const auto base = paths::Bridgechains::base();
  ASSERT_STREQ("/api/bridgechains", base);

  const auto get = paths::Bridgechains::get(testHost, "12345");
  ASSERT_STREQ("0.0.0.0:4003/api/bridgechains/12345", get.c_str());

  const auto all = paths::Bridgechains::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/bridgechains?limit=1&page=5", all.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "bridgechainId", "12345" }
  };
  const auto search = paths::Bridgechains::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/bridgechains/search?limit=1&page=5",
               search.first.c_str());
  ASSERT_STREQ(
      "bridgechainId=12345",
      search.second.c_str());
}

/**/

TEST(paths, test_delegates) {
  const auto base = paths::Delegates::base();
  ASSERT_STREQ("/api/delegates", base);

  const auto get = paths::Delegates::get(testHost, "boldninja");
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja", get.c_str());

  const auto all = paths::Delegates::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/delegates?limit=1&page=5", all.c_str());

  const auto blocks = paths::Delegates::blocks(testHost, "boldninja", "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja/blocks?limit=1&page=5",
               blocks.c_str());

  const auto voters = paths::Delegates::voters(testHost, "boldninja", "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/delegates/boldninja/voters?limit=1&page=5",
               voters.c_str());
}

/**/

TEST(paths, test_locks) {
  const auto base = paths::Locks::base();
  ASSERT_STREQ("/api/locks", base);

  const auto get = paths::Locks::get(testHost, "12345");
  ASSERT_STREQ("0.0.0.0:4003/api/locks/12345", get.c_str());

  const auto all = paths::Locks::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/locks?limit=1&page=5", all.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "lockId", "12345" }
  };
  const auto search = paths::Locks::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/locks/search?limit=1&page=5",
               search.first.c_str());
  ASSERT_STREQ(
      "lockId=12345",
      search.second.c_str());

  const std::map<std::string, std::string> unlockedBody = {
    { "lockId", "12345" }
  };
  const auto unlocked = paths::Locks::unlocked(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/locks/unlocked?limit=1&page=5",
               unlocked.first.c_str());
  ASSERT_STREQ(
      "lockId=12345",
      unlocked.second.c_str());
}

/**/

TEST(paths, test_node) {
  const auto base = paths::Node::base();
  ASSERT_STREQ("/api/node", base);

  const auto configuration = paths::Node::configuration(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/configuration", configuration.c_str());

  const auto crypto = paths::Node::crypto(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/configuration/crypto", crypto.c_str());

  const auto status = paths::Node::status(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/status", status.c_str());

  const auto syncing = paths::Node::syncing(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/node/syncing", syncing.c_str());
}

/**/

TEST(paths, test_peers) {
  const auto base = paths::Peers::base();
  ASSERT_STREQ("/api/peers", base);

  const auto get = paths::Peers::get(testHost, "0.0.0.0");
  ASSERT_STREQ("0.0.0.0:4003/api/peers/0.0.0.0", get.c_str());

  const auto all = paths::Peers::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/peers?limit=1&page=5", all.c_str());
}

/**/

TEST(paths, test_rounds) {
  const auto base = paths::Rounds::base();
  ASSERT_STREQ("/api/rounds", base);

  const auto delegates = paths::Rounds::delegates(testHost, "12345");
  ASSERT_STREQ("0.0.0.0:4003/api/rounds/12345/delegates", delegates.c_str());
}

/**/

TEST(paths, test_transactions) {  // NOLINT
  const auto base = paths::Transactions::base();
  ASSERT_STREQ("/api/transactions", base);

  const auto getUnconfirmed = paths::Transactions::getUnconfirmed(
      testHost,
      "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/transactions/unconfirmed/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
      getUnconfirmed.c_str());

  const auto all = paths::Transactions::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/transactions?limit=1&page=5", all.c_str());

  const auto get = paths::Transactions::get(
      testHost,
      "4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/transactions/4bbc5433e5a4e439369f1f57825e92d07cf9cb8e07aada69c122a2125e4b9d48",
      get.c_str());

  const auto allUnconfirmed = paths::Transactions::allUnconfirmed(
      testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/unconfirmed?limit=1&page=5",
               allUnconfirmed.c_str());

  const auto types = paths::Transactions::types(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/types", types.c_str());

  const auto fees = paths::Transactions::fees(testHost);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/fees", fees.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "id", "dummy" },
    { "key", "value" }
  };
  const auto search = paths::Transactions::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/transactions/search?limit=1&page=5",
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
  const auto send = paths::Transactions::send(testHost, jsonTransaction);
  ASSERT_STREQ("0.0.0.0:4003/api/transactions", send.first.c_str());
  ASSERT_STREQ(jsonTransaction.c_str(), send.second.c_str());
}

/**/

TEST(paths, test_votes) {  // NOLINT
  const auto base = paths::Votes::base();
  ASSERT_STREQ("/api/votes", base);

  const auto get = paths::Votes::get(
      testHost,
      "d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/votes/d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2",
      get.c_str());

  const auto all = paths::Votes::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/votes?limit=1&page=5", all.c_str());
}

/**/

TEST(paths, test_wallets) {  // NOLINT
  const auto base = paths::Wallets::base();
  ASSERT_STREQ("/api/wallets", base);

  const auto get = paths::Wallets::get(testHost,
                                       "DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu");
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/DKrACQw7ytoU2gjppy3qKeE2dQhZjfXYqu",
               get.c_str());

  const auto all = paths::Wallets::all(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/wallets?limit=1&page=5", all.c_str());

  const auto top = paths::Wallets::top(testHost, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/top?limit=1&page=5", top.c_str());

  const auto locks = paths::Wallets::locks(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", "?limit=1&page=5");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/locks?limit=1&page=5",
      locks.c_str());

  const auto transactions = paths::Wallets::transactions(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", "?limit=1&page=5");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions?limit=1&page=5",
      transactions.c_str());

  const auto sent = paths::Wallets::transactionsSent(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", "?limit=1&page=5");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/sent?limit=1&page=5",
      sent.c_str());

  const auto received = paths::Wallets::transactionsReceived(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", "?limit=1&page=5");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/transactions/received?limit=1&page=5",
      received.c_str());

  const auto votes = paths::Wallets::votes(
      testHost, "DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk", "?limit=1&page=5");
  ASSERT_STREQ(
      "0.0.0.0:4003/api/wallets/DNv1iScT2DJBWzpJd1AFYkTx1xkAZ9XVJk/votes?limit=1&page=5",
      votes.c_str());

  const std::map<std::string, std::string> searchBody = {
    { "username", "baldninja" },
    { "address", "DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T" },
    { "publicKey", "03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d" }
  };
  const auto search = paths::Wallets::search(testHost, searchBody, "?limit=1&page=5");
  ASSERT_STREQ("0.0.0.0:4003/api/wallets/search?limit=1&page=5",
               search.first.c_str());
  ASSERT_STREQ(
      "address=DFJ5Z51F1euNNdRUQJKQVdG4h495LZkc6T&publicKey=03d3c6889608074b44155ad2e6577c3368e27e6e129c457418eb3e5ed029544e8d&username=baldninja",
      search.second.c_str());
}
