/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_BLOCKS_H
#define TWO_BLOCKS_H

#include "api/base.h"
#include "api/two/two_paths.h"

#include <string>
#include <map>

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

  class IBlocks : public API::Base
  {
  protected:
    IBlocks(IHTTP& http) : API::Base(http) { }

  public:
    virtual ~IBlocks() { }

    virtual std::string get(const char *const blockId) = 0;
    virtual std::string all(int limit = 5, int page = 1) = 0;
    virtual std::string transactions(const char *const blockId) = 0;
    virtual std::string search(const std::map<std::string, std::string>& bodyParameters, int limit = 5, int page = 1) = 0;
  };

class Blocks : public IBlocks
{
public:
  Blocks(IHTTP& http) : IBlocks(http) { }

  std::string get(const char *const blockId);
  std::string all(int limit = 5, int page = 1);
  std::string transactions(const char *const blockId);
  std::string search(const std::map<std::string, std::string>& bodyParameters, int limit = 5, int page = 1);
};

};
};
};
};

#endif
