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

#include "api/api.h"
#include "api/abstract.h"
#include "api/blocks/blocks.h"
#include "api/delegates/delegates.h"
#include "api/node/node.h"
#include "api/peers/peers.h"
#include "api/transactions/transactions.h"
#include "api/votes/votes.h"
#include "api/wallets/wallets.h"

namespace Ark {
namespace Client {
/***/
class Api : public API::Abstract
{
  public:
    API::Blocks blocks;
    API::Delegates delegates;
    API::Node node;
    API::Peers peers;
    API::Transactions transactions;
    API::Votes votes;
    API::Wallets wallets;

    Api() :
        API::Abstract(2),
        blocks(http_),
        delegates(http_),
        node(http_),
        peers(http_),
        transactions(http_),
        votes(http_),
        wallets(http_) {}
};
/***/
}
}

#endif