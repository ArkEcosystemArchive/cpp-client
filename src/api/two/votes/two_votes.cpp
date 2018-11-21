
#include "api/two/votes/two_votes.h"

#include <cstdint>

std::string Ark::Client::API::TWO::Votes::get(const char *const identifier)
{
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::TWO::Paths::Votes::base, identifier);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Votes::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Votes::base, limit, page);
  return this->http->get(uri);
}
