/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_PEERS_H
#define TWO_PEERS_H

#include "api/api_base.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class Peers : public ApiBase
{
public:
  Peers() = default;

  std::string get(const char *const ip);
  std::string all(int limit = 5, int page = 1);
};

};
};
};
};

#endif
