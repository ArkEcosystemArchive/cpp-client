/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HOST_H
#define HOST_H

#include <string>

namespace Ark {
namespace Client {

namespace {
constexpr const size_t IP_MAX_STRING_LEN = 17U;
constexpr const size_t PORT_MAX_STRING_LEN = 5U;
}  // namespace

class Host {
 public:
  Host() = default;
  Host(const char* ip, int port);

  bool set(const char* ip, int port);

  std::string ip() const noexcept;
  int port() const noexcept;

  std::string toString();

 protected:
  std::string ip_;
  int port_ = -1;
};

}  // namespace Client
}  // namespace Ark

#endif
