/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef API_H
#define API_H

#include "http/http.h"

namespace Ark {
namespace Client {

/**
 * Ark::Client::AbstractApi 
 **/
class AbstractApi : public virtual HTTP
{
    protected:
        int version_;
    public:
        int version() { return this->version_; };
};
/**/
};
};

#endif
