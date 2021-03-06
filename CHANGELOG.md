# Changelog

## Unreleased
### Added
- Support std::int8_t, std::uint8_t, std::int16_t, std::uint16_t, std::int32_t, std::uint32_t.
- Container assignment operators.

### Changed
- Removed dead end fill constructors from Map and UnorderedMap.

## 1.1.0 — 2018-04-19
### Added
- CMake target version.
- Transitive CMake dependency resolution based on CONFIG lookup.
- CHANGELOG.md.

### Changed
- CMake target renamed from "jxxon" to "JXXON::ObjectMapper".
- Refactoring aimed to reduce build time and to enable more container types:
   - Internal container interfaces to de-couple object mapper implementation and instantiation from container type.
   - Related internal container base implementations.

### Removed
- CMake modules.

## 1.0.0 — 2018-04-01
### Added
- Json object mapper:
   - Poco implementation.
   - JsonCpp implementation.
- Serializable interface.
- Nullable and non-nullable properties.
- Container types Vector, List, Map, UnorderedMap.
- CMake target import files.
- Templatized test suite.
