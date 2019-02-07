# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## Unreleased

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
