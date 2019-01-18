
#include "api/delegates/delegates.h"

std::string Ark::Client::API::Delegates::get(const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Delegates::get(this->host_, identifier).c_str());
}

/***/

std::string Ark::Client::API::Delegates::all(int limit /* = 5 */, int page /* = 1 */) {
  return http_->get(Ark::Client::API::Paths::Delegates::all(this->host_, limit, page).c_str());
}

/***/

std::string Ark::Client::API::Delegates::blocks(const char *const identifier, int limit /* = 5 */, int page /* = 1 */) {
  return http_->get(Ark::Client::API::Paths::Delegates::blocks(this->host_, identifier, limit, page).c_str());
}

/***/

std::string Ark::Client::API::Delegates::voters(const char *const identifier, int limit /* = 5 */, int page /* = 1 */) {
  return http_->get(Ark::Client::API::Paths::Delegates::voters(this->host_, identifier, limit, page).c_str());
}
