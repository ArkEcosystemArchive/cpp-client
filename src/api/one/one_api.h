/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_API_H
#define ONE_API_H

#include "api/api.h"
#include "api/one/accounts/one_accounts.h"
#include "api/one/blocks/one_blocks.h"
#include "api/one/delegates/one_delegates.h"
#include "api/one/loader/one_loader.h"
#include "api/one/peers/one_peers.h"
#include "api/one/signatures/one_signatures.h"
#include "api/one/transactions/one_transactions.h"

namespace Ark {
namespace Client {
namespace API {
/**/
class One : public AbstractApi
{
    public:
        Ark::Client::API::ONE::Accounts accounts;
        Ark::Client::API::ONE::Blocks blocks;
        Ark::Client::API::ONE::Delegates delegates;
        Ark::Client::API::ONE::Loader loader;
        Ark::Client::API::ONE::Peers peers;
        Ark::Client::API::ONE::Signatures signatures;
        Ark::Client::API::ONE::Transactions transactions;
        
        One() : AbstractApi(1) { }

        void setHost(const char *const newHost, const int newPort)
        {
            this->accounts.setHost(newHost, newPort);
            this->blocks.setHost(newHost, newPort);
            this->delegates.setHost(newHost, newPort);
            this->loader.setHost(newHost, newPort);
            this->peers.setHost(newHost, newPort);
            this->signatures.setHost(newHost, newPort);
            this->transactions.setHost(newHost, newPort);
        }
};
/**/
};
};
};

#endif
