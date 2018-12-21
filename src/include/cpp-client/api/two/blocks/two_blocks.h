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

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class Blocks : public API::Base
{
public:
  Blocks(HTTP& http) : API::Base(http) { }

  std::string get(const char *const blockId);
  std::string all(int limit = 5, int page = 1);
  std::string transactions(const char *const blockId);
  std::string search(std::pair<const char*, const char*> bodyParameters, int limit = 5, int page = 1);
};

};
};
};
};

#endif
