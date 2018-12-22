/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_PATHS_H
#define ONE_PATHS_H

namespace Ark {
namespace Client {
namespace API {
namespace ONE {
namespace Paths {

namespace Accounts
{
    const auto base = "/api/accounts";
    const auto balance = "/api/accounts/getBalance";
    const auto publicKey = "/api/accounts/getPublicKey";
    const auto delegates = "/api/accounts/delegates";
    const auto delegatesFee = "/api/accounts/delegates/fee";
}
/***/
namespace Blocks
{
    const auto base = "/api/blocks";
    const auto epoch = "/api/blocks/getEpoch";
    const auto fee = "/api/blocks/getFee";
    const auto fees = "/api/blocks/getFees";
    const auto get = "/api/blocks/get";
    const auto height = "/api/blocks/getHeight";
    const auto nethash = "/api/blocks/getNethash";
    const auto milestone = "/api/blocks/getMilestone";
    const auto reward = "/api/blocks/getReward";
    const auto status = "/api/blocks/getStatus";
    const auto supply = "/api/blocks/getSupply";
}
/***/
namespace Delegates
{
    const auto base = "/api/delegates";
    const auto count = "/api/delegates/count";
    const auto fee = "/api/delegates/fee";
    const auto forgedByAccount = "/api/delegates/forging/getForgedByAccount";
    const auto get = "/api/delegates/get";
    const auto nextForgers = "/api/delegates/getNextForgers";
    const auto search = "/api/delegates/search";
    const auto voters = "/api/delegates/voters";
}
/***/
namespace Loader
{
    const auto status = "/api/loader/status";
    const auto sync = "/api/loader/status/sync";
    const auto autoconfigure = "/api/loader/autoconfigure";
}
/***/
namespace Peers
{
    const auto base = "/api/peers";
    const auto get = "/api/peers/get";
    const auto version = "/api/peers/version";
}
/***/
namespace Signatures
{
    const auto fee = "/api/signatures/fee";
}
/***/
namespace Transactions
{
    const auto base = "/api/transactions";
    const auto get = "/api/transactions/get";
    const auto getUnconfirmed = "/api/transactions/unconfirmed/get";
    const auto allUnconfirmed = "/api/transactions/unconfirmed";

}

}
}
}
}
}

#endif
