/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_H
#define API_H

#include "api/abstract.h"
#include "api/api.h"
#include "api/blockchain/blockchain.hpp"
#include "api/blocks/blocks.h"
#include "api/businesses/businesses.h"
#include "api/bridgechains/bridgechains.h"
#include "api/delegates/delegates.h"
#include "api/node/node.h"
#include "api/peers/peers.h"
#include "api/rounds/rounds.h"
#include "api/transactions/transactions.h"
#include "api/votes/votes.h"
#include "api/wallets/wallets.h"

namespace Ark {
namespace Client {

class Api : public api::Abstract {
 public:
  api::Blockchain blockchain;
  api::Blocks blocks;
  api::Businesses businesses;
  api::Bridgechains bridgechains;
  api::Delegates delegates;
  api::Node node;
  api::Peers peers;
  api::Rounds rounds;
  api::Transactions transactions;
  api::Votes votes;
  api::Wallets wallets;

  Api() : Abstract(),
          blockchain(host_, *http_),
          blocks(host_, *http_),
          businesses(host_, *http_),
          bridgechains(host_, *http_),
          delegates(host_, *http_),
          node(host_, *http_),
          peers(host_, *http_),
          rounds(host_, *http_),
          transactions(host_, *http_),
          votes(host_, *http_),
          wallets(host_, *http_) {}
};

}  // namespace Client
}  // namespace Ark

#endif
