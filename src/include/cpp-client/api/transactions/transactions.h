/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "api/base.h"
#include "api/paths.h"

#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace api {  // NOLINT

class ITransactions : public Base {
 public:
  virtual ~ITransactions() {}

  virtual std::string getUnconfirmed(const char* const identifier) = 0;
  virtual std::string get(const char* const identifier) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string allUnconfirmed(const char* const query) = 0;
  virtual std::string types() = 0;
  virtual std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) = 0;
  virtual std::string send(std::string& jsonTransaction) = 0;

 protected:
  ITransactions(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Transactions : public ITransactions {
 public:
  Transactions(Host& host, IHTTP& http) : ITransactions(host, http) {}

  std::string getUnconfirmed(const char* const identifier) override;
  std::string get(const char* const identifier) override;
  std::string all(const char* const query) override;
  std::string allUnconfirmed(const char* const query) override;
  std::string types() override;
  std::string search(const std::map<std::string, std::string>& bodyParameters, const char* const query) override;
  std::string send(std::string& jsonTransaction) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
