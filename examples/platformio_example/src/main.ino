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
  Serial.println();

  const auto delegateResponse = connection.api.delegates.get("boldninja");
  Serial.println("Response for delegate 'boldninja':");
  Serial.println(delegateResponse.c_str());
  Serial.println();

  const auto nodeConfiguration = connection.api.node.configuration();
  Serial.println("Response for configuration of node '167.114.29.54:4003':");
  Serial.println(nodeConfiguration.c_str());
  Serial.println();

  const auto peer = connection.api.peers.get("167.114.29.49");
  Serial.println("Response for peer '167.114.29.49':");
  Serial.println(peer.c_str());
  Serial.println();

  const auto transaction = connection.api.transactions.get("b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850");
  Serial.println("Response for transaction 'b324cea5c5a6c15e6ced3ec9c3135a8022eeadb8169f7ba66c80ebc82b0ac850':");
  Serial.println(transaction.c_str());
  Serial.println();

  const auto vote = connection.api.votes.get("d202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2");
  Serial.println("Response for votes 'd202acbfa947acac53ada2ac8a0eb662c9f75421ede3b10a42759352968b4ed2':");
  Serial.println(vote.c_str());
  Serial.println();

  const auto walletsSearch = connection.api.wallets.search({ "username", "baldninja" });
  Serial.println("Response for wallet search 'username=baldninja':");
  Serial.println(walletsSearch.c_str());

}
