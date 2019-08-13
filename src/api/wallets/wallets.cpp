
#include "api/wallets/wallets.h"

std::string Ark::Client::API::Wallets::get(
    const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Wallets::get(
      this->host_,
      identifier).c_str());
}

/**/

std::string Ark::Client::API::Wallets::all(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::all(
      this->host_,
      query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::top(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::top(
      this->host_,
      query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::transactions(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::transactions(
      this->host_,
      identifier,
      query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::transactionsSent(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::transactionsSent(
      this->host_,
      identifier,
      query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::transactionsReceived(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::transactionsReceived(
      this->host_,
      identifier,
      query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::votes(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Wallets::votes(
      this->host_,
      identifier, query).c_str());
}

/**/

std::string Ark::Client::API::Wallets::search(
    const std::map<std::string, std::string> &bodyParameters,
    const char* const query) {
  const auto searchPathPair = Ark::Client::API::Paths::Wallets::search(
      this->host_,
      bodyParameters,
      query);
  return http_->post(searchPathPair.first.c_str(), searchPathPair.second.c_str());
}
