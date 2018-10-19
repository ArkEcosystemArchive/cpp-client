
#include "api/two/wallets/two_wallets.h"

std::string Ark::Client::API::TWO::Wallets::get(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::all(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::top(
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::top);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::transactions(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions");
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::transactionsSent(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/sent");
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::transactionsReceived(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/transactions/received");
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::votes(
        const char *const identifier,
        int limit,
        int page
) {
    char uri[128] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::base);
        strcat(uri, "/");
        strcat(uri, identifier);
        strcat(uri, "/votes");
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    return this->http->get(uri);
}

/***/

std::string Ark::Client::API::TWO::Wallets::search(
        std::pair<const char*, const char*> body,
        int limit,
        int page
) {
    char uri[96] = { '\0' };
        strcpy(uri, Ark::Client::API::TWO::Paths::Wallets::search);
        strcat(uri, "?limit=");
        strcat(uri, toString(limit).c_str());
        strcat(uri, "&page=");
        strcat(uri, toString(page).c_str());
    std::string parameterBuffer;
        parameterBuffer += body.first;
        parameterBuffer += "=";
        parameterBuffer += body.second;
    return this->http->post(uri, parameterBuffer.c_str());
}
