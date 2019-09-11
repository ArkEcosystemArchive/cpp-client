/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/paths.h"

#include <string>


#include <iostream>

namespace Ark {
namespace Client {
namespace api {
namespace paths {

namespace {
constexpr const uint8_t URL_MAX_LEN = 128U;
}  //namespace

/**
 * Blockchain
 **/
const char* Blockchain::base() { return "/api/blockchain"; }

/**/
std::string Blockchain::get(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Blockchain::base();
  return url;
}

/****/

/**
 * Blocks
 **/
const char* Blocks::base() { return "/api/blocks"; }

/**/
std::string Blocks::get(Host& newHost, const char* blockId) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Blocks::base();
  url += "/";
  url += blockId;
  return url;
}

/**/

std::string Blocks::all(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Blocks::base();
  url += query;
  return url;
}

/**/

std::string Blocks::transactions(Host& newHost, const char* blockId) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Blocks::base();
  url += "/";
  url += blockId;
  url += "/transactions";
  return url;
}

/**/

std::pair<std::string, std::string> Blocks::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Blocks::base();
  url += "/search";
  url += query;

  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return { url, parameterBuffer };
}

/****/

/**
 * Delegates
 **/
const char* Delegates::base() { return "/api/delegates"; }

/**/

std::string Delegates::get(Host& newHost, const char* identifier) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Delegates::base();
  url += "/";
  url += identifier;
  return url;
}

/**/

std::string Delegates::all( Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Delegates::base();
  url += query;
  return url;
}

/**/

std::string Delegates::blocks(Host& newHost,
                              const char* const identifier,
                              const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Delegates::base();
  url += "/";
  url += identifier;
  url += "/blocks";
  url += query;
  return url;
}

/**/

std::string Delegates::voters(Host& newHost,
                              const char* const identifier,
                              const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Delegates::base();
  url += "/";
  url += identifier;
  url += "/voters";
  url += query;
  return url;
}

/****/

/**
 * Node
 **/
const char* Node::base() { return "/api/node"; }

/**/

std::string Node::configuration(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Node::base();
  url += "/configuration";
  return url;
}

/**/

std::string Node::crypto(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Node::base();
  url += "/configuration/crypto";
  return url;
}

/**/

std::string Node::status(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Node::base();
  url += "/status";
  return url;
}

/**/

std::string Node::syncing(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Node::base();
  url += "/syncing";
  return url;
}

/****/

/**
 * Peers
 **/
const char* Peers::base() { return "/api/peers"; }

/**/

std::string Peers::get(Host& newHost, const char* ip) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Peers::base();
  url += "/";
  url += ip;
  return url;
}

/**/

std::string Peers::all(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Peers::base();
  url += query;
  return url;
}

/****/

/**
 * Rounds
 **/
const char* Rounds::base() { return "/api/rounds"; }

/**/

std::string Rounds::delegates(Host& newHost, const char* roundId) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Rounds::base();
  url += "/";
  url += roundId;
  url += "/delegates";
  return url;
}

/****/

/**
 * Transactions
 **/
const char* Transactions::base() { return "/api/transactions"; }

/**/

std::string Transactions::getUnconfirmed(Host& newHost,
                                         const char* identifier) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += "/unconfirmed/";
  url += identifier;
  return url;
}

/**/

std::string Transactions::all(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += query;
  return url;
}

/**/

std::string Transactions::get(Host& newHost,const char* identifier) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += "/";
  url += identifier;
  return url;
}

/**/

std::string Transactions::allUnconfirmed(Host& newHost,
                                         const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += "/unconfirmed";
  url += query;
  return url;
}

/**/

std::string Transactions::types(Host& newHost) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += "/types";
  return url;
}

/**/

std::pair<std::string, std::string> Transactions::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();
  url += "/search";
  url += query;

  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return { url, parameterBuffer.c_str() };
}

/**/

std::pair<std::string, std::string> Transactions::send(
    Host& newHost,
    std::string& jsonTransaction) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Transactions::base();

  return { url.c_str(), jsonTransaction.c_str() };
}

/****/

/**
 * Votes
 **/
const char* Votes::base() { return "/api/votes"; }

/**/

std::string Votes::get(Host& newHost, const char* identifier) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Votes::base();
  url += "/";
  url += identifier;
  return url;
}

/**/

std::string Votes::all(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Votes::base();
  url += query;
  return url;
}

/****/

/**
 * Wallets
 **/
const char* Wallets::base() { return "/api/wallets"; }

/**/

std::string Wallets::get(Host& newHost, const char* identifier) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/";
  url += identifier;
  return url;
}

/**/

std::string Wallets::all(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += query;
  return url;
}

/**/

std::string Wallets::top(Host& newHost, const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/top";
  url += query;
  return url;
}

/**/

std::string Wallets::transactions(Host& newHost,
                                  const char* const identifier,
                                  const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/";
  url += identifier;
  url += "/transactions";
  url += query;
  return url;
}

/**/

std::string Wallets::transactionsSent(Host& newHost,
                                      const char* const identifier,
                                      const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/";
  url += identifier;
  url += "/transactions/sent";
  url += query;
  return url;
}

/**/

std::string Wallets::transactionsReceived(Host& newHost,
                                          const char* const identifier,
                                          const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/";
  url += identifier;
  url += "/transactions/received";
  url += query;
  return url;
}

/**/

std::string Wallets::votes(Host& newHost,
                           const char* const identifier,
                           const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/";
  url += identifier;
  url += "/votes";
  url += query;
  return url;
}

/**/

std::pair<std::string, std::string> Wallets::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  std::string url;
  url.reserve(URL_MAX_LEN);
  url += newHost.toString().c_str();
  url += Wallets::base();
  url += "/search";
  url += query;

  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return { url.c_str(), parameterBuffer.c_str() };
}

}  // namespace paths
}  // namespace api
}  // namespace Client
}  // namespace Ark
