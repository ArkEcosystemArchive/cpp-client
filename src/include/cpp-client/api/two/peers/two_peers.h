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

#include "api/base.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class IPeers : public API::Base
{
protected:
  IPeers(IHTTP& http) : API::Base(http) { }

public:
  virtual std::string get(const char *const ip) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
};

class Peers : public IPeers
{
public:
  Peers(IHTTP& http) : IPeers(http) { }

  std::string get(const char *const ip) override;
  std::string all(int limit = 5, int page = 1) override;
};

};
};
};
};

#endif
