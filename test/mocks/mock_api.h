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

#include "arkClient.h"
#include "http/http.h"
#include "mocks/mock_http.h"

class MockBlocks : public Ark::Client::API::IBlocks
{
public:
  MockBlocks(Ark::Client::IHTTP& http) : IBlocks(http) { }

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
  MOCK_METHOD1(transactions, std::string(const char* const));
  MOCK_METHOD3(search, std::string(const std::map<std::string, std::string>&, int, int));
};

class MockDelegates : public Ark::Client::API::IDelegates
{
public:
  MockDelegates(Ark::Client::IHTTP& http) : IDelegates(http) { }

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
  MOCK_METHOD3(blocks, std::string(const char* const, int, int));
  MOCK_METHOD3(voters, std::string(const char* const, int, int));
};

class MockNode : public Ark::Client::API::INode {
public:
  MockNode(Ark::Client::IHTTP& http) : INode(http) { }

  MOCK_METHOD0(configuration, std::string());
  MOCK_METHOD0(status, std::string());
  MOCK_METHOD0(syncing, std::string());
};

class MockPeers : public Ark::Client::API::IPeers
{
public:
  MockPeers(Ark::Client::IHTTP& http) : IPeers(http) { }

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
};

class MockTransactions : public Ark::Client::API::ITransactions
{
public:
  MockTransactions(Ark::Client::IHTTP& http) : ITransactions(http) { }

  MOCK_METHOD1(getUnconfirmed, std::string(const char* const));
  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
  MOCK_METHOD2(allUnconfirmed, std::string(int, int));
  MOCK_METHOD0(types, std::string());
  MOCK_METHOD3(search, std::string(const std::map<std::string, std::string>&, int, int));
};

class MockVotes : public Ark::Client::API::IVotes
{
public:
  MockVotes(Ark::Client::IHTTP& http) : IVotes(http) { }

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
};

class MockWallets : public Ark::Client::API::IWallets
{
public:
  MockWallets(Ark::Client::IHTTP& http) : IWallets(http) { }

  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(all, std::string(int, int));
  MOCK_METHOD2(top, std::string(int, int));
  MOCK_METHOD3(transactions, std::string(const char* const, int, int));
  MOCK_METHOD3(transactionsReceived, std::string(const char* const, int, int));
  MOCK_METHOD3(transactionsSent, std::string(const char* const, int, int));
  MOCK_METHOD3(votes, std::string(const char* const, int, int));
  MOCK_METHOD3(search, std::string(const std::map<std::string, std::string>&, int, int));
};

class MockApi : public Ark::Client::API::Abstract
{
public:
  MockBlocks blocks;
  MockDelegates delegates;
  MockNode node;
  MockPeers peers;
  MockTransactions transactions;
  MockVotes votes;
  MockWallets wallets;

  MockApi() : Abstract(new MockHTTP(), 2), blocks(*http_), delegates(*http_), node(*http_), peers(*http_), transactions(*http_), votes(*http_), wallets(*http_) { }
};

#endif