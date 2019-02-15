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
/**/
class IPeers : public API::Base {
 protected:
  IPeers(Host& host, IHTTP& http) : API::Base(host, http) {}

 public:
  virtual ~IPeers() {}

  virtual std::string get(const char* const ip) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
};
/**/
class Peers : public IPeers {
 public:
  Peers(Host& host, IHTTP& http) : IPeers(host, http) {}

  std::string get(const char* const ip) override;
  std::string all(int limit = 5, int page = 1) override;
};
/**/
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
