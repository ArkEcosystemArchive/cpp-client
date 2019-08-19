/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "api/base.h"
#include "api/paths.h"

#include <string>

namespace Ark {
namespace Client {
namespace api {

class IBlockchain : public api::Base {
 public:
  virtual ~IBlockchain() {}

  virtual std::string get() = 0;

protected:
  IBlockchain(Host& host, IHTTP& http) : api::Base(host, http) {}
};

/**/

class Blockchain : public IBlockchain {
 public:
  Blockchain(Host& host, IHTTP& http) : IBlockchain(host, http) {}

  std::string get() override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
