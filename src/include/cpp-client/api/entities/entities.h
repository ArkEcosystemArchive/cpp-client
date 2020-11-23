/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ENTITIES_H
#define ENTITIES_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {

class IEntities : public Base {
 public:
  virtual ~IEntities() {}

  virtual std::string get(const char* const entityId) = 0;
  virtual std::string all(const char* const query) = 0;

 protected:
  IEntities(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Entities : public IEntities {
 public:
  Entities(Host& host, IHTTP& http) : IEntities(host, http) {}

  std::string get(const char* const entityId) override;
  std::string all(const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
