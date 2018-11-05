
#include "api/two/delegates/two_delegates.h"

std::string Ark::Client::API::TWO::Delegates::get(const char *const identifier)
{
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::all(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Delegates::base);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::blocks(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/blocks");
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Delegates::voters(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Delegates::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/voters");
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}
