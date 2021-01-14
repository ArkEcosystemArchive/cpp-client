/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_TRANSACTIONS_HPP
#define API_TRANSACTIONS_HPP

#include <string>

#include "api/api_base.hpp"
#include "api/api_handler.hpp"
#include "api/paths.hpp"

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
class Transactions : public ApiBase {
 public:
  Transactions(ApiHandler &apiHandler) : ApiBase(apiHandler) {}

  std::string all(const std::string &query = DEFAULT_QUERY);
  std::string allUnconfirmed(const std::string &query = DEFAULT_QUERY);

  std::string get(const std::string &identifier);
  std::string getUnconfirmed(const std::string &identifier);

  std::string fees();
  std::string types();

  //////////////////////////////////////////////////////////////////////////////
  // Send a Json Transaction
  //
  // Transaction(s) must be a string in the format:
  // - "{\"transactions\":[{<transaction_1>},{<transaction_2>},...]}"
  //
  // ---
  std::string send(const std::string &jsonTransaction);
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_TRANSACTIONS_HPP
