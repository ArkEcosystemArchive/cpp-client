/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef CONNECTION_H
#define CONNECTION_H

#include "api/abstract.h"
#include "api/api.h"
#include "host/host.h"
#include "http/http.h"

namespace Ark {
namespace Client {
/**
 * Ark::Client::Connection<TAPI>
 **/
template <typename TAPI>
class Connection {
 public:
  TAPI api;
  Host host;

  Connection() = default;
  Connection(const TAPI& other) : api(other) {}

  Connection(const char* const newIP, int newPort) {
    this->host.set(newIP, newPort);
    this->api.setHost(newIP, newPort);
  };
};
/**/
}  // namespace Client
}  // namespace Ark

#endif
