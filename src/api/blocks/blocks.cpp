/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/blocks/blocks.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/blocks/blocks_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Blocks::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_BLOCKS).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Blocks::get(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_BLOCKS).append("/").append(identifier));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Blocks::first() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_BLOCKS_FIRST);
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Blocks::last() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_BLOCKS_LAST);
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Blocks::transactions(const std::string &identifier,
                                 const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_BLOCKS)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_BLOCKS_TRANSACTIONS_ENDPOINT)
                      .append(query));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
