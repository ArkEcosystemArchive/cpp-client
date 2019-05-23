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

#include "api/base.h"
#include "api/paths.h"

#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace API {
/**/
class IBlocks : public API::Base {
protected:
  IBlocks(Host& host, IHTTP& http) : API::Base(host, http) {}

public:
  virtual ~IBlocks() {}
  virtual std::string get(const char* const blockId) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
  virtual std::string transactions(const char* const blockId) = 0;
  virtual std::string search(
      const std::map<std::string, std::string>& bodyParameters,
      int limit = 5,
      int page = 1) = 0;
};
/**/
class Blocks : public IBlocks {
public:
  Blocks(Host& host, IHTTP& http) : IBlocks(host, http) {}

  std::string get(const char* const blockId) override;
  std::string all(int limit = 5, int page = 1) override;
  std::string transactions(const char* const blockId) override;
  std::string search(
      const std::map<std::string, std::string>& bodyParameters,
      int limit = 5,
      int page = 1) override;
};
/**/
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
