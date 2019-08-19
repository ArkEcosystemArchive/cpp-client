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
namespace api {

class IPeers : public Base {
 public:
  virtual ~IPeers() {}

  virtual std::string get(const char* const ip) = 0;
  virtual std::string all(const char* const query) = 0;

 protected:
  IPeers(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Peers : public IPeers {
 public:
  Peers(Host& host, IHTTP& http) : IPeers(host, http) {}

  std::string get(const char* const ip) override;
  std::string all(const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
