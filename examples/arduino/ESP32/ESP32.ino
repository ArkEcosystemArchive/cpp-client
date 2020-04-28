/**
 * This file is part of ARK Cpp Client.
 *
 * (c) ARK Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

/**
 * ESP32 Cpp-Client Usage Example Sketch
 *
 * This sketch covers how to use the Cpp-Client API.
 * It allows your ESP32 to send requests to an ARK Node
 */

 /**
 * NOTE: At the time of this writing, the Cpp-Client library requires running the 'ARDUINO_IDE.sh' bash script located in the 'extras' folder.
 * This converts our library to be compatible with the Arduino IDE.
 */

/****************************************/

/**
 * This is where you include the 'arkClient.h' header.
 * This allows your project to use ARK Cpp-Client.
 */
#include <arkClient.h>
/**/

/****************************************/

/**
 * This is where you include WiFi header for your board.
 * This example is for the ESP32, and includes the 'WiFi.h' header.
 */
#include <WiFi.h>
/**/

/****************************************/

/* This is the WiFi network you'd like your board to connect to. */
const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";
/**/

/****************************************/

/** 
 *  This is the IP address of an ARK Node
 *  Specifically, this is a Devnet Node IP
 *  You can find more peers here: https://github.com/ArkEcosystem/peers
 *  
 * The API port for ARK Explorer: '8443'
 * - https://dexplorer.ark.io:8443
 *
 * The Public API port for the ARK network via IP Address is '4003'
 * - 167.114.29.55:4003
 */
const char* peer = "https://dexplorer.ark.io";
int port = 8443;
/**/

/****************************************/

/**
 * This is how you define a connection while speficying the API class as a 'template argument'
 * You instantiate a connection by passing a IP address as a 'c_string', and the port as an 'int'.
 */
Ark::Client::Connection<Ark::Client::Api> connection(peer, port);
/**/

/****************************************/

void checkAPI() {
  // With this API endpoint, you can find ARK Blockchain info.
  // This is equivalent to calling 'https://dexplorer.ark.io/api//blockchain'
  //
  // {
  //     "data": {
  //         "block": {
  //             "height": 2922163,
  //             "id": "84125ec94ba3f3a2d6fd6643d50c98ed2f3c8fa62d8c939355974f404e9b3906"
  //         },
  //         "supply": "13082272800000000"
  //     }
  // }
  const auto blockchainResponse = connection.api.blockchain.get();
  Serial.print("\nBlockchain Response: ");
  Serial.println(blockchainResponse.c_str()); 

  /********************/

  // Here you can call a list of 'All' 'Blocks' on the network.
  // The '1' and '1' refer to the pagination (e.g. response limit and what page)
  //
  // This is equivalent to calling 'https://dexplorer.ark.io/api/blocks?limit=1&page=1'
  //
  // The response should be a json-formatted object
  // The "pretty print" version would look something like this:
  //
  // {
  //     "meta": {
  //         "totalCountIsEstimate": false,
  //         "count": 1,
  //         "pageCount": 2918749,
  //         "totalCount": 2918749,
  //         "next": "/api/blocks?limit=1&page=2&transform=true",
  //         "previous": null,
  //         "self": "/api/blocks?limit=1&page=1&transform=true",
  //         "first": "/api/blocks?limit=1&page=1&transform=true",
  //         "last": "/api/blocks?limit=1&page=2918749&transform=true"
  //     },
  //     "data": [
  //         {
  //             "id": "804da254073cad1c2386acbd3c3365c7532cd44ed43f9a4ad6b47541e4a62a2e",
  //             "version": 0,
  //             "height": 2918749,
  //             "previous": "38b9b9fbf9cf8891e1b4f94c73c122199c8871c447bb59ab7c07fe0cedc75ea6",
  //             "forged": {
  //                 "reward": "200000000",
  //                 "fee": "0",
  //                 "total": "200000000",
  //                 "amount": "0"
  //             },
  //             "payload": {
  //                 "hash": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
  //                 "length": 0
  //             },
  //             "generator": {
  //                 "username": "zillion",
  //                 "address": "DFWTC6qyGgWPFp3NvWtmtvZV1mKF9ASVMk",
  //                 "publicKey": "0366da7ed85cc1e73a13fafb8007d2609d92239355847343cc7b12d85a65d25502"
  //             },
  //             "signature": "3045022100c7965c32f881fd6f4f691e9e479c8768a7ba13679cf449ae78174906431154ce02202ad413d16ce61ca19ef795dad431670ac2392b8980bfe5fc6e802a34e741c940",
  //             "confirmations": 0,
  //             "transactions": 0,
  //             "timestamp": {
  //                 "epoch": 72725376,
  //                 "unix": 1562826576,
  //                 "human": "2019-07-11T06:29:36.000Z"
  //             }
  //         }
  //     ]
  //   }
  const auto blocksResponse = connection.api.blocks.all("?limit=1&page=1");
  Serial.print("\nBlocks Response: ");
  // The response is a 'std::string'; to 'Print' on Arduino, we need the c_string type.
  Serial.println(blocksResponse.c_str());

  /********************/

  // The following method can be used to search for a speficit Delegate.
  //
  // This is equivalent to calling 'https://dexplorer.ark.io/api/delegates/boldninja'
  //
  // {
  //     "data": {
  //         "username": "munich",
  //         "address": "DKfEF2sykKCZzom3vFg1dp9D2kisB8hM2Q",
  //         "publicKey": "036a520acf24036ff691a4f8ba19514828e9b5aa36ca4ba0452e9012023caccfef",
  //         "votes": "30756514325531",
  //         "rank": 8,
  //         "blocks": {
  //             "produced": 39154,
  //             "last": {
  //                 "id": "9ece2a535ad471766c4bd5b6d0e8f342301b7f744a1ec200ddbc150da0d8c669",
  //                 "height": 2919031,
  //                 "timestamp": {
  //                     "epoch": 72727632,
  //                     "unix": 1562828832,
  //                     "human": "2019-07-11T07:07:12.000Z"
  //                 }
  //             }
  //         },
  //         "production": {
  //             "approval": 0.25
  //         },
  //         "forged": {
  //             "fees": "5933484566",
  //             "rewards": "7830800000000",
  //             "total": "7836733484566"
  //         }
  //     }
  // }
  const auto delegateResponse = connection.api.delegates.get("munich");
    Serial.print("\nDelegate Response: ");
    Serial.println(delegateResponse.c_str());

  /********************/

  // The following method can be used to get the Status of a Node.
  //
  // This is equivalent to calling 'https://dexplorer.ark.io/api/node/status'
  //
  // The response should be a json-formatted object
  // The "pretty print" version would look something like this:
  //
  // {
  //     "data": {
  //         "synced": true,
  //         "now": 2919069,
  //         "blocksCount": -1,
  //         "timestamp": 72727946
  //     }
  // }
  const auto nodeStatus = connection.api.node.status();
  Serial.print("\nNode Status: ");
  Serial.println(nodeStatus.c_str()); 
  /**/

  /********************/

  // The following method can be used to get a list of 'All' 'Peers' on the network.
  //
  // This is equivalent to calling 'https://dexplorer.ark.io/api/peers?limit=1&page=1'
  //
  // {
  //     "meta": {
  //         "count": 1,
  //         "pageCount": 219,
  //         "totalCount": 219,
  //         "next": "/api/peers?limit=1&page=2",
  //         "previous": null,
  //         "self": "/api/peers?limit=1&page=1",
  //         "first": "/api/peers?limit=1&page=1",
  //         "last": "/api/peers?limit=1&page=219"
  //     },
  //     "data": [
  //         {
  //             "ip": "213.32.9.98",
  //             "port": 4002,
  //             "ports": {},
  //             "version": "2.5.0-next.9",
  //             "height": 2919099,
  //             "latency": 9
  //         }
  //     ]
  // }
  const auto allPeers = connection.api.peers.all("?limit=1&page=1");
  Serial.print("\nAll Peers: ");
  Serial.println(allPeers.c_str());

  /********************/

  // The following method can be used to get a list of 'Transaction' 'Types'.
  //
  // This is equivalent to calling https://dexplorer.ark.io/api/transactions/types'
  //
  // {
  //     "data": {
  //         "Transfer": 0,
  //         "SecondSignature": 1,
  //         "DelegateRegistration": 2,
  //         "Vote": 3,
  //         "MultiSignature": 4,
  //         "Ipfs": 5,
  //         "TimelockTransfer": 6,
  //         "MultiPayment": 7,
  //         "DelegateResignation": 8
  //     }
  // }
  const auto transactionTypes = connection.api.transactions.types();
  Serial.print("\nTransaction Types: ");
  Serial.println(transactionTypes.c_str());

  /********************/

  // This method can be used to get a list of 'Vote' Transactions.
  //
  // This is equivalent to calling 'https://dexplorer.ark.io/api/votes?limit=1&page=1'
  //
  // {
  //     "meta": {
  //         "totalCountIsEstimate": false,
  //         "count": 1,
  //         "pageCount": 15137,
  //         "totalCount": 15137,
  //         "next": "/api/votes?limit=1&page=2&transform=true",
  //         "previous": null,
  //         "self": "/api/votes?limit=1&page=1&transform=true",
  //         "first": "/api/votes?limit=1&page=1&transform=true",
  //         "last": "/api/votes?limit=1&page=15137&transform=true"
  //     },
  //     "data": [
  //         {
  //             "id": "a3b890d25824eba36dfc2a5956590c68101378211dab216ae92c123ab1ba4b67",
  //             "blockId": "9df8800ab375cfda3782b90bb8e14326e029cecfb22742c6a7c3100c7209a30b",
  //             "version": 1,
  //             "type": 3,
  //             "amount": "0",
  //             "fee": "97013913",
  //             "sender": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
  //             "senderPublicKey": "034da006f958beba78ec54443df4a3f52237253f7ae8cbdb17dccf3feaa57f3126",
  //             "recipient": "DTRdbaUW3RQQSL5By4G43JVaeHiqfVp9oh",
  //             "signature": "3045022100b92598f344d3d3d6b0224cfd2058fb35318aac127b8bde529e01fe3868018b610220041cb63436f84bbf93b11c040f9389ebaf8293d63cc685255cea13f48a3f48f6",
  //             "asset": {
  //                 "votes": [
  //                     "+02aea83a44f1d6b073e5bcffb4176bbe3c51dcd0e96a793a88f3a6135600224adf"
  //                 ]
  //             },
  //             "confirmations": 229,
  //             "timestamp": {
  //                 "epoch": 72739207,
  //                 "unix": 1562840407,
  //                 "human": "2019-07-11T10:20:07.000Z"
  //             }
  //         }
  //     ]
  // }
  const auto allVotes = connection.api.votes.all("?limit=1&page=1");
  Serial.print("\nAll Votes: ");
  Serial.println(allVotes.c_str());

  /********************/

  // This method can be used to get a list of 'Top' 'Wallets' (Wallets with the most ARK).
  // 
  // This is equivalent to calling 'https://dexplorer.ark.io/api/wallets/top?limit=1&page=1'
  //
  // The response should be a json-formatted object
  // The "pretty print" version would look something like this:
  //
  // {
  //     "meta": {
  //         "count": 1,
  //         "pageCount": 196457,
  //         "totalCount": 196457,
  //         "next": "/api/wallets?limit=1&page=2",
  //         "previous": null,
  //         "self": "/api/wallets?limit=1&page=1",
  //         "first": "/api/wallets?limit=1&page=1",
  //         "last": "/api/wallets?limit=1&page=196457"
  //     },
  //     "data": [
  //         {
  //             "address": "D6Z26L69gdk9qYmTv5uzk3uGepigtHY4ax",
  //             "publicKey": "03d3fdad9c5b25bf8880e6b519eb3611a5c0b31adebc8455f0e096175b28321aff",
  //             "balance": "9898440219335676",
  //             "isDelegate": false
  //         }
  //     ]
  // }
  const auto topWallets = connection.api.wallets.top("?limit=1&page=1");
  Serial.print("\nTop Wallets: ");
  Serial.println(topWallets.c_str());
};

/****************************************/

void setup() {
  // Begin your Serial Connection.
  // This allows you to monitor your boards output.
  Serial.begin(115200);

  // This starts your boards connection to WiFi.
  WiFi.begin(ssid, password);

  // This will delay until we're connected to WiFi.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  };

  Serial.print("\nConnected, IP address: ");
  Serial.println(WiFi.localIP());

  // Begin API Demo
  checkAPI(); 
};

/****************************************/

// We can leave this empty, we don't want to repeat anything in this example.
void loop() {};
