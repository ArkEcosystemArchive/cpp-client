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

#include "host/host.h"
#include "http/http.h"

namespace Ark {
namespace Client {
namespace api {

class Abstract {
 public:
  void setHost(const char* newHost, int newPort) {
    this->host_.set(newHost, newPort);
  };

 protected:
  Host host_;
  std::unique_ptr<IHTTP> http_;

  Abstract() : http_(makeHTTP()) {}
  explicit Abstract(IHTTP* http) : http_(http) {}
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
