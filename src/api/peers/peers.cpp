/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/peers/peers.h"

namespace Ark {
namespace Client {
namespace api {

std::string Peers::get(const char* ip) {
  return http_->get(paths::Peers::get(this->host_, ip).c_str());
}

/**/

std::string Peers::all(const char* const query) {
  return http_->get(paths::Peers::all(this->host_, query).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
