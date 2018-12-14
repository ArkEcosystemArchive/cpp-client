/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef PEERS_H
#define PEERS_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace API {

class Peers : public API::Base
{
  public:
    Peers(HTTP& http) : API::Base(http) { }

    std::string get(const char *const ip);
    std::string all(int limit = 5, int page = 1);
};

};
};
};

#endif
