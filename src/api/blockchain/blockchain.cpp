/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/blockchain/blockchain.hpp"

namespace Ark {
namespace Client {
namespace api {

std::string Blockchain::get() {
  return http_->get(paths::Blockchain::get(this->host_).c_str());
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
