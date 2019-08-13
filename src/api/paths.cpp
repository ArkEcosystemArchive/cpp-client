
#include "api/paths.h"

/**
 * Blockchain
 **/
const char* Ark::Client::API::Paths::Blockchain::base() {
  return "/api/blockchain";
}

/**/
std::string Ark::Client::API::Paths::Blockchain::get(
    Host& newHost) {
  char url[56] = {};
  snprintf(url, sizeof(url),
      "%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Blockchain::base());
  return url;
}

/****/

/**
 * Blocks
 **/
const char* Ark::Client::API::Paths::Blocks::base() {
  return "/api/blocks";
}

/**/
std::string Ark::Client::API::Paths::Blocks::get(
    Host& newHost,
    const char* const blockId) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Blocks::base(),
      blockId);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Blocks::all(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Blocks::base(),
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Blocks::transactions(
    Host& newHost,
    const char* const blockId) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/transactions",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Blocks::base(),
      blockId);
  return url;
}

/**/

std::pair<std::string, std::string> Ark::Client::API::Paths::Blocks::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  char uri[96] = {};
  snprintf(
      uri, sizeof(uri),
      "%s%s/search%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Blocks::base(),
      query);
  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return {uri, parameterBuffer.c_str()};
}

/****/

/**
 * Delegates
 **/
const char* Ark::Client::API::Paths::Delegates::base() {
  return "/api/delegates";
}

/**/

std::string Ark::Client::API::Paths::Delegates::get(
    Host& newHost,
    const char* const identifier) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(), 
      Ark::Client::API::Paths::Delegates::base(),
      identifier);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Delegates::all(
    Host& newHost,
    const char* const query) {
  char uri[128] = {};
  snprintf(
      uri, sizeof(uri),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Delegates::base(),
      query);
  return uri;
}

/**/

std::string Ark::Client::API::Paths::Delegates::blocks(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/blocks%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Delegates::base(),
      identifier,
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Delegates::voters(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/voters%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Delegates::base(),
      identifier,
      query);
  return url;
}

/****/

/**
 * Node
 **/
const char* Ark::Client::API::Paths::Node::base() {
  return "/api/node";
}

/**/

std::string Ark::Client::API::Paths::Node::configuration(Host& newHost) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/configuration",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Node::base());
  return url;
}

/**/

std::string Ark::Client::API::Paths::Node::status(Host& newHost) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/status",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Node::base());
  return url;
}

/**/

std::string Ark::Client::API::Paths::Node::syncing(Host& newHost) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/syncing",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Node::base());
  return url;
}

/****/

/**
 * Peers
 **/
const char* Ark::Client::API::Paths::Peers::base() {
  return "/api/peers";
}

/**/

std::string Ark::Client::API::Paths::Peers::get(
    Host& newHost,
    const char* const ip) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Peers::base(),
      ip);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Peers::all(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Peers::base(),
      query);
  return url;
}

/****/

/**
 * Transactions
 **/
const char* Ark::Client::API::Paths::Transactions::base() {
  return "/api/transactions";
}

/**/

std::string Ark::Client::API::Paths::Transactions::getUnconfirmed(
    Host& newHost,
    const char* const identifier) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/unconfirmed/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base(),
      identifier);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Transactions::all(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base(),
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Transactions::get(
    Host& newHost,
    const char* const identifier) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base(),
      identifier);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Transactions::allUnconfirmed(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/unconfirmed%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base(),
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Transactions::types(Host& newHost) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/types",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base());
  return url;
}

/**/

std::pair<std::string, std::string> Ark::Client::API::Paths::Transactions::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  char uri[96] = {};
  snprintf(
      uri, sizeof(uri),
      "%s%s/search%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base(),
      query);
  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return {uri, parameterBuffer.c_str()};
}

/**/

std::pair<std::string, std::string> Ark::Client::API::Paths::Transactions::send(
    Host& newHost,
    std::string& jsonTransaction) {
  char uri[96] = {};
  snprintf(
      uri, sizeof(uri),
      "%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Transactions::base());
  return {uri, jsonTransaction.c_str()};
}

/****/

/**
 * Votes
 **/
const char* Ark::Client::API::Paths::Votes::base() {
  return "/api/votes";
}

/**/

std::string Ark::Client::API::Paths::Votes::get(
    Host& newHost,
    const char* const identifier) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Votes::base(),
      identifier);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Votes::all(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Votes::base(),
      query);
  return url;
}

/****/

/**
 * Wallets
 **/
const char* Ark::Client::API::Paths::Wallets::base() {
  return "/api/wallets";
}

/**/

std::string Ark::Client::API::Paths::Wallets::get(
    Host& newHost,
    const char* const identifier) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
     identifier);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::all(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::top(
    Host& newHost,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/top%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::transactions(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/transactions%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      identifier,
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::transactionsSent(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/transactions/sent%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      identifier,
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::transactionsReceived(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/transactions/received%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      identifier,
      query);
  return url;
}

/**/

std::string Ark::Client::API::Paths::Wallets::votes(
    Host& newHost,
    const char* const identifier,
    const char* const query) {
  char url[128] = {};
  snprintf(
      url, sizeof(url),
      "%s%s/%s/votes%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      identifier,
      query);
  return url;
}

/**/

std::pair<std::string, std::string> Ark::Client::API::Paths::Wallets::search(
    Host& newHost,
    const std::map<std::string, std::string>& bodyParameters,
    const char* const query) {
  char uri[96] = {};
  snprintf(
      uri, sizeof(uri),
      "%s%s/search%s",
      newHost.toString().c_str(),
      Ark::Client::API::Paths::Wallets::base(),
      query);
  std::string parameterBuffer;
  auto count = 0UL;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    };
  };
  return {uri, parameterBuffer.c_str()};
}
