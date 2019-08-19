/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "host/host.h"

#include <cstdio>
#include <string>

namespace Ark {
namespace Client {

Host::Host(const char* ip, int port) : ip_(ip), port_(port) {}

/**/

bool Host::set(const char* ip, int port) {
  this->ip_.reserve(IP_MAX_STRING_LEN);
  this->ip_ += ip;
  this->port_ = port;
  return this->port_ == port && this->ip_ == ip;
}

/**/

std::string Host::ip() const noexcept { return this->ip_; };

/**/

int Host::port() const noexcept { return this->port_; };

/**/

std::string Host::toString() {
  std::string out;
  out.reserve(IP_MAX_STRING_LEN + PORT_MAX_STRING_LEN);
  out += (this->ip_);
  out += ":";
  snprintf(&out[out.length()], PORT_MAX_STRING_LEN, "%d", this->port_);
  return out;
}

}  // namespace Client
}  // namespace Ark
