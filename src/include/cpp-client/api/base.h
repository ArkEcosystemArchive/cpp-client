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

#include "http/http.h"

namespace Ark {
namespace Client {
namespace API {
/**
 * Ark::Client::API::Base 
 **/
class Base {
protected:
  IHTTP* http_;

  template <typename HTTPType>
  explicit Base(HTTPType& http) : http_(static_cast<IHTTP*>(&http)) { }
};
/**/
};
};
};

#endif
