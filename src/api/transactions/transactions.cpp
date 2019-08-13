
#include "api/transactions/transactions.h"

std::string Ark::Client::API::Transactions::getUnconfirmed(
    const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Transactions::getUnconfirmed(
      this->host_,
      identifier).c_str());
}

/**/

std::string Ark::Client::API::Transactions::all(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Transactions::all(
      this->host_,
      query).c_str());
}

/**/

std::string Ark::Client::API::Transactions::get(
    const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Transactions::get(
      this->host_,
      identifier).c_str());
}

/**/

std::string Ark::Client::API::Transactions::allUnconfirmed(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Transactions::allUnconfirmed(
      this->host_,
      query).c_str());
}

/**/

std::string Ark::Client::API::Transactions::types() {
  return http_->get(Ark::Client::API::Paths::Transactions::types(
    this->host_).c_str());
}

/**/

std::string Ark::Client::API::Transactions::search(
    const std::map<std::string, std::string> &bodyParameters,
    const char* const query) {
  const auto searchPathPair = Ark::Client::API::Paths::Transactions::search(
      this->host_,
      bodyParameters,
      query);
  return http_->post(searchPathPair.first.c_str(), searchPathPair.second.c_str());
}

/**/

std::string Ark::Client::API::Transactions::send(
    std::string& jsonTransaction) {
  const auto pathPair = Ark::Client::API::Paths::Transactions::send(
      this->host_,
      jsonTransaction);
  return http_->post(pathPair.first.c_str(), pathPair.second.c_str());
};

