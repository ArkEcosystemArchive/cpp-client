/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_TRANSACTIONS_H
#define ONE_TRANSACTIONS_H

#include "api/base.h"
#include "api/one/one_paths.h"
#include <string>

namespace Ark {
namespace Client {
namespace API {
namespace ONE {

class Transactions : public API::Base
{
public:
  Transactions(IHTTP& http) : ApiBase(http) { }

  std::string get(const char *const id);
  std::string all(int limit = 5, const char *const orderBy = "timestamp", bool isDescending = true);
  std::string getUnconfirmed(const char *const id);
  std::string allUnconfirmed();
};

};
};
};
};

#endif
