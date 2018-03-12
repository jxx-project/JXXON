# JXXON - A C++ JSON object mapper library

Serialze C++ object hierarchies into JSON documents and vice versa almost as conveniently as Java objects using [Jackson](https://github.com/FasterXML/jackson-databind).

 * [Home](https://github.com/jxx-project/JXXON/wiki)
 * [How to build](https://github.com/jxx-project/JXXON/wiki/How-to-build)
 * [How to use](https://github.com/jxx-project/JXXON/wiki/How-to-use)

## Dependencies

JXXON code is focussing on object mapping. Processing of JSON documents is delegated to either [JsonCpp](https://github.com/open-source-parsers/jsoncpp) or [Poco](https://pocoproject.org), depending on your choice when building the JXXON library:

 * **either** Poco >= 1.6.0
 * **or** JsonCpp >= 1.7.4

## License

Free Software, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).
