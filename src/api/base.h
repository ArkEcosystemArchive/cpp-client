/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef BASE_H
#define BASE_H

#include "host/host.h"
#include "http/http.h"

namespace Ark {
namespace Client {
namespace api {

class Base {
 protected:
  Host& host_;
  IHTTP* http_;

  template <typename HTTPType>
  explicit Base(Host& host, HTTPType& http)
      : host_(host), http_(static_cast<IHTTP*>(&http)) {}
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
