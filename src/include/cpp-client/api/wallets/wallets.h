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
namespace api {  // NOLINT

class IWallets : public Base {
 public:
  virtual ~IWallets() {}

  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(const char* const query) = 0;
  virtual std::string top(const char* const query) = 0;
  virtual std::string transactions(const char *const identifier, const char* const query) = 0;
  virtual std::string transactionsReceived(const char *const identifier, const char* const query) = 0;
  virtual std::string transactionsSent(const char *const identifier, const char* const query) = 0;
  virtual std::string votes(const char *const identifier, const char* const query) = 0;
  virtual std::string search(const std::map<std::string, std::string> &bodyParameters, const char* const query) = 0;

 protected:
  IWallets(Host &host, IHTTP &http) : Base(host, http) {}
};

/**/

class Wallets : public IWallets {
 public:
  Wallets(Host &host, IHTTP &http) : IWallets(host, http) {}

  std::string get(const char *const identifier) override;
  std::string all(const char* const query) override;
  std::string top(const char* const query) override;
  std::string transactions(const char *const identifier, const char* const query) override;
  std::string transactionsReceived(const char *const identifier, const char* const query) override;
  std::string transactionsSent(const char *const identifier, const char* const query) override;
  std::string votes(const char *const identifier, const char* const query) override;
  std::string search(const std::map<std::string, std::string> &bodyParameters, const char* const query) override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
