/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef WALLETS_H
#define WALLETS_H

#include "api/base.h"
#include "api/paths.h"

#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace API {
/**/
class IWallets : public API::Base {
protected:
  IWallets(Host &host, IHTTP &http) : API::Base(host, http) {}

public:
  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
  virtual std::string top(int limit = 5, int page = 1) = 0;
  virtual std::string transactions(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string transactionsReceived(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string transactionsSent(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string votes(const char *const identifier, int limit = 5, int page = 1) = 0;
  virtual std::string search(const std::map<std::string, std::string> &bodyParameters, int limit = 5, int page = 1) = 0;
};
/**/
class Wallets : public IWallets {
public:
  Wallets(Host &host, IHTTP &http) : IWallets(host, http) {}

  std::string get(const char *const identifier) override;
  std::string all(int limit = 5, int page = 1) override;
  std::string top(int limit = 5, int page = 1) override;
  std::string transactions(const char *const identifier, int limit = 5, int page = 1) override;
  std::string transactionsReceived(const char *const identifier, int limit = 5, int page = 1) override;
  std::string transactionsSent(const char *const identifier, int limit = 5, int page = 1) override;
  std::string votes(const char *const identifier, int limit = 5, int page = 1) override;
  std::string search(const std::map<std::string, std::string> &bodyParameters, int limit = 5, int page = 1) override;
};
/**/
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
