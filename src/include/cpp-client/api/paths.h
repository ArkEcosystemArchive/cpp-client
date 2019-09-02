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

#include <cstdio>
#include <map>
#include <string>

#include "host/host.h"

namespace Ark {
namespace Client {
namespace api {
namespace paths {  // NOLINT

static const char* DEFAULT_QUERY = "?page=1&limit=5";

struct Blockchain {
  static const char* base();
  static std::string get(Host& newHost);
};

/***/

struct Blocks {
  static const char* base();
  static std::string get(Host& newHost, const char* const blockId);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string transactions(Host& newHost, const char* const blockId);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
};

/***/

struct Delegates {
  static const char* base();
  static std::string get(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string blocks(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string voters(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
};

/***/

struct Node {
  static const char* base();
  static std::string configuration(Host& newHost);
  static std::string crypto(Host& newHost);
  static std::string status(Host& newHost);
  static std::string syncing(Host& newHost);
};

/***/

struct Peers {
  static const char* base();
  static std::string get(Host& newHost, const char* const ip);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
};

/***/

struct Transactions {
  static const char* base();
  static std::string getUnconfirmed(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string get(Host& newHost, const char* const identifier);
  static std::string allUnconfirmed(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string types(Host& newHost);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> send(Host& newHost, std::string& jsonTransaction);
};

/***/

struct Votes {
  static const char* base();
  static std::string get(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
};

/***/

struct Wallets {
  static const char* base();
  static std::string get(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string top(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string transactions(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string transactionsSent(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string transactionsReceived(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string votes(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
};

}  // namespace paths
}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
