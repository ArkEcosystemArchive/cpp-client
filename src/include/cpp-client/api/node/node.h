/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef NODE_H
#define NODE_H

#include "api/base.h"
#include "api/paths.h"

namespace Ark {
namespace Client {
namespace api {

class INode : public Base {
 public:
  virtual ~INode() {}

  virtual std::string configuration() = 0;
  virtual std::string status() = 0;
  virtual std::string syncing() = 0;

 protected:
  INode(Host& host, IHTTP& http) : Base(host, http) {}
};

/**/

class Node : public INode {
 public:
  Node(Host& host, IHTTP& http) : INode(host, http) {}

  std::string configuration() override;
  std::string status() override;
  std::string syncing() override;
};

}  // namespace api
}  // namespace Client
}  // namespace Ark

#endif
