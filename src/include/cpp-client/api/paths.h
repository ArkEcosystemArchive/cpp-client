/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef PATHS_H
#define PATHS_H

#include "host/host.h"

#include <cstdio>
#include <map>
#include <string>

namespace Ark {
namespace Client {
namespace API {
namespace Paths {

namespace Blocks {
extern const char* base();
/***/
extern std::string get(Host& newHost, const char* const blockId);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string transactions(Host& newHost, const char* const blockId);
/***/
extern std::pair<std::string, std::string> search(Host& newHost,
                                                  const std::map<std::string, std::string>& bodyParameters,
                                                  int limit = 5, int page = 1);
/***/
};  // namespace Blocks

/***/

namespace Delegates {
extern const char* base();
/***/
extern std::string get(Host& newHost, const char* const identifier);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string blocks(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
extern std::string voters(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
};  // namespace Delegates

/***/

namespace Node {
extern const char* base();
/***/
extern std::string configuration(Host& newHost);
/***/
extern std::string status(Host& newHost);
/***/
extern std::string syncing(Host& newHost);
/***/
};  // namespace Node

/***/

namespace Peers {
extern const char* base();
/***/
extern std::string get(Host& newHost, const char* const ip);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
};  // namespace Peers

/***/

namespace Transactions {
extern const char* base();
/***/
extern std::string getUnconfirmed(Host& newHost, const char* const identifier);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string get(Host& newHost, const char* const identifier);
/***/
extern std::string allUnconfirmed(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string types(Host& newHost);
/***/
extern std::pair<std::string, std::string> search(Host& newHost,
                                                  const std::map<std::string, std::string>& bodyParameters,
                                                  int limit = 5, int page = 1);
/***/
};  // namespace Transactions

/***/

namespace Votes {
extern const char* base();
/***/
extern std::string get(Host& newHost, const char* const identifier);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
};  // namespace Votes

/***/

namespace Wallets {
extern const char* base();
/***/
extern std::string get(Host& newHost, const char* const identifier);
/***/
extern std::string all(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string top(Host& newHost, int limit = 5, int page = 1);
/***/
extern std::string transactions(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
extern std::string transactionsSent(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
extern std::string transactionsReceived(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
extern std::string votes(Host& newHost, const char* const identifier, int limit = 5, int page = 1);
/***/
extern std::pair<std::string, std::string> search(Host& newHost,
                                                  const std::map<std::string, std::string>& bodyParameters,
                                                  int limit = 5, int page = 1);
/***/
};  // namespace Wallets

};  // namespace Paths
};  // namespace API
};  // namespace Client
};  // namespace Ark

#endif
