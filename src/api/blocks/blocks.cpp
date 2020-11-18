/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/blocks/blocks.h"

namespace Ark {
namespace Client {
namespace api {

std::string Blocks::get(const char* identifier) {
  return http_->get(paths::Blocks::get(this->host_, identifier).c_str());
}

/**/

std::string Blocks::first() {
  return http_->get(paths::Blocks::first(this->host_).c_str());
}

/**/

std::string Blocks::last() {
  return http_->get(paths::Blocks::last(this->host_).c_str());
}

/**/

std::string Blocks::all(const char* const query) {
  return http_->get(paths::Blocks::all(this->host_, query).c_str());
}

/**/

std::string Blocks::transactions(const char* identifier) {
  return http_->get(paths::Blocks::transactions(this->host_, identifier).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
