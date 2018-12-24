/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef VOTES_H
#define VOTES_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace API {

class IVotes : public API::Base
{
protected:
  IVotes(IHTTP& http) : API::Base(http) { }

public:
  virtual ~IVotes() { }

  virtual std::string get(const char *const identifier) = 0;
  virtual std::string all(int limit = 5, int page = 1) = 0;
};

class Votes : public IVotes
{
public:
  Votes(IHTTP& http) : IVotes(http) { }

  std::string get(const char *const identifier) override;
  std::string all(int limit = 5, int page = 1) override;
};

};
};
};

#endif
