#ifndef __MOCK_HTTP_H__
#define __MOCK_HTTP_H__

#include "http/http.h"

#include "gmock/gmock.h"

class MockHTTP : public Ark::Client::IHTTP {
public:
  MockHTTP() = default;
  
  MOCK_CONST_METHOD0(host, const char*());
  MOCK_CONST_METHOD0(port, int());
  MOCK_CONST_METHOD0(api_version, int());
  MOCK_METHOD3(setHost, bool(const char* const, int, int));
  MOCK_METHOD1(get, std::string(const char* const));
  MOCK_METHOD2(post, std::string(const char* const, const char* const));
};

#endif
