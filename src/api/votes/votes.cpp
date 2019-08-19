/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/votes/votes.h"

namespace Ark {
namespace Client {
namespace api {

std::string Votes::get(const char* identifier) {
  return http_->get(paths::Votes::get(this->host_, identifier).c_str());
}

/**/

std::string Votes::all(const char* const query) {
  return http_->get(paths::Votes::all(this->host_, query).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
