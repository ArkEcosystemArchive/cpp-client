
#include "api/two/blocks/two_blocks.h"

#include <cstdio>

std::string Ark::Client::API::TWO::Blocks::get(const char *const blockId)
{
  char uri[80] = { };
  snprintf(uri, sizeof(uri), "%s/%s", Ark::Client::API::TWO::Paths::Blocks::base, blockId);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::all(
  int limit,
  const int page
) {
  char uri[256] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Blocks::base, limit, page);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::transactions(const char *const blockId)
{
  char uri[256] = {  };
  snprintf(uri, sizeof(uri), "%s/%s/transactions", Ark::Client::API::TWO::Paths::Blocks::base, blockId);
  return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::search(
  std::pair<const char*, const char*> bodyParameters,
  int limit,
  int page
) {
  char uri[96] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d&page=%d", Ark::Client::API::TWO::Paths::Blocks::search, limit, page);
  std::string parameterBuffer;
  parameterBuffer.reserve(strlen(bodyParameters.first) + strlen(bodyParameters.second) + 1);
  parameterBuffer += bodyParameters.first;
  parameterBuffer += "=";
  parameterBuffer += bodyParameters.second;
  return this->http->post(uri, parameterBuffer.c_str());
}
