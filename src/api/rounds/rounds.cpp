/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/rounds/rounds.h"

namespace Ark {
namespace Client {
namespace api {

std::string Rounds::delegates(const char* roundId) {
  return http_->get(paths::Rounds::delegates(this->host_, roundId).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
