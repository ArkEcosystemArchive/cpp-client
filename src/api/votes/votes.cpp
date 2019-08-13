
#include "api/votes/votes.h"

std::string Ark::Client::API::Votes::get(
    const char *const identifier) {
  return http_->get(Ark::Client::API::Paths::Votes::get(
      this->host_,
      identifier).c_str());
}

/**/

std::string Ark::Client::API::Votes::all(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Votes::all(
      this->host_,
      query).c_str());
}
