
#include "api/one/loader/one_loader.h"

/**
 * /api/loader/autoconfigure
 **/
std::string Ark::Client::API::ONE::Loader::autoconfigure()
{
  return http_->get(Ark::Client::API::ONE::Paths::Loader::autoconfigure);
}
/**/

/***/

/**
 * /api/loader/status
 **/
std::string Ark::Client::API::ONE::Loader::status()
{
  return http_->get(Ark::Client::API::ONE::Paths::Loader::status);
}
/**/

/***/

/**
 * /api/loader/status/sync
 **/
std::string Ark::Client::API::ONE::Loader::sync()
{
  return http_->get(Ark::Client::API::ONE::Paths::Loader::sync);
}
/**/
