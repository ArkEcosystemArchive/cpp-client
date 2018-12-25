/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ABSTRACT_H
#define ABSTRACT_H

#include "http/http.h"

namespace Ark {
namespace Client {
namespace API {
/**
 * Ark::Client::API::Abstract 
 **/
class Abstract {
  protected:
    HTTP http_;
    int version_;

    Abstract(int version) : version_(version) { }

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
};

#endif
