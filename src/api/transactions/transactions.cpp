
#include "api/transactions/transactions.h"

#include <cstdio>

std::string Ark::Client::API::Transactions::getUnconfirmed(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?id=%s&limit=%d&page=%d", Ark::Client::API::Paths::Transactions::unconfirmed, identifier, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Transactions::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Transactions::base, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Transactions::get(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s?limit=%d&page=%d", Ark::Client::API::Paths::Transactions::base, identifier, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Transactions::allUnconfirmed(
  int limit /* = 5 */,
  int page /* =1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Transactions::unconfirmed, limit, page);
  return http_.get(uri);
}

/***/

std::string Ark::Client::API::Transactions::types(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Transactions::types, limit, page);
  return http_.get(uri);
}
