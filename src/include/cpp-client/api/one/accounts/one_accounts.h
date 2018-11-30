/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_ACCOUNTS_H
#define ONE_ACCOUNTS_H

#include "http/http.h"
#include "api/api_base.h"
#include "api/one/one_paths.h"
#include <string>

namespace Ark {
namespace Client {
namespace API {
namespace ONE {

class Accounts : public Ark::Client::ApiBase
{
public:
  Accounts() = default;
  std::string balance(const char *const arkAddress);
  std::string publickey(const char *const arkAddress);
  std::string delegatesFee(const char *const arkAddress);
  std::string delegates(const char *const arkAddress);
  std::string get(const char *const arkAddress);
};

};
};
};
};

#endif
