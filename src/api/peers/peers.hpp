/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_PEERS_HPP
#define API_PEERS_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"
#include "api/paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Peers : public ApiBase {
 public:
  Peers(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string all(const std::string &query = DEFAULT_QUERY);
  std::string get(const std::string &ip);
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_PEERS_HPP
