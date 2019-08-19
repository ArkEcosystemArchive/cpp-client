/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#include "helpers/client_helpers.h"

#if (defined PLATFORMIO && !defined UNIT_TEST)

void setup() {}
void loop() {
  delay(1000);
}

#endif
