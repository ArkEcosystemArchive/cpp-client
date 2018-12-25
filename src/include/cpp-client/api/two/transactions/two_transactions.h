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

#include "api/base.h"
#include "api/two/two_paths.h"

#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class Transactions : public API::Base
{
public:
  Transactions(HTTP& http) : API::Base(http) { }

  std::string getUnconfirmed(const char *const identifier, int limit = 2, int page = 1);
  std::string get(const char *const identifier, int limit = 5, int page = 1);
  std::string all(int limit = 5, int page = 1);
  std::string allUnconfirmed(int limit = 2, int page = 1);
  std::string types(int limit = 5, int page = 1);
  std::string search(const std::map<std::string, std::string>& body_parameters, int limit = 5, int page = 1);
};

};
};
};
};

#endif
