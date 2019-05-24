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

#include <cstdio>
#include <cstring>
#include <string>

namespace Ark {
namespace Client {
/***
 * Ark::Client::Host
 **/
class Host {
protected:
  char ip_[17];
  int port_;

 public:
  Host();
  Host(const char* const newIP, int newPort);

  bool set(const char* const newIP, int newPort);

  std::string ip() const noexcept;
  int port() const noexcept;

  std::string toString();
};
/**/
};  // namespace Client
};  // namespace Ark

#endif
