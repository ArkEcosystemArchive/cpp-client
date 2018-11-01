
#include "api/one/delegates/one_delegates.h"

/**
 * /api/delegates/get?username="username"
 * /api/delegates/get?publicKey=publicKey
 **/
std::string Ark::Client::API::ONE::Delegates::get(
    const char *const parameter
) {
    char uri[128] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Delegates::get);
    bool isUsername = (strlen(parameter) <= 20);
    auto key = (isUsername) ? ("?username=") : ("?publicKey=");
        strcat(uri, key);
        strcat(uri, parameter);
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/delegates?limit=20
 **/
std::string Ark::Client::API::ONE::Delegates::all(int limit)
{
    char uri[32] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Delegates::base);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/delegates/count
 **/
std::string Ark::Client::API::ONE::Delegates::count()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Delegates::count);
};
/**/

/***/

/**
 * /api/delegates/search?q=sleepdeficit 
 **/
std::string Ark::Client::API::ONE::Delegates::search(
    const char *const username)
{
    char uri[69 + 1] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Delegates::search);
        strcat(uri, "?q=");
        strcat(uri, username);
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/delegates/fee
 **/
std::string Ark::Client::API::ONE::Delegates::fee()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Delegates::fee);
};
/**/

/***/

/**
 * /api/delegates/forging/getForgedByAccount?generatorPublicKey=_genPubkey
 **/
std::string Ark::Client::API::ONE::Delegates::forgedByAccount(const char *const generatorPublicKey)
{
    char uri[152 + 1];
        strcpy(uri, Ark::Client::API::ONE::Paths::Delegates::forgedByAccount);
        strcat(uri, "?generatorPublicKey=");
        strcat(uri, generatorPublicKey);
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/delegates/getNextForgers
 **/
std::string Ark::Client::API::ONE::Delegates::nextForgers()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Delegates::nextForgers);
};
/**/

/***/

/**
 * /api/delegates/voters?publicKey=_pubKey
 **/
std::string Ark::Client::API::ONE::Delegates::voters(
    const char *const publicKey)
{
    char uri[123 + 1] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Delegates::voters);
        strcat(uri, "?publicKey=");
        strcat(uri, publicKey);
    return this->http->get(uri);
};
/**/
