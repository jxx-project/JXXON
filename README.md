# JXXON — C++ JSON object mapper library

Serialize C++ object hierarchies into JSON documents and vice versa almost as conveniently as Java objects using [Jackson](https://github.com/FasterXML/jackson-databind).

## Design goals

### Focus on one thing and try do that well

Mapping C++ object hierarchies and containers to JSON documents. There are a couple of C++ JSON parsers/generators out there, mature and proven. I doubt I can write a better one. Instead, JXXON relies on existing ones.

### Full encapsulation

JXXON does not expose any details of the encaplusalated JSON parsers/generators to clients. Neither explicitly, nor via transitive inclusion.

### Polymorphism-friendliness

Provide a common interface base class, which all serializable classes implement.

Lacking such an interface, object mapper consumer classes supposed to handle more than one type would be forced to a non-polymorphic design, using non-virtual template member functions, or using member overloads. In any case, to drop all object oriented runtime flexibility.

### Concise handling of null values

Throwing exceptions, when there is a null value somewhere in JSON input, is probably the least helpful thing to do. Null values are valid JSON, even when they occur as array elements.

### Integrate C++ standard containers as transparently as possible and reasonable.

C++ standard conainers should feel like first class citizens in JSON. Based on a little bit of [wrapping](https://github.com/jxx-project/Polymorphic).

### Thorough testing

Not strictly a design goal, but best practice. A templatized test suite helps boosting code and branch coverage to amazing levels.

## Example

```
#include "JXXON/Serializable.h"
#include <string>

struct SampleObject : public JXXON::Serializable
{
        // Deserializing constructor
        SampleObject(const JXXON::Json &json) :
                property(json.get<std::string>("property_name")),
        {
        }

        // Serializing virtual function
        virtual JXXON::Json toJson() const override
        {
                JXXON::Json json;
                json.set("property_name", property);
                return json;
        }

        // Non-nullable field.
        std::string property;
};
```

## See also

 * [Home](https://github.com/jxx-project/JXXON/wiki)
 * [How to build](https://github.com/jxx-project/JXXON/wiki/How-to-build)
 * [How to use](https://github.com/jxx-project/JXXON/wiki/How-to-use)

## Dependencies

JXXON is using [Polymorphic decorators](https://github.com/jxx-project/Polymorphic) >= 1.0.0 to extend C++11 standard containers and to add serializability.

Processing of JSON documents is delegated to **either** [JsonCpp](https://github.com/open-source-parsers/jsoncpp) >= 1.6.0 **or** [Poco](https://pocoproject.org) >= 1.7.4, depending on your choice when building the JXXON library.

## License

Free Software, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).
