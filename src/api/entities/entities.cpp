/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/entities/entities.h"

namespace Ark {
namespace Client {
namespace api {

std::string Entities::get(const char* entityId) {
  return http_->get(paths::Entities::get(this->host_, entityId).c_str());
}

/**/

std::string Entities::all(const char* const query) {
  return http_->get(paths::Entities::all(this->host_, query).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
