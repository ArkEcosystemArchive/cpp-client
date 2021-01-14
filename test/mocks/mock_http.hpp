/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef __MOCK_HTTP_HPP__
#define __MOCK_HTTP_HPP__

#include <memory>
#include <string>

#include "http/http_support.hpp"

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
class MockHttp : public AbstractHttp {
  //////////////////////////////////////////////////////////////////////////////
  std::string get(const std::string& request) override { return request; }

  //////////////////////////////////////////////////////////////////////////////
  std::string post(const std::string& request,
                   const std::string& body) override {
    return std::string("url: ")
        .append(request)
        .append("\nbody: ")
        .append(body);
  }

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  std::string get(const char* request) override { return this->get(request); }
  std::string post(const char* request, const char* body) override {
    return this->post(request, body);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Mock Http Factory
std::unique_ptr<IHttp> getNewMockHttp();

}  // namespace Client
}  // namespace Ark

#endif  // __MOCK_HTTP_HPP__
