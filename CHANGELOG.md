# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
-   added support for https ([#195])

## [1.4.1] - 2020-03-06

### Added
-   added first and last block methods ([#183])

### Changed
-   improved building as a project dependency ([#176])

## [1.4.0] - 2020-02-13

### Added
-   added Core 2.6 endpoints ([#159])

## [1.3.0] - 2019-10-09

### Added
-   added Blockchain API endpoint ([#104])

### Changed
-   moved external libraries out of source tree ([#140])
-   improved API query usage to accept strings ([#114])
-   improved class members and test coverage ([#93])
-   improved formatting and maintainability ([#92])
-   dropped Hunter Package Manager in favor of git submodules in OS builds ([#90])
-   updated ArduinoJson 5.13.2 >> 6.10.1, usage patterns, and documentation/examples ([#87])

### Fixed
-   fixed typos in Arduino examples ([#86])
-   changed to "statusCode" '422' to test API Post response for empty Transactions objects ([#85])

## [1.2.0] - 2019-02-16

### Added
-   arduino CircleCI config ([#73])

### Changed
-   removed `./src/stl` library ([#78])
-   updated `keywords.txt`. ([#77])
-   updated `ARDUINO_IDE.sh` script to reflect `lib/` changes ([#76])
-   reorganized files and documentation ([#75])
-   automated `ARDUINO_IDE.sh` script ([#72])
-   updated `./library.json` package export settings ([#70])

## [1.1.0] - 2019-02-07

### Added
-   added Arduino Sketch Paths to `library.json` ([#67])
-   added an API `send()` method for the `Transactions` class ([#64])

### Fixed
-   renamed `Helpers` class to avoid naming collision with Cpp-Crypto `Helpers` ([#65])
-   fixed unterminated comment which resulted in skipped `Node` tests ([#63])

## [1.0.0] - 2019-01-19
-   Initial Release

[1.0.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.0.0...master
[#63]: https://github.com/ArkEcosystem/cpp-client/pull/63
[#64]: https://github.com/ArkEcosystem/cpp-client/pull/64
[#65]: https://github.com/ArkEcosystem/cpp-client/pull/65
[#67]: https://github.com/ArkEcosystem/cpp-client/pull/67
[1.1.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.0.0...1.1.0
[#70]: https://github.com/ArkEcosystem/cpp-client/pull/70
[#72]: https://github.com/ArkEcosystem/cpp-client/pull/72
[#73]: https://github.com/ArkEcosystem/cpp-client/pull/73
[#75]: https://github.com/ArkEcosystem/cpp-client/pull/75
[#76]: https://github.com/ArkEcosystem/cpp-client/pull/76
[#77]: https://github.com/ArkEcosystem/cpp-client/pull/77
[#78]: https://github.com/ArkEcosystem/cpp-client/pull/78
[1.2.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.1.0...1.2.0
[#85]: https://github.com/ArkEcosystem/cpp-client/pull/85
[#86]: https://github.com/ArkEcosystem/cpp-client/pull/86
[#87]: https://github.com/ArkEcosystem/cpp-client/pull/87
[#90]: https://github.com/ArkEcosystem/cpp-client/pull/90
[#92]: https://github.com/ArkEcosystem/cpp-client/pull/92
[#93]: https://github.com/ArkEcosystem/cpp-client/pull/93
[#104]: https://github.com/ArkEcosystem/cpp-client/pull/104
[#114]: https://github.com/ArkEcosystem/cpp-client/pull/114
[#140]: https://github.com/ArkEcosystem/cpp-client/pull/140
[1.3.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.2.0...1.3.0
[#159]: https://github.com/ArkEcosystem/cpp-client/pull/159
[1.4.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.3.0...1.4.0
[#176]: https://github.com/ArkEcosystem/cpp-client/pull/176
[#183]: https://github.com/ArkEcosystem/cpp-client/pull/183
[1.4.1]: https://github.com/ArkEcosystem/cpp-client/compare/1.4.0...1.4.1
[#195]: https://github.com/ArkEcosystem/cpp-client/pull/195
[Unreleased]: https://github.com/ArkEcosystem/cpp-client/compare/1.4.1...develop
