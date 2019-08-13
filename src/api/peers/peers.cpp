
#include "api/peers/peers.h"

std::string Ark::Client::API::Peers::get(
    const char *const ip) {
  return http_->get(Ark::Client::API::Paths::Peers::get(
    this->host_, ip).c_str());
}

/**/

std::string Ark::Client::API::Peers::all(const char* const query) {
  return http_->get(Ark::Client::API::Paths::Peers::all(
      this->host_,
      query).c_str());
}
