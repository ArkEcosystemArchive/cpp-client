#include "host/host.h"

Ark::Client::Host::Host() : ip_(), port_(-1) {}

/***/

Ark::Client::Host::Host(const Host& other) : port_(other.port_) {
  strncpy(this->ip_, other.ip_, sizeof(this->ip_) / sizeof(this->ip_[0]));
}

/***/

Ark::Client::Host& Ark::Client::Host::Host::operator=(const Host& other) noexcept {
  if (this != &other) {
    strncpy(this->ip_, other.ip_, sizeof(this->ip_) / sizeof(this->ip_[0]));
    this->port_ = other.port_;
  }
  return *this;
}

/***/

Ark::Client::Host::Host(const char *const newIP, int newPort) : port_(newPort)
{
  strncpy(this->ip_, newIP, sizeof(this->ip_) / sizeof(this->ip_[0]));
}

/***/

const char* Ark::Client::Host::ip() const noexcept { return this->ip_; };

/***/

int Ark::Client::Host::port() const noexcept { return this->port_; };

/***/

std::string Ark::Client::Host::toString()
{
  char temp[36] = {};
  snprintf(temp, sizeof(this->ip_) + sizeof(this->port_), "%s:%d", this->ip_, this->port_);
  return temp;
}

/***/

bool Ark::Client::Host::set(
    const char *const newIP,
    int newPort
) {
  strncpy(this->ip_, newIP, sizeof(this->ip_) / sizeof(this->ip_[0]));
  this->port_ = newPort;
  return (this->port_ == newPort) && strcmp(this->ip_, newIP);
}
