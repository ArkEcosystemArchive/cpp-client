/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef MOCK_API_H
#define MOCK_API_H

#include "gmock/gmock.h"

#include "arkClient.h"
#include "host/host.h"
#include "http/http.h"
#include "mocks/mock_http.h"

class MockBlockchain : public Ark::Client::api::IBlockchain {  // NOLINT
public:
  MockBlockchain(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IBlockchain(host, http) {}

  MOCK_METHOD0(get, std::string());
};

/**/

class MockBlocks : public Ark::Client::api::IBlocks {  // NOLINT
public:
  MockBlocks(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IBlocks(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD0(first, std::string());
  MOCK_METHOD0(last, std::string());
  MOCK_METHOD1(all, std::string(const char* const));
  MOCK_METHOD1(transactions, std::string(const char* const));
  MOCK_METHOD2(search, std::string(const std::map<std::string, std::string>&, const char* const));
};

/**/

class MockDelegates : public Ark::Client::api::IDelegates {  // NOLINT
public:
  MockDelegates(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IDelegates(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
  MOCK_METHOD2(blocks, std::string(const char* const, const char* const));
  MOCK_METHOD2(voters, std::string(const char* const, const char* const));
};

/**/

class MockLocks : public Ark::Client::api::ILocks {  // NOLINT
public:
  MockLocks(Ark::Client::Host& host, Ark::Client::IHTTP& http) : ILocks(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
  MOCK_METHOD2(search, std::string(const std::map<std::string, std::string>&, const char* const));
  MOCK_METHOD2(unlocked, std::string(std::string&, const char* const));
};

/**/

class MockNode : public Ark::Client::api::INode {  // NOLINT
public:
  MockNode(Ark::Client::Host& host, Ark::Client::IHTTP& http) : INode(host, http) {}

  MOCK_METHOD0(configuration, std::string());
  MOCK_METHOD0(crypto, std::string());
  MOCK_METHOD1(fees, std::string(const char* const));
  MOCK_METHOD0(status, std::string());
  MOCK_METHOD0(syncing, std::string());
};

/**/

class MockPeers : public Ark::Client::api::IPeers {  // NOLINT
public:
  MockPeers(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IPeers(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
};

/**/

class MockRounds : public Ark::Client::api::IRounds {  // NOLINT
public:
  MockRounds(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IRounds(host, http) {}

  MOCK_METHOD1(delegates, std::string(const char* const));
};

/**/

class MockTransactions : public Ark::Client::api::ITransactions {  // NOLINT
public:
  MockTransactions(Ark::Client::Host& host, Ark::Client::IHTTP& http) : ITransactions(host, http) {}

  MOCK_METHOD1(getUnconfirmed, std::string(const char* const));
  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
  MOCK_METHOD1(allUnconfirmed, std::string(const char* const));
  MOCK_METHOD0(types, std::string());
  MOCK_METHOD0(fees, std::string());
  MOCK_METHOD2(search, std::string(const std::map<std::string, std::string>&, const char* const));
  MOCK_METHOD1(send, std::string(std::string&));
};

/**/

class MockVotes : public Ark::Client::api::IVotes {  // NOLINT
public:
  MockVotes(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IVotes(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
};

/**/

class MockWallets : public Ark::Client::api::IWallets {  // NOLINT
public:
  MockWallets(Ark::Client::Host& host, Ark::Client::IHTTP& http) : IWallets(host, http) {}

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD1(all, std::string(const char* const));
  MOCK_METHOD1(top, std::string(const char* const));
  MOCK_METHOD2(locks, std::string(const char* const, const char* const));
  MOCK_METHOD2(transactions, std::string(const char* const, const char* const));
  MOCK_METHOD2(transactionsReceived, std::string(const char* const, const char* const));
  MOCK_METHOD2(transactionsSent, std::string(const char* const, const char* const));
  MOCK_METHOD2(votes, std::string(const char* const, const char* const));
  MOCK_METHOD2(search, std::string(const std::map<std::string, std::string>&, const char* const));
};

/**/

class MockApi : public Ark::Client::api::Abstract {
public:
  MockBlockchain blockchain;
  MockBlocks blocks;
  MockDelegates delegates;
  MockLocks locks;
  MockNode node;
  MockPeers peers;
  MockRounds rounds;
  MockTransactions transactions;
  MockVotes votes;
  MockWallets wallets;

  MockApi() : Abstract(new MockHTTP()),
              blockchain(host_, *http_),
              blocks(host_, *http_),
              delegates(host_, *http_),
              locks(host_, *http_),
              node(host_, *http_),
              peers(host_, *http_),
              rounds(host_, *http_),
              transactions(host_, *http_),
              votes(host_, *http_),
              wallets(host_, *http_) {}
};

#endif
