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

#include "api/api_base.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

  class IBlocks : public ApiBase
  {
  protected:
    IBlocks(IHTTP& http) : ApiBase(http) { }

  public:
    virtual std::string get(const char *const blockId) = 0;
    virtual std::string all(int limit = 5, int page = 1) = 0;
    virtual std::string transactions(const char *const blockId) = 0;
    virtual std::string search(std::pair<const char*, const char*> bodyParameters, int limit = 5, int page = 1) = 0;
  };

class Blocks : public IBlocks
{
public:
  Blocks(IHTTP& http) : IBlocks(http) { }

  std::string get(const char *const blockId) override;
  std::string all(int limit = 5, int page = 1) override;
  std::string transactions(const char *const blockId) override;
  std::string search(std::pair<const char*, const char*> bodyParameters, int limit = 5, int page = 1) override;
};

};
};
};
};

#endif
