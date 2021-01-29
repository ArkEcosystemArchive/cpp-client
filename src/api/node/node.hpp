/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_NODE_HPP
#define API_NODE_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"
#include "api/paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Node : public ApiBase {
 public:
  Node(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string configuration();
  std::string crypto();
  std::string fees(const std::string &query = DEFAULT_DAYS_QUERY);
  std::string status();
  std::string syncing();
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_NODE_HPP
