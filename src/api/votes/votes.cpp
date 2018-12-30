
#include "api/votes/votes.h"

#include <cstdint>
#include <cstdio>

std::string Ark::Client::API::Votes::get(const char *const identifier)
{
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::Paths::Votes::base, identifier);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::Votes::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Votes::base, limit, page);
  return http_->get(uri);
}
