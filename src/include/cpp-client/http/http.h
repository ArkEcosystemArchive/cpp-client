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

class IHTTP {
protected:
  IHTTP() = default;

public:
  virtual ~IHTTP() { }

  virtual const char* host() const /*noexcept*/ = 0;
  virtual int port() const /*noexcept*/ = 0;
  virtual int api_version() const /*noexcept*/ = 0;

  virtual bool setHost(
    const char *const newHost,
    int newPort,
    int api_version
  ) = 0;

  virtual std::string get(const char *const request) = 0;
  virtual std::string post(const char *const request, const char *body) = 0;

  /**/
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
        char host_[17];
        int port_;
        int api_version_;

        AbstractHTTP() : host_(), port_(-1), api_version_(0) { }

        AbstractHTTP(AbstractHTTP&&) = delete;
        AbstractHTTP& operator=(AbstractHTTP&&) = delete;

        AbstractHTTP(const AbstractHTTP& other) : port_(other.port_), api_version_(other.api_version_) {
          strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
        }

        AbstractHTTP& operator=(const AbstractHTTP& other) noexcept {
          if (this != &other) {
            strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = other.port_;
            this->api_version_ = other.api_version_;
          }
          return *this;
        }

    public:
        virtual ~AbstractHTTP() {};

        /**/
        const char* host() const /*noexcept*/ override { return this->host_; };
        int port() const /*noexcept*/ override { return this->port_; };
        int api_version() const /*noexcept*/ override { return this->api_version_; }

        bool setHost(
                const char *const newHost,
                int newPort,
                int api_version
        ) override {
            strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = newPort;
            this->api_version_ = api_version;
            return (this->port_ == newPort) && strcmp(this->host_, newHost);
        }
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
