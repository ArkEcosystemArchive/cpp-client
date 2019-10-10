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

#include <map>
#include <string>

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class IBlocks : public Base {
 public:
  virtual ~IBlocks() {}
  virtual std::string get(const char* const blockId) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string transactions(const char* const blockId) = 0;
  virtual std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) = 0;

 protected:
  IBlocks(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Blocks : public IBlocks { 
 public:
  Blocks(Host& host, IHTTP& http) : IBlocks(host, http) {}

  std::string get(const char* const blockId) override;
  std::string all(const char* const query) override;
  std::string transactions(const char* const blockId) override;
  std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
