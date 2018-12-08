/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_H
#define API_H

#include "http/http.h"

namespace Ark {
namespace Client {

/**
 * Ark::Client::AbstractApi 
 **/
class AbstractApi {
protected:
  HTTP http_;
  int version_;

  AbstractApi(int version) : version_(version) { }

public:
  int version() const noexcept { return this->version_; }
  const char* host() const noexcept { return http_.host(); };
  int port() const noexcept { return http_.port(); };

  void setHost(const char *const newHost, int newPort) {
    http_.setHostHTTP(newHost, newPort, version_);
  }
};
/**/
};
};

#endif
