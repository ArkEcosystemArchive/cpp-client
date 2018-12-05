/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_TRANSACTIONS_H
#define TWO_TRANSACTIONS_H

#include "api/api_base.h"
#include "api/two/two_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class Transactions : public ApiBase
{
public:
  Transactions(HTTP& http) : ApiBase(http) { }

  std::string getUnconfirmed(const char *const identifier, int limit = 2, int page = 1);
  std::string get(const char *const identifier, int limit = 5, int page = 1);
  std::string all(int limit = 5, int page = 1);
  std::string allUnconfirmed(int limit = 2, int page = 1);
  std::string types(int limit = 5, int page = 1);
};

};
};
};
};

#endif
