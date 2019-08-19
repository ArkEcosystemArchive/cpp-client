/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/transactions/transactions.h"

namespace Ark {
namespace Client {
namespace api {

std::string Transactions::getUnconfirmed(const char* identifier) {
  return http_->get(paths::Transactions::getUnconfirmed(this->host_,
                                                        identifier).c_str());
}

/**/

std::string Transactions::all(const char* const query) {
  return http_->get(paths::Transactions::all(this->host_, query).c_str());
}

/**/

std::string Transactions::get(const char* identifier) {
  return http_->get(paths::Transactions::get(this->host_, identifier).c_str());
}

/**/

std::string Transactions::allUnconfirmed(const char* const query) {
  return http_->get(paths::Transactions::allUnconfirmed(this->host_,
                                                        query).c_str());
}

/**/

std::string Transactions::types() {
  return http_->get(paths::Transactions::types(this->host_).c_str());
}

/**/

std::string Transactions::search(
    const std::map<std::string, std::string> &bodyParameters,
    const char* const query) {
  const auto searchPathPair = paths::Transactions::search(this->host_,
                                                          bodyParameters,
                                                          query);
  return http_->post(searchPathPair.first.c_str(),
                     searchPathPair.second.c_str());
}

/**/

std::string Transactions::send(std::string& jsonTransaction) {
  const auto pathPair = paths::Transactions::send(this->host_, jsonTransaction);
  return http_->post(pathPair.first.c_str(), pathPair.second.c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
