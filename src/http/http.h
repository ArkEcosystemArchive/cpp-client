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
        AbstractHTTP() = default;

        char host_[17];
        int port_;

    public:
        virtual ~AbstractHTTP(){};
        AbstractHTTP(AbstractHTTP const & other){
            strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = other.port_;
        };

        AbstractHTTP& operator=(AbstractHTTP&& other){
            strncpy(this->host_, other.host_, sizeof(this->host_) / sizeof(this->host_[0]));
            this->port_ = other.port_;
            return *this;
        }

        /**/
        const char *host() { return this->host_; };
        int port() { return this->port_; };

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
    public:
        std::unique_ptr<Ark::Client::AbstractHTTP> http;
        HTTP() : http(makeHTTP()) { }
        ~HTTP(){};
        void setHostHTTP(
                const char *const newHost,
                const int newPort
        ) {
            http->setHost(newHost, newPort);
        };
};
/**/

#endif
