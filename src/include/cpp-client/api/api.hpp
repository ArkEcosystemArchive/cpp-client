/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_HPP
#define API_HPP

#include "api/api_handler.hpp"

#include "api/blockchain/blockchain.hpp"
#include "api/blocks/blocks.hpp"
#include "api/delegates/delegates.hpp"
#include "api/entities/entities.hpp"
#include "api/locks/locks.hpp"
#include "api/node/node.hpp"
#include "api/peers/peers.hpp"
#include "api/rounds/rounds.hpp"
#include "api/transactions/transactions.hpp"
#include "api/votes/votes.hpp"
#include "api/wallets/wallets.hpp"

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
class Api {
 public:
  api::Blockchain blockchain;
  api::Blocks blocks;
  api::Delegates delegates;
  api::Entities entities;
  api::Locks locks;
  api::Node node;
  api::Peers peers;
  api::Rounds rounds;
  api::Transactions transactions;
  api::Votes votes;
  api::Wallets wallets;

  //////////////////////////////////////////////////////////////////////////////
  Api(api::ApiHandler &apiHandler)
      : blockchain(apiHandler),
        blocks(apiHandler),
        delegates(apiHandler),
        entities(apiHandler),
        locks(apiHandler),
        node(apiHandler),
        peers(apiHandler),
        rounds(apiHandler),
        transactions(apiHandler),
        votes(apiHandler),
        wallets(apiHandler) {}
};

}  // namespace Client
}  // namespace Ark

#endif  // API_HPP
