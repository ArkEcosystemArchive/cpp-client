
#include "api/wallets/wallets.h"

#include <cstdio>

std::string Ark::Client::API::Wallets::get(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s?limit=%d&page=%d", Ark::Client::API::Paths::Wallets::base, identifier, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Wallets::base, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::top(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Wallets::top, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::transactions(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions?limit=%d&page=%d",
    Ark::Client::API::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::transactionsSent(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions/sent?limit=%d&page=%d",
    Ark::Client::API::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::transactionsReceived(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/transactions/received?limit=%d&page=%d",
    Ark::Client::API::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::votes(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s/%s/votes?limit=%d&page=%d",
    Ark::Client::API::Paths::Wallets::base,
    identifier,
    limit,
    page
  );
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Wallets::search(
  std::pair<const char*, const char*> body,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[96] = { };
  snprintf(
    uri,
    sizeof(uri),
    "%s?limit=%d&page=%d",
    Ark::Client::API::Paths::Wallets::search,
    limit,
    page
  );
  std::string parameterBuffer;
  parameterBuffer.reserve(strlen(body.first) + strlen(body.second) + 2);
  parameterBuffer += body.first;
  parameterBuffer += "=";
  parameterBuffer += body.second;
  return http_.post(uri, parameterBuffer.c_str());
}