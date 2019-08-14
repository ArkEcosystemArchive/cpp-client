
#include "api/delegates/delegates.h"

std::string Ark::Client::API::Delegates::get(
    const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Delegates::get(
      this->host_,
      identifier).c_str());
}

/**/

std::string Ark::Client::API::Delegates::all(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Delegates::all(
      this->host_,
      query).c_str());
}

/**/

std::string Ark::Client::API::Delegates::blocks(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Delegates::blocks(
      this->host_,
      identifier,
      query).c_str());
}

/**/

std::string Ark::Client::API::Delegates::voters(
    const char *const identifier,
    const char* const query) {
  return http_->get(Ark::Client::API::Paths::Delegates::voters(
      this->host_,
      identifier,
      query).c_str());
}
