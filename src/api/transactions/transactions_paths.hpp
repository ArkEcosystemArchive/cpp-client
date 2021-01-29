/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_TRANSACTIONS_PATHS_HPP
#define API_TRANSACTIONS_PATHS_HPP

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
#define PATHS_TRANSACTIONS "/api/transactions"
#define PATHS_TRANSACTIONS_UNCONFIRMED PATHS_TRANSACTIONS "/unconfirmed"
#define PATHS_TRANSACTIONS_FEES PATHS_TRANSACTIONS "/fees"
#define PATHS_TRANSACTIONS_TYPES PATHS_TRANSACTIONS "/types"

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_TRANSACTIONS_PATHS_HPP
