/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/votes/votes.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/votes/votes_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Votes::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_VOTES).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Votes::get(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_VOTES).append("/").append(identifier));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
