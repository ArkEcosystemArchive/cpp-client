/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_BLOCKCHAIN_PATHS_HPP
#define API_BLOCKCHAIN_PATHS_HPP

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
#define PATHS_BLOCKS "/api/blocks"
#define PATHS_BLOCKS_FIRST PATHS_BLOCKS "/first"
#define PATHS_BLOCKS_LAST PATHS_BLOCKS "/last"
#define PATHS_BLOCKS_TRANSACTIONS_ENDPOINT "/transactions"

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_BLOCKCHAIN_PATHS_HPP
