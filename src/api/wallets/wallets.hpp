/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_WALLETS_HPP
#define API_WALLETS_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"
#include "api/paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Wallets : public ApiBase {
 public:
  Wallets(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string all(const std::string &query = DEFAULT_QUERY);
  std::string get(const std::string &identifier);

  std::string locks(const std::string &identifier);
  std::string top(const std::string &query = DEFAULT_QUERY);
  std::string votes(const std::string &identifier,
                    const std::string &query = DEFAULT_QUERY);

  std::string transactions(const std::string &identifier,
                           const std::string &query = DEFAULT_QUERY);
  std::string transactionsSent(const std::string &identifier,
                               const std::string &query = DEFAULT_QUERY);
  std::string transactionsReceived(const std::string &identifier,
                                   const std::string &query = DEFAULT_QUERY);
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_WALLETS_HPP
