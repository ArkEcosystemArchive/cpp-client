/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef DELEGATES_H
#define DELEGATES_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace API {

class Delegates : public API::Base
{
  public:
    Delegates(HTTP& http) : API::Base(http) { }

    std::string get(const char *const identifier);
    std::string all(int limit = 5, int page = 1);
    std::string blocks(const char *const identifier, int limit = 5, int page = 1);
    std::string voters(const char *const identifier, int limit = 5, int page = 1);
};

};
};
};

#endif
