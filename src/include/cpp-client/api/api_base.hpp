/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_API_BASE_HPP
#define API_API_BASE_HPP

#include "api/api_handler.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class ApiBase {
 protected:
  ApiHandler *apiHandler_;

  //////////////////////////////////////////////////////////////////////////////
  explicit ApiBase(ApiHandler &apiHandler) : apiHandler_(&apiHandler) {}
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_API_BASE_HPP
