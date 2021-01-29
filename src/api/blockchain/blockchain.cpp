/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "api/blockchain/blockchain.hpp"

#include <string>

#include "api/api_handler.hpp"

#include "api/blockchain/blockchain_paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
std::string Blockchain::get() {
  const auto response =
      this->apiHandler_->process(ACTION_GET, PATHS_BLOCKCHAIN);
  return response;
}

}  // namespace api
}  // namespace Client
}  // namespace Ark
