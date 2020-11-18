/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/locks/locks.h"

namespace Ark {
namespace Client {
namespace api {

std::string Locks::get(const char* lockId) {
  return http_->get(paths::Locks::get(this->host_, lockId).c_str());
}

/**/

std::string Locks::all(const char* const query) {
  return http_->get(paths::Locks::all(this->host_, query).c_str());
}

/**/

std::string Locks::unlocked(std::string& jsonIds, const char* const query) {
  const auto pathPair = paths::Locks::unlocked(this->host_, jsonIds, query);
  return http_->post(pathPair.first.c_str(), pathPair.second.c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
