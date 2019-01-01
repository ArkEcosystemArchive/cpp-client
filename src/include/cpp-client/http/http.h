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

#include <memory>
#include <string>
#include <cstring>

namespace Ark {
namespace Client {

class IHTTP
{
  protected:
    IHTTP() = default;

  public:
    virtual ~IHTTP() { }

    virtual int api_version() const /*noexcept*/ = 0;

    virtual std::string get(const char *const request) = 0;
    virtual std::string post(const char *const request, const char *body) = 0;
};

/***
 * Ark::Client::AbstractHTTP
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **/
class AbstractHTTP : public IHTTP
{
  protected:
    int api_version_;

    AbstractHTTP() : api_version_(0) { };

    AbstractHTTP(AbstractHTTP&&) = delete;
    AbstractHTTP& operator=(AbstractHTTP&&) = delete;

    AbstractHTTP(const AbstractHTTP& other) : api_version_(other.api_version_) { };

    AbstractHTTP& operator=(const AbstractHTTP& other) noexcept {
      if (this != &other) {
        this->api_version_ = other.api_version_;
      }
      return *this;
    };

  public:
    virtual ~AbstractHTTP() {};

    int api_version() const /*noexcept*/ override { return this->api_version_; }
};
/**/

/***/

/***
 * HTTP object factory
 **/
std::unique_ptr<IHTTP> makeHTTP();
/**/

};
};
/**/

#endif
