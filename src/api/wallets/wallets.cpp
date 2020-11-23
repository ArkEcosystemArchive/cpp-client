/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/wallets/wallets.h"

namespace Ark {
namespace Client {
namespace api {

std::string Wallets::get(const char* identifier) {
  return http_->get(paths::Wallets::get(this->host_, identifier).c_str());
}

/**/

std::string Wallets::all(const char* const query) {
  return http_->get(paths::Wallets::all(this->host_, query).c_str());
}

/**/

std::string Wallets::top(const char* const query) {
  return http_->get(paths::Wallets::top(this->host_, query).c_str());
}

/**/

std::string Wallets::locks(const char *const identifier,
                                  const char* const query) {
  return http_->get(paths::Wallets::locks(this->host_,
                                                 identifier,
                                                 query).c_str());
}

/**/

std::string Wallets::transactions(const char *const identifier,
                                  const char* const query) {
  return http_->get(paths::Wallets::transactions(this->host_,
                                                 identifier,
                                                 query).c_str());
}

/**/

std::string Wallets::transactionsSent(const char *const identifier,
                                      const char* const query) {
  return http_->get(paths::Wallets::transactionsSent(this->host_,
                                                     identifier,
                                                     query).c_str());
}

/**/

std::string Wallets::transactionsReceived(const char *const identifier,
                                          const char* const query) {
  return http_->get(paths::Wallets::transactionsReceived(this->host_,
                                                         identifier,
                                                         query).c_str());
}

/**/

std::string Wallets::votes(const char *const identifier,
                           const char* const query) {
  return http_->get(paths::Wallets::votes(this->host_,
                                          identifier,
                                          query).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
