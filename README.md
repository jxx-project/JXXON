# JXXON — C++ JSON object mapper library

Serialize C++ object hierarchies into JSON documents and vice versa almost as conveniently as Java objects using [Jackson](https://github.com/FasterXML/jackson-databind).

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

JXXON is using [Polymorphic decorators](https://github.com/jxx-project/Polymorphic) >= 1.0.0 to extend C++11 standard containers and add serializiblity.

JXXON code is focussing on object mapping. Processing of JSON documents is delegated to **either** [JsonCpp](https://github.com/open-source-parsers/jsoncpp) >= 1.6.0 **or** [Poco](https://pocoproject.org) >= 1.7.4, depending on your choice when building the JXXON library.

## License

Free Software, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).
