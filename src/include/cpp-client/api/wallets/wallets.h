/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef WALLETS_H
#define WALLETS_H

#include "api/base.h"
#include "api/paths.h"
#include <string>

namespace Ark {
namespace Client {
namespace API {

class Wallets : public API::Base
{
  public:
    Wallets(HTTP& http) : API::Base(http) { }

    std::string get(const char *const identifier, int limit = 5, int page = 1);
    std::string all(int limit = 5, int page = 1);
    std::string top(int limit = 5, int page = 1);
    std::string transactions(const char *const identifier, int limit = 5, int page = 1);
    std::string transactionsReceived(const char *const identifier, int limit = 5, int page = 1);
    std::string transactionsSent(const char *const identifier, int limit = 5, int page = 1);
    std::string votes(const char *const identifier, int limit = 5, int page = 1);
    std::string search(std::pair<const char*, const char*> bodyParameters, int limit = 5, int page = 1);
};

};
};
};

#endif
