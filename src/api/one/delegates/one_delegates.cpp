
#include "api/one/delegates/one_delegates.h"

#include <cstdio>

/**
 * /api/delegates/get?username="username"
 * /api/delegates/get?publicKey=publicKey
 **/
std::string Ark::Client::API::ONE::Delegates::get(
    const char *const parameter
) {
  char uri[128] = { };
  const auto isUsername = std::strlen(parameter) <= 20;

  snprintf(
    uri,
    sizeof(uri),
    "%s%s%s",
    Ark::Client::API::ONE::Paths::Delegates::get,
    isUsername ? "?username=" : "?publicKey=",
    parameter
  );
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/delegates?limit=20
 **/
std::string Ark::Client::API::ONE::Delegates::all(int limit)
{
  char uri[32] = { };
  snprintf(uri, sizeof(uri), "%s?limit=%d", Ark::Client::API::ONE::Paths::Delegates::base, limit);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/delegates/count
 **/
std::string Ark::Client::API::ONE::Delegates::count()
{
  return this->http->get(Ark::Client::API::ONE::Paths::Delegates::count);
}
/**/

/***/

/**
 * /api/delegates/search?q=sleepdeficit 
 **/
std::string Ark::Client::API::ONE::Delegates::search(
    const char *const username)
{
  char uri[69 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?q=%s", Ark::Client::API::ONE::Paths::Delegates::search, username);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/delegates/fee
 **/
std::string Ark::Client::API::ONE::Delegates::fee()
{
  return this->http->get(Ark::Client::API::ONE::Paths::Delegates::fee);
}
/**/

/***/

/**
 * /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
 **/
std::string Ark::Client::API::ONE::Delegates::forgedByAccount(const char *const generatorPublicKey)
{
  char uri[152 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?generatorPublicKey=%s", Ark::Client::API::ONE::Paths::Delegates::forgedByAccount, generatorPublicKey);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/delegates/getNextForgers
 **/
std::string Ark::Client::API::ONE::Delegates::nextForgers()
{
  return this->http->get(Ark::Client::API::ONE::Paths::Delegates::nextForgers);
}
/**/

/***/

/**
 * /api/delegates/voters?publicKey=_pubKey
 **/
std::string Ark::Client::API::ONE::Delegates::voters(
    const char *const publicKey)
{
  char uri[123 + 1] = { };
  snprintf(uri, sizeof(uri), "%s?publicKey=%s", Ark::Client::API::ONE::Paths::Delegates::voters, publicKey);
  return this->http->get(uri);
}
/**/
