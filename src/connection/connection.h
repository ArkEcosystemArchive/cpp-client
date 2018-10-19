/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef CONNECTION_H
#define CONNECTION_H

#include "api/api.h"
#include "api/one/one_api.h"
#include "api/two/two_api.h"
#include "http/http.h"

namespace Ark {
namespace Client {
/**
 * Ark::Client::Connection<VersionedAPI>
 **/
template <class AbstractApi>
class Connection : public virtual HTTP
{
    public:
        AbstractApi api;

        Connection(){};
        Connection(AbstractApi const &other) : api(other) {}
        explicit Connection(
                const char *const newHost,
                const int newPort
        ) {
            this->http->setHost(newHost, newPort);
            this->api.setHost(newHost, newPort);
        };
};
/**/
};
};

#endif
