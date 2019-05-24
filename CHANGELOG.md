# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## Unreleased

### Changed

- improved test coverage ([#93])
- improved formatting and maintainability ([#92])
- dropped Hunter Package Manager in favor of git submodules in OS builds. ([#90])
- updated ArduinoJson 5.13.2 >> 6.10.1, usage patterns, and documentation/examples. ([#87])

### Fixed

- fixed typos in Arduino examples ([#86])
- changed to "statusCode" '422' to test API Post response for empty Transactions objects. ([#85])

## [1.2.0] - 2019-02-16
## [1.2.0-arduino] - 2019-02-16

### Added

- Arduino CircleCI config ([#73])

### Changed

- updated `keywords.txt`. ([#77])
- updated `./library.json` package export settings. ([#70])
- removed unnecessary files: ([#75])
  - `./appveyor.yml`.
  - `./CMakeSettings.json`.
  - submodule from `cmake_example`.
- removed `./src/stl` library. ([#78])
- moved `./docs` to `./extras` in arduino builds. ([#75])
- automated `ARDUINO_IDE.sh` script. ([#72])
- updated `ARDUINO_IDE.sh` script to reflect `lib/` changes. ([#76])

## [1.1.0] - 2019-02-07

### Added

- Added an API `send()` method for the `Transactions` class ([#64])
- Added Arduino Sketch Paths to `library.json` ([#67])

### Fixed

- Fixed unterminated comment which resulted in skipped `Node` tests ([#63])
- Renamed `Helpers` class to avoid naming collision with Cpp-Crypto `Helpers` ([#65])

## 1.0.0 - 2019-01-19

- Initial Release

[unreleased]: https://github.com/ArkEcosystem/cpp-client/compare/1.1.0...develop
[1.1.0]: https://github.com/ArkEcosystem/cpp-client/compare/1.0.0...1.1.0
[#64]: https://github.com/ArkEcosystem/cpp-client/pull/64
[#67]: https://github.com/ArkEcosystem/cpp-client/pull/67
[#63]: https://github.com/ArkEcosystem/cpp-client/pull/63
[#65]: https://github.com/ArkEcosystem/cpp-client/pull/65
