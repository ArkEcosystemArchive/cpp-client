/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/businesses/businesses.h"

namespace Ark {
namespace Client {
namespace api {

std::string Businesses::get(const char* businessId) {
  return http_->get(paths::Businesses::get(this->host_, businessId).c_str());
}

/**/

std::string Businesses::all(const char* const query) {
  return http_->get(paths::Businesses::all(this->host_, query).c_str());
}

/**/

std::string Businesses::bridgechains(const char* businessId) {
  return http_->get(paths::Businesses::bridgechains(this->host_, businessId).c_str());
}

/**/

std::string Businesses::search(
    const std::map<std::string, std::string> &bodyParameters,
    const char* const query) {
  const auto searchPathPair = paths::Businesses::search(this->host_,
                                                     bodyParameters,
                                                     query);
  return http_->post(searchPathPair.first.c_str(),
                     searchPathPair.second.c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
