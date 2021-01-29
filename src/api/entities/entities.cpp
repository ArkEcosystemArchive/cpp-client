/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/entities/entities.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/entities/entities_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Entities::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_ENTITIES).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Entities::get(const std::string &entityId) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_ENTITIES).append("/").append(entityId));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
