/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_NODE_PATHS_HPP
#define API_NODE_PATHS_HPP

namespace Ark {
namespace Client {
namespace api {

////////////////////////////////////////////////////////////////////////////////
#define PATHS_NODE "/api/node"
#define PATHS_NODE_CONFIGURATION PATHS_NODE "/configuration"
#define PATHS_NODE_CRYPTO PATHS_NODE_CONFIGURATION "/crypto"
#define PATHS_NODE_FEES PATHS_NODE "/fees"
#define PATHS_NODE_STATUS PATHS_NODE "/status"
#define PATHS_NODE_SYNCING PATHS_NODE "/syncing"

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif  // API_NODE_PATHS_HPP
