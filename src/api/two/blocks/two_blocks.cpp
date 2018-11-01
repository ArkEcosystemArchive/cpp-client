
#include "api/two/blocks/two_blocks.h"

std::string Ark::Client::API::TWO::Blocks::get(const char *const blockId)
{
    char uri[80] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::all(
        int limit,
        const int page
) {
    char uri[256] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Blocks::base);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::transactions(const char *const blockId)
{
    char uri[256] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Blocks::base);
        strcat(uri, "/");
        strcat(uri, blockId);
        strcat(uri, "/transactions");
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Blocks::search(
        std::pair<const char*, const char*> bodyParameters,
        int limit,
        int page
) {
    char uri[96] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Blocks::search);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    std::string parameterBuffer;
        parameterBuffer += bodyParameters.first;
        parameterBuffer += "=";
        parameterBuffer += bodyParameters.second;
    return this->http->post(uri, parameterBuffer.c_str());
}
