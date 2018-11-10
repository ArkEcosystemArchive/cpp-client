
#include "api/one/transactions/one_transactions.h"

#include <cstring>

/**
 * /api/transactions/get?id=
 **/
std::string Ark::Client::API::ONE::Transactions::get(const char *const id)
{
  char uri[114 + 1] = { };
  std::snprintf(uri, sizeof(uri), "%s?id=%s", Ark::Client::API::ONE::Paths::Transactions::get, id);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/transactions/?orderBy=timestamp:desc&limit=10"
 **/
std::string Ark::Client::API::ONE::Transactions::all(
        int limit,
        const char *const orderBy,
        bool isDescending
) {
  char uri[64] = { };
  std::snprintf(
    uri,
    sizeof(uri),
    "%s?orderBy=%s:%s&limit=%d",
    Ark::Client::API::ONE::Paths::Transactions::base,
    orderBy,
    isDescending ? "desc" : "asc",
    limit
  );
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/transactions/unconfirmed/get?id=
 **/
std::string Ark::Client::API::ONE::Transactions::getUnconfirmed(const char *const id)
{
  char uri[126 + 1] = { };
  std::snprintf(uri, sizeof(uri), "%s?id=%s", Ark::Client::API::ONE::Paths::Transactions::getUnconfirmed, id);
  return this->http->get(uri);
}
/**/

/***/

/**
 * /api/transactions/unconfirmed
 **/
std::string Ark::Client::API::ONE::Transactions::allUnconfirmed()
{
  return this->http->get(Ark::Client::API::ONE::Paths::Transactions::allUnconfirmed);
}
/**/
