/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HTTP_H
#define HTTP_H

#include <cstring>
#include <memory>
#include <string>

namespace Ark {
namespace Client {

class IHTTP {
protected:
  IHTTP() = default;

public:
  virtual ~IHTTP() {}

  virtual std::string get(const char* const request) = 0;
  virtual std::string post(const char* const request, const char* body) = 0;
};

/***
 * Ark::Client::AbstractHTTP
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **/
class AbstractHTTP : public IHTTP {
protected:
  AbstractHTTP() = default;
  AbstractHTTP(AbstractHTTP&&) = delete;
  AbstractHTTP& operator=(AbstractHTTP&&) = delete;
  AbstractHTTP& operator=(const AbstractHTTP& other) = default;

public:
  virtual ~AbstractHTTP(){};
};
/**/

/***/

/***
 * HTTP object factory
 **/
std::unique_ptr<IHTTP> makeHTTP();
/**/

};  // namespace Client
};  // namespace Ark
/**/

#endif
