
#include "api/two/delegates/two_delegates.h"

#include <cstdio>

std::string Ark::Client::API::TWO::Delegates::get(const char *const identifier)
{
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::TWO::Paths::Delegates::base, identifier);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Delegates::base, limit, page);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::blocks(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s/blocks?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Delegates::base, identifier, limit, page);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::voters(
  const char *const identifier,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s/%s/voters?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Delegates::base, identifier, limit, page);
  return this->http->get(uri);
}
