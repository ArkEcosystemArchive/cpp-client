/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/peers/peers.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/peers/peers_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Peers::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_PEERS).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Peers::get(const std::string &ip) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_PEERS).append("/").append(ip));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
