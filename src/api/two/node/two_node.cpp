
#include "api/two/node/two_node.h"

std::string Ark::Client::API::TWO::Node::configuration()
{
  return this->http->get(Ark::Client::API::TWO::Paths::Node::configuration);
}

/***/

std::string Ark::Client::API::TWO::Node::status()
{
  return this->http->get(Ark::Client::API::TWO::Paths::Node::status);
}

/***/

std::string Ark::Client::API::TWO::Node::syncing()
{
  return this->http->get(Ark::Client::API::TWO::Paths::Node::syncing);
} 
