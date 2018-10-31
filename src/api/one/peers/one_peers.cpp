
#include "api/one/peers/one_peers.h"

/**
 * /api/peers/get?ip=167.114.29.55&port=4002
 **/
std::string Ark::Client::API::ONE::Peers::get(
    const char *const ip,
    const int port
) {
    char uri[68 + 1] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Peers::get);
        strcat(uri, "?ip=");
        strcat(uri, ip);
        strcat(uri, "&port=");
        strcat(uri, std::to_string(port).c_str());
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/peers?limit=10
 **/
std::string Ark::Client::API::ONE::Peers::all(int limit)
{
    char uri[24] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Peers::base);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
    return this->http->get(uri);
};
/**/

/***/

/**
 * /api/peers/version
 **/
std::string Ark::Client::API::ONE::Peers::version()
{
    return this->http->get(Ark::Client::API::ONE::Paths::Peers::version);
};
/**/
