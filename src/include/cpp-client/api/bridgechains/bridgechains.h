/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef BRIDGECHAINS_H
#define BRIDGECHAINS_H

#include <map>
#include <string>

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class IBridgechains : public Base {
 public:
  virtual ~IBridgechains() {}
  virtual std::string get(const char* const bridgechainId) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) = 0;

 protected:
  IBridgechains(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Bridgechains : public IBridgechains { 
 public:
  bridgechains(Host& host, IHTTP& http) : IBridgechains(host, http) {}

  std::string get(const char* const bridgechainId) override;
  std::string all(const char* const query) override;
  std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
