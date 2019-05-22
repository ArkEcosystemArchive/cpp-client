
#include "api/node/node.h"

std::string Ark::Client::API::Node::configuration() {
  return http_->get(Ark::Client::API::Paths::Node::configuration(
      this->host_).c_str());
}

/**/

std::string Ark::Client::API::Node::status() {
  return http_->get(Ark::Client::API::Paths::Node::status(
      this->host_).c_str());
}

/**/

std::string Ark::Client::API::Node::syncing() {
  return http_->get(Ark::Client::API::Paths::Node::syncing(
      this->host_).c_str());
}
