
#include "api/blocks/blocks.h"

#include <cstdio>

std::string Ark::Client::API::Blocks::get(const char *const blockId)
{
  char uri[80] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::Paths::Blocks::base, blockId);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::Blocks::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[256] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Blocks::base, limit, page);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::Blocks::transactions(const char *const blockId)
{
  char uri[256] = {  };
  snprintf(uri, sizeof(uri), "%s/%s/transactions", Ark::Client::API::Paths::Blocks::base, blockId);
  return http_->get(uri);
}

/***/

std::string Ark::Client::API::Blocks::search(
  const std::map<std::string, std::string>& bodyParameters,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::Paths::Blocks::search, limit, page);
  std::string parameterBuffer;
  for (const auto& p : bodyParameters) {
    parameterBuffer += p.first + '=' + p.second + '&';
  }
  return http_->post(uri, parameterBuffer.c_str());
}
