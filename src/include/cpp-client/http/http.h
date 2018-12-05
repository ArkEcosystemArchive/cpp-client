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
/***
 * Ark::Client::HTTP
 * @brief: Forward Delcaration
 **/
class HTTP;
/**/

/***/

/***
 * Ark::Client::AbstractHTTP
 *
 * The purpose of this class is to serve as an
 * entry point for integrating the HTTPClient
 * library for different boards/chipsets
 **/
class AbstractHTTP
{
    protected:
        char host_[17];
        int port_;

        AbstractHTTP() : host_(), port_(-1) { }

        AbstractHTTP(AbstractHTTP&&) = delete;
        AbstractHTTP& operator=(AbstractHTTP&&) = delete;

        AbstractHTTP(const AbstractHTTP& other) : port_(other.port_) {
          strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
        }

        AbstractHTTP& operator=(const AbstractHTTP& other) noexcept {
          if (this != &other) {
            strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = other.port_;
          }
          return *this;
        }

    public:
        virtual ~AbstractHTTP() {};

        /**/
        const char* host() const noexcept { return this->host_; };
        int port() const noexcept { return this->port_; };

        /**/

        virtual std::string get(
                const char *const request
        ) = 0;

        /**/

        virtual std::string post(
                const char *const request,
                const char *body
        ) = 0;

        /**/


        bool setHost(
                const char *const newHost,
                const int newPort
        ) {
            strncpy(this->host_, newHost, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = newPort;
            return (this->port_ == newPort) && strcmp(this->host_, newHost);
        };
};
/**/

/***/

/***
 * HTTP object factory
 **/
std::unique_ptr<AbstractHTTP> makeHTTP();
/**/

};
};

/***
 * Ark::Client::HTTP
 **/
class Ark::Client::HTTP
{
private:
  std::unique_ptr<Ark::Client::AbstractHTTP> http;

public:
  HTTP() : http(makeHTTP()) { }

  const char* host() const noexcept { return http->host(); };
  int port() const noexcept { return http->port(); };

  void setHostHTTP(
          const char* const newHost,
          const int newPort
  ) {
      http->setHost(newHost, newPort);
  }

  std::string get(
    const char* const request
  ) {
    return http->get(request);
  }

  std::string post(
    const char* const request,
    const char* body
  ) {
    return http->post(request, body);
  }
};
/**/

#endif
