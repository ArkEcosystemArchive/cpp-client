/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "connection/connection_abstract.hpp"

#include "http/http_support.hpp"

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
template <typename API_IMPL>
class Connection : public AbstractConnection<API_IMPL> {
 public:
  //////////////////////////////////////////////////////////////////////////////
  Connection(const std::string &peer = DEFAULT_PEER_ADN,
             std::unique_ptr<IHttp> http = DefaultHttp())
      : AbstractConnection<API_IMPL>(peer, std::move(http)) {}

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  Connection(const char *domain, int port)
      : AbstractConnection<API_IMPL>(domain, port) {}

  //////////////////////////////////////////////////////////////////////////////
  // Handle the Api callback
  std::string process(int action, const std::string &uri,
                      const std::string &postBody = "") {
    std::string url = this->peer_ + uri;

    return action == api::ACTION_GET ? this->http_->get(url)
                                     : this->http_->post(url, postBody);
  }
};

}  // namespace Client
}  // namespace Ark

#endif  // CONNECTION_HPP
