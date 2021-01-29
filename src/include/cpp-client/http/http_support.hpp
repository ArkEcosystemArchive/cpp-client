/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HTTP_SUPPORT_HPP
#define HTTP_SUPPORT_HPP

#include <memory>
#include <string>

namespace Ark {
namespace Client {

////////////////////////////////////////////////////////////////////////////////
// Example Implementation
//
// /////////////////////////////////////////////////////////////////////////////
// class SomeHttp : public AbstractHttp {
//  public:
//   SomeHttp() = default;
//
//   std::string get(const std::string &request) override { ... }
//   std::string post(const std::string &request,
//                    const std::string &body) override { ... }
//
//   std::string get(const char* request) override { ... }
//   std::string post(const char* request, const char* body) override { ... }
// };
//
// /////////////////////////////////////////////////////////////////////////////
// std::unique_ptr<IHttp> getSomeNewHttp() {
//   return std::unique_ptr<IHttp>(new SomeHttp());
// }
//

////////////////////////////////////////////////////////////////////////////////
class IHttp {  // LCOV_EXCL_START
 protected:
  IHttp() = default;

 public:
  virtual ~IHttp() {}

  //////////////////////////////////////////////////////////////////////////////
  // !DEPRECATED
  virtual std::string get(const char* request) = 0;
  virtual std::string post(const char* request, const char* body) = 0;

  //////////////////////////////////////////////////////////////////////////////
  virtual std::string get(const std::string& request) = 0;
  virtual std::string post(const std::string& request,
                           const std::string& body) = 0;
};

////////////////////////////////////////////////////////////////////////////////
class AbstractHttp : public IHttp {
 protected:
  AbstractHttp() = default;
  AbstractHttp(AbstractHttp&&) = delete;
  AbstractHttp(const AbstractHttp& other) = delete;
  AbstractHttp& operator=(AbstractHttp&&) = delete;
  AbstractHttp& operator=(const AbstractHttp& other) = default;

 public:
  virtual ~AbstractHttp(){};
};  // LCOV_EXCL_STOP

//////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IHttp> DefaultHttp();

}  // namespace Client
}  // namespace Ark

#endif  // HTTP_SUPPORT_HPP
