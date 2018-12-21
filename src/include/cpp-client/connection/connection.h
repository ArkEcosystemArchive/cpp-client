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

#include "api/api.h"
#include "api/one/one_api.h"
#include "api/two/two_api.h"
#include "http/http.h"

namespace Ark {
namespace Client {
/**
 * Ark::Client::Connection<API_INTERFACE>
 **/
template <typename API_INTERFACE>
class Connection {
public:
  API_INTERFACE api;

  Connection() = default;
  Connection(const API_INTERFACE& other) : api(other) {}

  Connection(
    const char *const newHost,
    int newPort
  ) {
    this->api.setHost(newHost, newPort);
  }

  const char* host() const noexcept { return api.host(); };
  int port() const noexcept { return api.port(); };

};
/**/
}
}

#endif
