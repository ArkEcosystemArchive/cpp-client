/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef NODE_H
#define NODE_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace API {

class Node : public API::Base
{
  public:
    Node(IHTTP& http) : API::Base(http) { }

    std::string configuration();
    std::string status();
    std::string syncing();
};

};
};
};

#endif
