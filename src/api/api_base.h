/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_BASE_H
#define API_BASE_H

#include "http/http.h"

namespace Ark {
namespace Client {
/**
 * Ark::Client::AbstractApi 
 **/
class ApiBase : public virtual HTTP
{
protected:
  ApiBase() = default;

public:
  void setHost(
    const char *const newHost,
    const int newPort
  ) {
    this->http->setHost(newHost, newPort);
  }
};
/**/
};
};

#endif
