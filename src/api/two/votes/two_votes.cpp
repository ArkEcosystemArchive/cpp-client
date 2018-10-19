
#include "api/two/votes/two_votes.h"

std::string Ark::Client::API::TWO::Votes::get(const char *const identifier)
{
    char uri[96] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Votes::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Votes::all(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Votes::base);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}
