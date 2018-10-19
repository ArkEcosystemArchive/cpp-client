
#include "api/one/transactions/one_transactions.h"

/**
 * /api/transactions/get?id=
 **/
std::string Ark::Client::API::ONE::Transactions::get(const char *const id)
{
    char uri[114 + 1] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Transactions::get);
        strcat(uri, "?id=");
        strcat(uri, id);
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
    char uri[64] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Transactions::base);
        strcat(uri, "?orderBy=");
        strcat(uri, orderBy);
        strcat(uri, ":");
        strcat(uri, (isDescending ? "desc" : "asc"));
        strcat(uri, "&limit=");
        strcat(uri, toString(limit).c_str());
    return this->http->get(uri);
}
/**/

/***/

/**
 * /api/transactions/unconfirmed/get?id=
 **/
std::string Ark::Client::API::ONE::Transactions::getUnconfirmed(const char *const id)
{
    char uri[126 + 1] = {'\0'};
        strcpy(uri, Ark::Client::API::ONE::Paths::Transactions::getUnconfirmed);
        strcat(uri, "?id=");
        strcat(uri, id);
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
