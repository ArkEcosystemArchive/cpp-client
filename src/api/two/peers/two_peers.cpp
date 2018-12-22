
#include "api/two/peers/two_peers.h"

#include <cstdio>

std::string Ark::Client::API::TWO::Peers::get(const char *const ip)
{
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::TWO::Paths::Peers::base, ip);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Peers::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[128] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Peers::base, limit, page);
  return http_->get(uri);
}
