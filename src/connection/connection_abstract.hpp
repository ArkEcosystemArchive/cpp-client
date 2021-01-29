/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef CONNECTION_ABSTRACT_HPP
#define CONNECTION_ABSTRACT_HPP

#include <memory>
#include <string>

#include "api/api.hpp"
#include "api/api_handler.hpp"

#include "http/http_support.hpp"

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
constexpr auto DEFAULT_PEER_ADN = "https://dwallets.ark.io";

////////////////////////////////////////////////////////////////////////////////
template <typename API_IMPL>
class AbstractConnection : public api::ApiHandler {
 protected:
  std::string peer_;
  std::unique_ptr<IHttp> http_;

 public:
  API_IMPL api;

  //////////////////////////////////////////////////////////////////////////////
  AbstractConnection(const std::string &peer, std::unique_ptr<IHttp> http)
      : peer_(peer), http_(std::move(http)), api(*this) {}

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  AbstractConnection(const char *domain, int port) : api(*this) {
    constexpr const size_t IP_MAX_STRING_LEN = 17U;
    constexpr const size_t PORT_MAX_STRING_LEN = 5U;

    this->peer_.reserve(IP_MAX_STRING_LEN + PORT_MAX_STRING_LEN);
    this->peer_ += std::string(domain);
    this->peer_ += ":";

    char temp[PORT_MAX_STRING_LEN];
    snprintf(temp, PORT_MAX_STRING_LEN, "%d", port);

    this->peer_ += std::string(temp);
  }

  //////////////////////////////////////////////////////////////////////////////
  std::string getPeer() { return this->peer_; }

  //////////////////////////////////////////////////////////////////////////////
  virtual std::string process(int action, const std::string &endpoint,
                              const std::string &body) = 0;
};

}  // namespace Client
}  // namespace Ark

#endif  // CONNECTION_ABSTRACT_HPP
