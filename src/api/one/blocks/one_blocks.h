/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef ONE_BLOCKS_H
#define ONE_BLOCKS_H

#include "api/api_base.h"
#include "api/one/one_paths.h"
#include "helpers/helpers.h"

namespace Ark {
namespace Client {
namespace API {
namespace ONE {

class Blocks : public ApiBase
{
    public:
        std::string get(const char *const blockId);
        std::string all(const char *const orderBy = "height", bool isDescending = true, int limit = 10);
        std::string epoch();
        std::string fee();
        std::string fees();
        std::string height();
        std::string milestone();
        std::string nethash();
        std::string reward();
        std::string supply();
        std::string status();
};

};
};
};
};

#endif
