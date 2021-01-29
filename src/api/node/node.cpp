/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/node/node.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/node/node_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Node::configuration() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_NODE_CONFIGURATION);
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Node::crypto() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_NODE_CRYPTO);
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Node::fees(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_NODE_FEES).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Node::status() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_NODE_STATUS);
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Node::syncing() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_NODE_SYNCING);
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
