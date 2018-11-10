
#include "api/one/blocks/one_blocks.h"

#include <cstring>

/**
 * /api/blocks/get?id=_blockID
 **/
std::string Ark::Client::API::ONE::Blocks::get(const char *const blockId)
{
  char uri[80] = { '\0' };
  std::snprintf(uri, sizeof(uri), "%s?id=%s", Ark::Client::API::ONE::Paths::Blocks::get, blockId);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/blocks?orderBy=height:desc&limit=10
 **/
std::string Ark::Client::API::ONE::Blocks::all(
  const char *const orderBy /* = "height" */,
  bool isDescending /* = true */,
  int limit /* = 10 */
) {
  char uri[48] = { '\0' };
  std::snprintf(
    uri,
    sizeof(uri),
    "%s?orderBy=%s:%s&limit=%d",
    Ark::Client::API::ONE::Paths::Blocks::base,
    orderBy,
    isDescending ? "desc" : "asc",
    limit
  );
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/blocks/getEpoch
 **/
std::string Ark::Client::API::ONE::Blocks::epoch()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::epoch);
}
/**/

/***/

/**
 * /api/blocks/getFee
 **/
std::string Ark::Client::API::ONE::Blocks::fee()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::fee);
}
/**/

/***/

/**
 * /api/blocks/getFees
 **/
std::string Ark::Client::API::ONE::Blocks::fees()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::fees);
}
/**/

/***/

/**
 * /api/blocks/getHeight
 **/
std::string Ark::Client::API::ONE::Blocks::height()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::height);
}
/**/

/***/

/**
 * /api/blocks/getMilestone
 **/
std::string Ark::Client::API::ONE::Blocks::milestone()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::milestone);
}
/**/

/***/

/**
 * /api/blocks/getNethash
 **/
std::string Ark::Client::API::ONE::Blocks::nethash()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::nethash);
}
/**/

/***/

/**
 * /api/blocks/getReward
 **/
std::string Ark::Client::API::ONE::Blocks::reward()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::reward);
}
/**/

/***/

/**
 * /api/blocks/getSupply
 **/
std::string Ark::Client::API::ONE::Blocks::supply()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::supply);
}
/**/

/***/

/**
 * /api/blocks/getStatus
 **/
std::string Ark::Client::API::ONE::Blocks::status()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Blocks::status);
}
/**/
