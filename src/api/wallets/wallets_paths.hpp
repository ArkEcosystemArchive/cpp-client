/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_WALLETS_PATHS_HPP
#define API_WALLETS_PATHS_HPP

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
#define PATHS_WALLETS "/api/wallets"
#define PATHS_WALLETS_LOCKS_ENDPOINT "/locks"
#define PATHS_WALLETS_TOP PATHS_WALLETS "/top"
#define PATHS_WALLETS_VOTES_ENDPOINT "/votes"
#define PATHS_WALLETS_TRANSACTIONS_ENDPOINT "/transactions"
#define PATHS_WALLETS_TRANSACTIONS_SENT_ENDPOINT \
  PATHS_WALLETS_TRANSACTIONS_ENDPOINT "/sent"
#define PATHS_WALLETS_TRANSACTIONS_RECEIVED_ENDPOINT \
  PATHS_WALLETS_TRANSACTIONS_ENDPOINT "/received"

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_WALLETS_PATHS_HPP
