/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/rounds/rounds.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/rounds/rounds_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Rounds::delegates(const std::string &roundId) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_ROUNDS)
                      .append("/")
                      .append(roundId)
                      .append(PATHS_ROUNDS_DELEGATES_ENDPOINT));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
