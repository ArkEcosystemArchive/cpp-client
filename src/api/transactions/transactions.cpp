
#include "api/transactions/transactions.h"

std::string Ark::Client::API::Transactions::getUnconfirmed(const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Transactions::getUnconfirmed(this->host_, identifier).c_str());
}

/***/

std::string Ark::Client::API::Transactions::all(int limit /* = 5 */, int page /* = 1 */) {
  return http_->get(Ark::Client::API::Paths::Transactions::all(this->host_, limit, page).c_str());
}

/***/

std::string Ark::Client::API::Transactions::get(const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Transactions::get(this->host_, identifier).c_str());
}

/***/

std::string Ark::Client::API::Transactions::allUnconfirmed(int limit /* = 5 */, int page /* =1 */) {
  return http_->get(Ark::Client::API::Paths::Transactions::allUnconfirmed(this->host_, limit, page).c_str());
}

/***/

std::string Ark::Client::API::Transactions::types() {
  return http_->get(Ark::Client::API::Paths::Transactions::types(this->host_).c_str());
}

/***/

std::string Ark::Client::API::Transactions::search(const std::map<std::string, std::string> &bodyParameters,
                                                   int limit /* = 5 */, int page /* = 1 */) {
  const auto searchPathPair = Ark::Client::API::Paths::Transactions::search(this->host_, bodyParameters, limit, page);
  return http_->post(searchPathPair.first.c_str(), searchPathPair.second.c_str());
}
