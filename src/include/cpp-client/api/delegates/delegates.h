/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef DELEGATES_H
#define DELEGATES_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace API {
/**/
class IDelegates : public API::Base {
protected:
  IDelegates(Host &host, IHTTP &http) : API::Base(host, http) {}

public:
  virtual ~IDelegates() {}

  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
  virtual std::string blocks(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string voters(const char *const identifier, int limit = 5, int page = 1) = 0;
};
/**/
class Delegates : public IDelegates {
public:
  Delegates(Host &host, IHTTP &http) : IDelegates(host, http) {}

  std::string get(const char *const identifier) override;
  std::string all(int limit = 5, int page = 1) override;
  std::string blocks(const char *const identifier, int limit = 5, int page = 1) override;
  std::string voters(const char *const identifier, int limit = 5, int page = 1) override;
};
/**/
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
