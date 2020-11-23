
#include "arkClient.h"

#include <arduino.h>

void setup() {
  Serial.begin(115200);

  while (!Serial) { delay(100); };
  // ^for the Arduino Leonardo/Micro only
}

void loop() {
  // Create a connection
  Ark::Client::Connection<Ark::Client::Api> connection("167.114.29.54", 4003);

  // Perform an API call using the connection to access endpoint
  const auto blockchainResponse = connection.api.blockchain.get();
  Serial.print("\nResponse for blockchain:");
  Serial.println(blockchainResponse.c_str());

  const auto blockResponse = connection.api.blocks.get("13114381566690093367");
  Serial.println("Response for block '13114381566690093367':");
  Serial.println(blockResponse.c_str());

  const auto delegateResponse = connection.api.delegates.get("genesis_1");
  Serial.println("\nResponse for delegate 'genesis_1':");
  Serial.println(delegateResponse.c_str());

  const auto entitiesResponse = connection.api.entities.get("89d4afb16f4c30554ef0dfdc500e6e6b2df949f56374e3fdc09c2ebe9504e2a2");
  Serial.println("\nResponse for entity '89d4afb16f4c30554ef0dfdc500e6e6b2df949f56374e3fdc09c2ebe9504e2a2':");
  Serial.println(entitiesResponse.c_str());

  const auto nodeConfiguration = connection.api.node.configuration();
  Serial.println("\nResponse for configuration of node '167.114.29.54:4003':");
  Serial.println(nodeConfiguration.c_str());

  const auto peer = connection.api.peers.get("167.114.29.49");
  Serial.println("\nResponse for peer '167.114.29.49':");
  Serial.println(peer.c_str());

  const auto transaction = connection.api.transactions.get(
      "ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4");
  Serial.println("\nResponse for transaction 'ed46b70a5fad2957c09aa0e0d02b7a2e3e4ab93f0581d1a871e0c44907a4f3e4':");
  Serial.println(transaction.c_str());

  const auto vote = connection.api.votes.get(
      "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67");
  Serial.println("\nResponse for votes 'a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67':");
  Serial.println(vote.c_str());

  const auto walletsGet = connection.api.wallets.get("genesis_1");
  Serial.println("\nResponse for wallet 'genesis_1'::");
  Serial.println(walletsGet.c_str());
}
