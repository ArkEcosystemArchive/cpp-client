/**
 * This file is part of Ark Cpp Client.
 *
 * (c) Ark Ecosystem <info@ark.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 **/

#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <cstring>

/**/
/**/

#if (defined ARDUINO || defined ESP8266 || defined ESP32)

#define USE_IOT

/**/

#include <Arduino.h>
#include <pgmspace.h>

/**/
// undef the C macros to allow the C++ STL to take over
// This is to have compatibility with various board implementations of the STL
#undef min
#undef max
/**/

    /**/
    template <typename T>
    std::string toString(T val) {
        return String(val).c_str();
    };
    /**/
    const static inline std::string toString(uint64_t input)
    {
        std::string result;
        uint8_t base = 10;
        do {
            char c = input % base;
            input /= base;
            (c < 10) ? c += '0' : c += 'A' - 10;
            result = c + result;
        } while (input);
        return result;
    }
    /**/
#else
    /**/
    template <typename T>
    std::string toString(T val) {
        return std::to_string(val);
    }
    /**/
#endif

#endif
