/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_DELEGATES_H
#define TWO_DELEGATES_H

#include "api/api_base.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class Delegates : public ApiBase
{
public:
  Delegates(HTTP& http) : ApiBase(http) { }

  std::string get(const char *const identifier);
  std::string all(int limit = 5, int page = 1);
  std::string blocks(const char *const identifier, int limit = 5, int page = 1);
  std::string voters(const char *const identifier, int limit = 5, int page = 1);
};

};
};
};
};

#endif
