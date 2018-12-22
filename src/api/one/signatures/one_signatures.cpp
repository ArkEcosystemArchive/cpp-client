
#include "api/one/signatures/one_signatures.h"

/**
 * /api/signatures/fee
 **/
std::string Ark::Client::API::ONE::Signatures::fee()
{
  return http_.get(Ark::Client::API::ONE::Paths::Signatures::fee);
}
/**/
