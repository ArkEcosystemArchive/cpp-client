/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/delegates/delegates.h"

namespace Ark {
namespace Client {
namespace api {

std::string Delegates::get(const char* identifier) {
  return http_->get(paths::Delegates::get(this->host_, identifier).c_str());
}

/**/

std::string Delegates::all(const char* const query) {
  return http_->get(paths::Delegates::all(this->host_, query).c_str());
}

/**/

std::string Delegates::blocks(const char *const identifier,
                              const char* const query) {
  return http_->get(paths::Delegates::blocks(this->host_,
                                             identifier,
                                             query).c_str());
}

/**/

std::string Delegates::voters(const char *const identifier,
                              const char* const query) {
  return http_->get(paths::Delegates::voters(this->host_,
                                             identifier,
                                             query).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
