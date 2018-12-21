#include "arkClient.h"

#include <iostream>


int main(int argc, char* argv[]) {

  // Create a connection
  Ark::Client::Connection<Ark::Client::API::Two> connection("167.114.29.54", 4003);
  
  // Check the API Version
  const auto apiVersion = connection.api.version();
  std::cout << "API Version: " << apiVersion << "\n\n";

  // Perform an API call using the connection to access endpoint
  const auto blockResponse = connection.api.blocks.get("13114381566690093367");
  std::cout << "Response for block '13114381566690093367':\n";
  std::cout << blockResponse << "\n\n";

  const auto delegateResponse = connection.api.delegates.get("boldninja");
  std::cout << "Response for delegate 'boldninja':\n";
  std::cout << delegateResponse << "\n\n";

  const auto nodeConfiguration = connection.api.node.configuration();
  std::cout << "Response for configuration of node '167.114.29.54:4003':\n";
  std::cout << nodeConfiguration << "\n\n";

  const auto peer = connection.api.peers.get("167.114.29.49");
  std::cout << "Response for peer '167.114.29.49':\n";
  std::cout << peer << "\n\n";

  const auto transaction = connection.api.transactions.get("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850");
  std::cout << "Response for transaction 'b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850':\n";
  std::cout << transaction << "\n\n";

  const auto vote = connection.api.votes.get("d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");
  std::cout << "Response for votes 'd202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2':\n";
  std::cout << vote << "\n\n";

  const auto walletsSearch = connection.api.wallets.search({ "username", "baldninja" });
  std::cout << "Response for wallet search 'username=baldninja':\n";
  std::cout << walletsSearch << std::endl;

  return 0;
}
