/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/transactions/transactions.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/transactions/transactions_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_TRANSACTIONS).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::allUnconfirmed(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_TRANSACTIONS_UNCONFIRMED).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::get(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET,
      std::string(PATHS_TRANSACTIONS).append("/").append(identifier));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::getUnconfirmed(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_TRANSACTIONS_UNCONFIRMED)
                      .append("/")
                      .append(identifier));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::fees() {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_TRANSACTIONS_FEES));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::types() {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_TRANSACTIONS_TYPES));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Transactions::send(const std::string &jsonTransaction) {
  const auto response = this->apiHandler_->process(
      ACTION_POST, PATHS_TRANSACTIONS, jsonTransaction);
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
