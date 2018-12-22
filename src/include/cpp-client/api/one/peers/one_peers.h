/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_PEERS_H
#define ONE_PEERS_H

#include "api/api_base.h"
#include "api/one/one_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace ONE {

class Peers : public ApiBase
{
public:
  Peers(IHTTP& http) : ApiBase(http) { }

  std::string get(const char *const ip, const int port);
  std::string all(int limit = 5);
  std::string version();
};

};
};
};
};

#endif
