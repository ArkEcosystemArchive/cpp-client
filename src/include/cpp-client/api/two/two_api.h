/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef TWO_API_H
#define TWO_API_H

#include "api/api.h"
#include "api/two/blocks/two_blocks.h"
#include "api/two/delegates/two_delegates.h"
#include "api/two/node/two_node.h"
#include "api/two/peers/two_peers.h"
#include "api/two/transactions/two_transactions.h"
#include "api/two/votes/two_votes.h"
#include "api/two/wallets/two_wallets.h"

namespace Ark {
namespace Client {
namespace API {
/***/
class Two : public AbstractApi
{
public:
  Ark::Client::API::TWO::Blocks blocks;
  Ark::Client::API::TWO::Delegates delegates;
  Ark::Client::API::TWO::Node node;
  Ark::Client::API::TWO::Peers peers;
  Ark::Client::API::TWO::Transactions transactions;
  Ark::Client::API::TWO::Votes votes;
  Ark::Client::API::TWO::Wallets wallets;

  Two() : AbstractApi(2), blocks(http_), delegates(http_), node(http_), peers(http_), transactions(http_), votes(http_), wallets(http_) { }

  void setHost(const char *const newHost, int newPort) {
    http_.setHostHTTP(newHost, newPort);
  }
};
/***/
}
}
}

#endif
