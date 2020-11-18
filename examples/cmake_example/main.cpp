#include <arkClient.h>

#include <iostream>

int main(int argc, char* argv[]) {  // NOLINT
  // Create a connection
  Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.54", 4003);

  // Perform an API call using the connection to access endpoint
  const auto blockchainResponse = connection.api.blockchain.get();
  std::cout << "Response for blockchain:\n";
  std::cout << blockchainResponse << "\n\n";

  const auto blockResponse = connection.api.blocks.get("13114381566690093367");
  std::cout << "Response for block '13114381566690093367':\n";
  std::cout << blockResponse << "\n\n";

  const auto delegateResponse = connection.api.delegates.get("genesis_1");
  std::cout << "Response for delegate 'genesis_1':\n";
  std::cout << delegateResponse << "\n\n";

  const auto nodeConfiguration = connection.api.node.configuration();
  std::cout << "Response for configuration of node '167.114.29.54:4003':\n";
  std::cout << nodeConfiguration << "\n\n";

  const auto peer = connection.api.peers.get("167.114.29.49");
  std::cout << "Response for peer '167.114.29.49':\n";
  std::cout << peer << "\n\n";

  const auto transaction =connection.api.transactions.get(
      "ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4");
  std::cout << "Response for transaction 'ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4':\n";
  std::cout << transaction << "\n\n";

  const auto vote = connection.api.votes.get(
      "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67");
  std::cout << "Response for votes 'a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67':\n";
  std::cout << vote << "\n\n";

  const auto walletsGet = connection.api.wallets.get("genesis_1");
  std::cout << "Response for wallet 'genesis_1':\n";
  std::cout << walletsSearch << std::endl;

  return 0;
}
