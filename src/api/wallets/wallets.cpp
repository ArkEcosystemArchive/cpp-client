
#include "api/wallets/wallets.h"

std::string Ark::Client::API::Wallets::get(
    const char *const identifier
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::get(this->host_, identifier).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::all(
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::all(this->host_, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::top(
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::top(this->host_, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::transactions(
    const char *const identifier,
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::transactions(this->host_, identifier, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::transactionsSent(
    const char *const identifier,
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::transactionsSent(this->host_, identifier, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::transactionsReceived(
    const char *const identifier,
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::transactionsReceived(this->host_, identifier, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::votes(
    const char *const identifier,
    int limit /* = 5 */,
    int page /* = 1 */
) {
  return http_->get(
    Ark::Client::API::Paths::Wallets::votes(this->host_, identifier, limit, page).c_str()
  );
}

/***/

std::string Ark::Client::API::Wallets::search(
  const std::map<std::string, std::string>& bodyParameters,
  int limit /* = 5 */,
  int page /* = 1 */
) {
  const auto searchPathPair = Ark::Client::API::Paths::Wallets::search(this->host_, bodyParameters, limit, page);
  return http_->post(
    searchPathPair.first.c_str(), searchPathPair.second.c_str()
  );
}
