
#include "api/two/transactions/two_transactions.h"

#include <cstdio>

std::string Ark::Client::API::TWO::Transactions::getUnconfirmed(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?id=%s&limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::unconfirmed, identifier, limit, page);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::base, limit, page);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::get(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::base, identifier, limit, page);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::allUnconfirmed(
  int limit /* = 5 */,
  int page /* =1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::unconfirmed, limit, page);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::types(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::types, limit, page);
  return http_->get(uri);
}

std::string Ark::Client::API::TWO::Transactions::search(const std::map<std::string, std::string>& body_parameters, int limit /* = 5 */, int page /* = 1 */) {
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Transactions::search, limit, page);
  std::string parameterBuffer;
  for (const auto& p : body_parameters) {
    parameterBuffer += p.first + '=' + p.second + '&';
  }
  return http_.post(uri, parameterBuffer.c_str());
}
