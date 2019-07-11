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
namespace API {
/**/
class IBlockchain : public API::Base {
protected:
  IBlockchain(Host& host, IHTTP& http) : API::Base(host, http) {}

public:
  virtual ~IBlockchain() {}
  virtual std::string get() = 0;
};
/**/
class Blockchain : public IBlockchain {
public:
  Blockchain(Host& host, IHTTP& http) : IBlockchain(host, http) {}

  std::string get() override;
};
/**/
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
