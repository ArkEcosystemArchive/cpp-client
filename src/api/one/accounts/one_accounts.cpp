
#include "api/one/accounts/one_accounts.h"

#include <cstdio>

/**
 * /api/accounts/getBalance?address=arkAddress
 **/
std::string Ark::Client::API::ONE::Accounts::balance(const char *const arkAddress)
{
  char uri[68 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Ark::Client::API::ONE::Paths::Accounts::balance, arkAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * api/accounts/getPublickey?address=arkAddress
 **/
std::string Ark::Client::API::ONE::Accounts::publickey(const char *const arkAddress)
{
  char uri[94 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Ark::Client::API::ONE::Paths::Accounts::publicKey, arkAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts/delegates/fee?address=arkAddress
 **/
std::string Ark::Client::API::ONE::Accounts::delegatesFee(const char *const arkAddress)
{
  char uri[95 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Ark::Client::API::ONE::Paths::Accounts::delegatesFee, arkAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts/delegates?address=arkAddress
 **/
std::string Ark::Client::API::ONE::Accounts::delegates(const char *const arkAddress)
{
  char uri[91 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Ark::Client::API::ONE::Paths::Accounts::delegates, arkAddress);
  return http_.get(uri);
}
/**/

/***/

/**
 * /api/accounts?address=arkAddress
 **/
std::string Ark::Client::API::ONE::Accounts::get(
    const char *const arkAddress
) {
  char uri[81 + 1] = { '\0' };
  snprintf(uri, sizeof(uri), "%s?address=%s", Ark::Client::API::ONE::Paths::Accounts::base, arkAddress);
  return http_.get(uri);
}
/**/
