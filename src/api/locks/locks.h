/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef LOCKS_H
#define LOCKS_H

#include <map>
#include <string>

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class ILocks : public Base {
 public:
  virtual ~ILocks() {}
  virtual std::string get(const char* const lockId) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) = 0;
  virtual std::string unlocked(std::string& jsonIds, const char* const query) = 0;

 protected:
  ILocks(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Locks : public ILocks { 
 public:
  Locks(Host& host, IHTTP& http) : ILocks(host, http) {}

  std::string get(const char* const lockId) override;
  std::string all(const char* const query) override;
  std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) override;
  std::string unlocked(std::string& jsonIds, const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
