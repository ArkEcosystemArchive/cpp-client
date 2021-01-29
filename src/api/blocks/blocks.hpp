/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_BLOCKS_HPP
#define API_BLOCKS_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"
#include "api/paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Blocks : public ApiBase {
 public:
  Blocks(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string all(const std::string &query = DEFAULT_QUERY);
  std::string get(const std::string &identifier);

  std::string first();
  std::string last();

  std::string transactions(const std::string &identifier,
                           const std::string &query = DEFAULT_QUERY);
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_BLOCKS_HPP
