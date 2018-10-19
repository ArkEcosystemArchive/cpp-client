
#include "api/two/peers/two_peers.h"

std::string Ark::Client::API::TWO::Peers::get(const char *const ip)
{
    char uri[96] = { '\0' };
	    strcpy(uri, Ark::Client::API::TWO::Paths::Peers::base);
        strcat(uri, "/");
        strcat(uri, ip);
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Peers::all(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Peers::base);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}
