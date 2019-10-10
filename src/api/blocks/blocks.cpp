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

std::string Blocks::get(const char* blockId) {
  return http_->get(paths::Blocks::get(this->host_, blockId).c_str());
}

/**/

std::string Blocks::all(const char* const query) {
  return http_->get(paths::Blocks::all(this->host_, query).c_str());
}

/**/

std::string Blocks::transactions(const char* blockId) {
  return http_->get(paths::Blocks::transactions(this->host_, blockId).c_str());
}

/**/

std::string Blocks::search(
    const std::map<std::string, std::string> &bodyParameters,
    const char* const query) {
  const auto searchPathPair = paths::Blocks::search(this->host_,
                                                     bodyParameters,
                                                     query);
  return http_->post(searchPathPair.first.c_str(),
                     searchPathPair.second.c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
