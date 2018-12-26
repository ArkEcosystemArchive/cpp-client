/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_WALLETS_H
#define TWO_WALLETS_H

#include "api/base.h"
#include "api/two/two_paths.h"

#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace API {
namespace TWO {

class IWallets : public API::Base
{
protected:
  IWallets(IHTTP& http) : API::Base(http) { }

public:
  virtual ~IWallets() { }

  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
  virtual std::string top(int limit = 5, int page = 1) = 0;
  virtual std::string transactions(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string transactionsReceived(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string transactionsSent(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string votes(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string search(const std::map<std::string, std::string>& bodyParameters, int limit = 5, int page = 1) = 0;
};

class Wallets : public IWallets
{
public:
  Wallets(IHTTP& http) : IWallets(http) { }

  std::string get(const char *const identifier) override;
  std::string all(int limit = 5, int page = 1) override;
  std::string top(int limit = 5, int page = 1) override;
  std::string transactions(const char *const identifier, int limit = 5, int page = 1) override;
  std::string transactionsReceived(const char *const identifier, int limit = 5, int page = 1) override;
  std::string transactionsSent(const char *const identifier, int limit = 5, int page = 1) override;
  std::string votes(const char *const identifier, int limit = 5, int page = 1) override;
  std::string search(const std::map<std::string, std::string>& bodyParameters, int limit = 5, int page = 1) override;
};

};
};
};
};

#endif
