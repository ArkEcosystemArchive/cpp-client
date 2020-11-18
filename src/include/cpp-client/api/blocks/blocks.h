/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef BLOCKS_H
#define BLOCKS_H

#include <string>

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class IBlocks : public Base {
 public:
  virtual ~IBlocks() {}
  virtual std::string get(const char* const identifier) = 0;
  virtual std::string first() = 0;
  virtual std::string last() = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string transactions(const char* const identifier) = 0;

 protected:
  IBlocks(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Blocks : public IBlocks { 
 public:
  Blocks(Host& host, IHTTP& http) : IBlocks(host, http) {}

  std::string get(const char* const identifier) override;
  std::string first() override;
  std::string last() override;
  std::string all(const char* const query) override;
  std::string transactions(const char* const identifier) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
