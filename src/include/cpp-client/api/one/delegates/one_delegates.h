/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_DELEGATES_H
#define ONE_DELEGATES_H

#include "api/api_base.h"
#include "api/one/one_paths.h"

namespace Ark {
namespace Client {
namespace API {
namespace ONE {

class Delegates : public ApiBase
{
public:
  Delegates() = default;

  std::string get(const char *const parameter);
  std::string all(int limit = 5);
  std::string count();
  std::string search(const char *const username);
  std::string fee();
  std::string forgedByAccount(const char *const generatorPublicKey);
  std::string nextForgers();
  std::string voters(const char *const publicKey);
};

};
};
};
};

#endif
