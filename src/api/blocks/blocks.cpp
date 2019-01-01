
#include "api/blocks/blocks.h"

std::string Ark::Client::API::Blocks::get(const char *const blockId)
{
  return http_->get(
    Ark::Client::API::Paths::Blocks::get(this->host_, blockId).c_str()
  );
}

/***/

std::string Ark::Client::API::Blocks::all(
  int limit /* = 5 */,
  int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Blocks::all(this->host_, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Blocks::transactions(const char *const blockId)
{
  return http_->get(
    Ark::Client::API::Paths::Blocks::transactions(this->host_, blockId).c_str()
  );
}

/***/

std::string Ark::Client::API::Blocks::search(
  const std::map<std::string, std::string>& bodyParameters,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  const auto searchPathPair = Ark::Client::API::Paths::Blocks::search(this->host_, bodyParameters, limit, page);
  return http_->post(
    searchPathPair.first.c_str(), searchPathPair.second.c_str()
  );
}
