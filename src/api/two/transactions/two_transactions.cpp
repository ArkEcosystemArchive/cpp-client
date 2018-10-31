
#include "api/two/transactions/two_transactions.h"

std::string Ark::Client::API::TWO::Transactions::getUnconfirmed(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?id=");
        strcat(uri, identifier);
        strcat(uri, "&limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::all(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Transactions::base);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::get(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Transactions::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::allUnconfirmed(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Transactions::unconfirmed);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Transactions::types(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Transactions::types);
        strcat(uri, "?limit=");
        strcat(uri, std::to_string(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, std::to_string(page).c_str());
    return this->http->get(uri);
}
