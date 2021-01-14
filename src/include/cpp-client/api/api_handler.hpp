/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_API_HANDLER_HPP
#define API_API_HANDLER_HPP

#include <string>

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
enum ActionType { ACTION_GET = 1, ACTION_POST = 2 };

////////////////////////////////////////////////////////////////////////////////
class ApiHandler {
 public:
  virtual std::string process(int action, const std::string &uri,
                              const std::string &postBody = "") = 0;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_API_HANDLER_HPP
