
#include "api/node/node.h"

std::string Ark::Client::API::Node::configuration()
{
  return http_.get(Ark::Client::API::Paths::Node::configuration);
}

/***/

std::string Ark::Client::API::Node::status()
{
  return http_.get(Ark::Client::API::Paths::Node::status);
}

/***/

std::string Ark::Client::API::Node::syncing()
{
  return http_.get(Ark::Client::API::Paths::Node::syncing);
} 
