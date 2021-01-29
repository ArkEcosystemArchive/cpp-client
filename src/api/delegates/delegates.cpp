/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/delegates/delegates.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/delegates/delegates_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Delegates::all(const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_DELEGATES).append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Delegates::get(const std::string &identifier) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_DELEGATES).append("/").append(identifier));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Delegates::blocks(const std::string &identifier,
                              const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_DELEGATES)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_DELEGATES_BLOCKS_ENDPOINT)
                      .append(query));
  return response;
}

////////////////////////////////////////////////////////////////////////////////
std::string Delegates::voters(const std::string &identifier,
                              const std::string &query) {
  const auto response = this->apiHandler_->process(
      ACTION_GET, std::string(PATHS_DELEGATES)
                      .append("/")
                      .append(identifier)
                      .append(PATHS_DELEGATES_VOTERS_ENDPOINT)
                      .append(query));
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
