/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_BLOCKCHAIN_HPP
#define API_BLOCKCHAIN_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Blockchain : public ApiBase {
 public:
  Blockchain(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string get();
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_BLOCKCHAIN_HPP
