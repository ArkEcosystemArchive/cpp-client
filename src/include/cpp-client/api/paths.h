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

////////////////////////////////////////////////////////////////////////////////

static const char* DEFAULT_QUERY = "?page=1&limit=5";
static const char* DEFAULT_DAYS_QUERY = "?days=7";

////////////////////////////////////////////////////////////////////////////////

struct Blockchain {
  static std::string base();
  static std::string get(Host& newHost);
};

////////////////////////////////////////////////////////////////////////////////

struct Blocks {  // NOLINT
  static std::string base();
  static std::string get(Host& newHost, const char* const blockId);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string transactions(Host& newHost, const char* const blockId);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
};

////////////////////////////////////////////////////////////////////////////////

struct Businesses {
  static const char* base();
  static std::string get(Host& newHost, const char* const businessId);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string bridgechains(Host& newHost, const char* const businessId, const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
};

/***/

struct Bridgechains {
  static const char* base();
  static std::string get(Host& newHost, const char* const bridgechainId);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
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

////////////////////////////////////////////////////////////////////////////////

struct Locks {
  static const char* base();
  static std::string get(Host& newHost, const char* const lockId);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> unlocked(Host& newHost,
                                                      std::string& jsonIds,
                                                      const char* const query = DEFAULT_QUERY);
};

/***/

struct Node {
  static const char* base();
  static std::string configuration(Host& newHost);
  static std::string crypto(Host& newHost);
  static std::string fees(Host& newHost, const char* const query = DEFAULT_DAYS_QUERY);
  static std::string status(Host& newHost);
  static std::string syncing(Host& newHost);
};

////////////////////////////////////////////////////////////////////////////////

struct Peers {
  static std::string base();
  static std::string get(Host& newHost, const char* const ip);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
};

////////////////////////////////////////////////////////////////////////////////

struct Rounds {
  static std::string base();
  static std::string delegates(Host& newHost, const char* const roundId);
};

////////////////////////////////////////////////////////////////////////////////

struct Transactions {  // NOLINT
  static std::string base();
  static std::string getUnconfirmed(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string get(Host& newHost, const char* const identifier);
  static std::string allUnconfirmed(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string types(Host& newHost);
  static std::string fees(Host& newHost);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> send(Host& newHost, std::string& jsonTransaction);
};

////////////////////////////////////////////////////////////////////////////////

struct Votes {  // NOLINT
  static std::string base();
  static std::string get(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
};

////////////////////////////////////////////////////////////////////////////////

struct Wallets {  // NOLINT
  static std::string base();
  static std::string get(Host& newHost, const char* const identifier);
  static std::string all(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string top(Host& newHost, const char* const query = DEFAULT_QUERY);
  static std::string locks(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string transactions(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string transactionsSent(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string transactionsReceived(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::string votes(Host& newHost, const char* const identifier, const char* const query = DEFAULT_QUERY);
  static std::pair<std::string, std::string> search(Host& newHost,
                                                    const std::map<std::string, std::string>& bodyParameters,
                                                    const char* const query = DEFAULT_QUERY);
};

////////////////////////////////////////////////////////////////////////////////

}  // namespace paths
}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
