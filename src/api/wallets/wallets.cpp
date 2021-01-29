/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/wallets/wallets.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/wallets/wallets_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::get(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS).append("/").append(identifier));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::locks(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_WALLETS_LOCKS_ENDPOINT));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::top(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS_TOP).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::votes(const std::string &identifier,
                           const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_WALLETS_VOTES_ENDPOINT)
                      .append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::transactions(const std::string &identifier,
                                  const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_WALLETS_TRANSACTIONS_ENDPOINT)
                      .append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::transactionsSent(const std::string &identifier,
                                      const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_WALLETS_TRANSACTIONS_SENT_ENDPOINT)
                      .append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Wallets::transactionsReceived(const std::string &identifier,
                                          const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_WALLETS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_WALLETS_TRANSACTIONS_RECEIVED_ENDPOINT)
                      .append(query));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
