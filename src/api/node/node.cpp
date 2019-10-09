/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/node/node.h"

namespace Ark {
namespace Client {
namespace api {

std::string Node::configuration() {
  return http_->get(paths::Node::configuration(this->host_).c_str());
}

/**/

std::string Node::crypto() {
  return http_->get(paths::Node::crypto(this->host_).c_str());
}

/**/

std::string Node::fees(const char* const query) {
  return http_->get(paths::Node::fees(this->host_, query).c_str());
}

/**/

std::string Node::status() {
  return http_->get(paths::Node::status(this->host_).c_str());
}

/**/

std::string Node::syncing() {
  return http_->get(paths::Node::syncing(this->host_).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
