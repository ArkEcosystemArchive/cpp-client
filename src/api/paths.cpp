
#include "api/paths.h"

/**
 * Blocks
 **/

const char* Ark::Client::API::Paths::Blocks::base() {
  return "/api/v2/blocks";
}

std::string Ark::Client::API::Paths::Blocks::get(Host& newHost, const char* const blockId) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Blocks::base(), blockId);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Blocks::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Blocks::base(), limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Blocks::transactions(Host& newHost, const char* const blockId) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/transactions", newHost.toString().c_str(),
           Ark::Client::API::Paths::Blocks::base(), blockId);
  return url;
}

/***/

std::pair<std::string, std::string> Ark::Client::API::Paths::Blocks::search(
    Host& newHost, const std::map<std::string, std::string>& bodyParameters, int limit /* = 5 */, int page /* = 1 */) {
  char uri[96] = {};
  snprintf(uri, sizeof(uri), "%s%s/search?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Blocks::base(), limit, page);
  std::string parameterBuffer;
  auto count = 0ul;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    }
  }
  return {uri, parameterBuffer.c_str()};
}

/******/

/**
 * Delegates
 **/

const char* Ark::Client::API::Paths::Delegates::base() {
  return "/api/v2/delegates";
}

std::string Ark::Client::API::Paths::Delegates::get(Host& newHost, const char* const identifier) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Delegates::base(),
           identifier);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Delegates::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char uri[128] = {};
  snprintf(uri, sizeof(uri), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Delegates::base(), limit, page);
  return uri;
}

/***/

std::string Ark::Client::API::Paths::Delegates::blocks(Host& newHost, const char* const identifier, int limit /* = 5 */,
                                                       int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/blocks?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Delegates::base(), identifier, limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Delegates::voters(Host& newHost, const char* const identifier, int limit /* = 5 */,
                                                       int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/voters?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Delegates::base(), identifier, limit, page);
  return url;
}

/******/

/**
 * Node
 **/

const char* Ark::Client::API::Paths::Node::base() {
  return "/api/v2/node";
}

std::string Ark::Client::API::Paths::Node::configuration(Host& newHost) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/configuration", newHost.toString().c_str(), Ark::Client::API::Paths::Node::base());
  return url;
}

/***/

std::string Ark::Client::API::Paths::Node::status(Host& newHost) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/status", newHost.toString().c_str(), Ark::Client::API::Paths::Node::base());
  return url;
}

/***/

std::string Ark::Client::API::Paths::Node::syncing(Host& newHost) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/syncing", newHost.toString().c_str(), Ark::Client::API::Paths::Node::base());
  return url;
}

/******/

/**
 * Peers
 **/

const char* Ark::Client::API::Paths::Peers::base() {
  return "/api/v2/peers";
}

std::string Ark::Client::API::Paths::Peers::get(Host& newHost, const char* const ip) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Peers::base(), ip);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Peers::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Peers::base(), limit, page);
  return url;
}

/******/

/**
 * Transactions
 **/

const char* Ark::Client::API::Paths::Transactions::base() {
  return "/api/v2/transactions";
}

std::string Ark::Client::API::Paths::Transactions::getUnconfirmed(Host& newHost, const char* const identifier) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/unconfirmed/%s", newHost.toString().c_str(),
           Ark::Client::API::Paths::Transactions::base(), identifier);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Transactions::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Transactions::base(), limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Transactions::get(Host& newHost, const char* const identifier) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Transactions::base(),
           identifier);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Transactions::allUnconfirmed(Host& newHost, int limit /* = 5 */,
                                                                  int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/unconfirmed?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Transactions::base(), limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Transactions::types(Host& newHost) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/types", newHost.toString().c_str(), Ark::Client::API::Paths::Transactions::base());
  return url;
}

/***/

std::pair<std::string, std::string> Ark::Client::API::Paths::Transactions::search(
    Host& newHost, const std::map<std::string, std::string>& bodyParameters, int limit /* = 5 */, int page /* = 1 */) {
  char uri[96] = {};
  snprintf(uri, sizeof(uri), "%s%s/search?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Transactions::base(), limit, page);
  std::string parameterBuffer;
  auto count = 0ul;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    }
  }
  return {uri, parameterBuffer.c_str()};
}

/***/

std::pair<std::string, std::string> Ark::Client::API::Paths::Transactions::send(Host& newHost, std::string& jsonTransaction) {
  char uri[96] = {};
  snprintf(
    uri,
    sizeof(uri),
    "%s%s/",
    newHost.toString().c_str(),
    Ark::Client::API::Paths::Transactions::base());
  return {uri, jsonTransaction.c_str()};
}

/******/

/**
 * Votes
 **/

const char* Ark::Client::API::Paths::Votes::base() {
  return "/api/v2/votes";
}

std::string Ark::Client::API::Paths::Votes::get(Host& newHost, const char* const identifier) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Votes::base(), identifier);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Votes::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Votes::base(), limit, page);
  return url;
}

/******/

/**
 * Wallets
 **/

const char* Ark::Client::API::Paths::Wallets::base() {
  return "/api/v2/wallets";
}

std::string Ark::Client::API::Paths::Wallets::get(Host& newHost, const char* const identifier) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s", newHost.toString().c_str(), Ark::Client::API::Paths::Wallets::base(),
           identifier);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::all(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::top(Host& newHost, int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/top?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::transactions(Host& newHost, const char* const identifier,
                                                           int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/transactions?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), identifier, limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::transactionsSent(Host& newHost, const char* const identifier,
                                                               int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/transactions/sent?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), identifier, limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::transactionsReceived(Host& newHost, const char* const identifier,
                                                                   int limit /* = 5 */, int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/transactions/received?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), identifier, limit, page);
  return url;
}

/***/

std::string Ark::Client::API::Paths::Wallets::votes(Host& newHost, const char* const identifier, int limit /* = 5 */,
                                                    int page /* = 1 */) {
  char url[128] = {};
  snprintf(url, sizeof(url), "%s%s/%s/votes?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), identifier, limit, page);
  return url;
}

/***/

std::pair<std::string, std::string> Ark::Client::API::Paths::Wallets::search(
    Host& newHost, const std::map<std::string, std::string>& bodyParameters, int limit /* = 5 */, int page /* = 1 */) {
  char uri[96] = {};
  snprintf(uri, sizeof(uri), "%s%s/search?limit=%d&page=%d", newHost.toString().c_str(),
           Ark::Client::API::Paths::Wallets::base(), limit, page);
  std::string parameterBuffer;
  auto count = 0ul;
  for (const auto& p : bodyParameters) {
    ++count;
    parameterBuffer += p.first + '=' + p.second;
    if (bodyParameters.size() > 1 && count < bodyParameters.size()) {
      parameterBuffer += '&';
    }
  }
  return {uri, parameterBuffer.c_str()};
}
