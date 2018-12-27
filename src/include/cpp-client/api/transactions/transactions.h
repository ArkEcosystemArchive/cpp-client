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
namespace API {

class ITransactions : public API::Base
{
protected:
  ITransactions(IHTTP& http) : API::Base(http) { }

public:
  virtual ~ITransactions() { }

  virtual std::string getUnconfirmed(const char *const identifier) = 0;
  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
  virtual std::string allUnconfirmed(int limit = 2, int page = 1) = 0;
  virtual std::string types() = 0;
  virtual std::string search(const std::map<std::string, std::string>& body_parameters, int limit = 5, int page = 1) = 0;
};

class Transactions : public ITransactions
{
  public:
    Transactions(IHTTP& http) : ITransactions(http) { }

    std::string getUnconfirmed(const char *const identifier) override;
    std::string get(const char *const identifier) override;
    std::string all(int limit = 5, int page = 1) override;
    std::string allUnconfirmed(int limit = 2, int page = 1) override;
    std::string types() override;
    std::string search(const std::map<std::string, std::string>& body_parameters, int limit = 5, int page = 1) override;
};

};
};
};

#endif
