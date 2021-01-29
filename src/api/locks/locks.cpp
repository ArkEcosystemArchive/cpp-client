/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/locks/locks.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/locks/locks_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Locks::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_LOCKS).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Locks::get(const std::string &lockId) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_LOCKS).append("/").append(lockId));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Locks::unlocked(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET,
      std::string(PATHS_LOCKS_UNLOCKED).append("/").append(identifier));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
