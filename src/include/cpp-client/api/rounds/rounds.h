/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ROUNDS_H
#define ROUNDS_H

#include <string>

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class IRounds : public Base {
 public:
  virtual ~IRounds() {}
  virtual std::string delegates(const char* const roundId) = 0;

 protected:
  IRounds(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Rounds : public IRounds { 
 public:
  Rounds(Host& host, IHTTP& http) : IRounds(host, http) {}

  std::string delegates(const char* const roundId) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
