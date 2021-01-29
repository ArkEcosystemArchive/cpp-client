/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "mocks/mock_http.hpp"

#include <memory>
#include <string>

#include "http/http_support.hpp"

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
// Mock Http Factory
std::unique_ptr<IHttp> getNewMockHttp() {
  return std::unique_ptr<IHttp>(new MockHttp());
}

}  // namespace Client
}  // namespace Ark
