# JXXON - A C++ JSON object mapper library

Serialze C++ object hierarchies into JSON documents and vice versa almost as conveniently as Java objects using [Jackson](https://github.com/FasterXML/jackson-databind).

## Overview

Java has a reflection API, allowing frameworks like Jackson to automatically navigate class member names and types for mapping. C++ hasn't. Java has annotations allowing to control an object mapper's behaviour. C++ hasn't. Java is said to have no pointers. But *all* object references can be *null*, nicely mapping to JSON null values. C++ has kind of these, too, but you need to use them explicitly. Java has a garbage collector. C++ has destructors and smart pointers, not always inferior.

It's obvious you can't provide anything as automated and transparent for C++ as Jackson, which can make sense of any POJO (Plain Old Java Object) on its own. JXXON attempts to come close, however, allowing object mapping with a minimum amount of clutter, and allowing serializable classes to still look like C++ classes. 

In conjunction with [JXXRS](https://github.com/jxx-project/JXXRS) it helps building JSON REST clients with C++ almost es easily as with JAX-RS and Jackson.

## How to use

All classes to be used with JXXON must

 * publically inherit from JXXON::Serializable and implement its virtual member `toJson()` and
 * provide a constructor accepting a `const JXXON::Json&` argument and
 * provide a default constructor (can be omitted when class is only referred via std::shared_ptr in other serializable classes) and
 * declare all members to be (de)serialized either directly, or as `std::shared_ptr<T>`.

### Supported basic data types

 * `std::string`
 * `int`
 * `unsigned int`
 * `std::int64_t`
 * `std::uint64_t`
 * `std::intmax_t`
 * `std::uintmax_t`
 * `float`
 * `double`
 * `bool`

### Examples

```
#include "JXXON/Serializable.hpp"
#include <string>

struct SampleObject : public JXXON::Serializable {

	// Deserializing constructor
	SampleObject(const JXXON::Json &json) :
		stringProp(json.get<std::string>("string_prop_name")),
		unsignedIntProp(json.get<unsigned int>("unsigned_int_prop_name")),
		boolProp(json.get<bool>("bool_prop_name")) {
	}

	// Serializing virtual function
	virtual JXXON::Json toJson() const override {
		JXXON::Json json;
		json.set("string_prop_name", stringProp);
		json.set("unsigned_int_prop_name", unsignedIntProp);
		json.set("bool_prop_name", boolProp);
		return json;
	}

	// Corresponding members all nullable
	std::string stringProp;
	unsigned int unsignedIntProp;
	bool boolProp;

};
```

Sure: that is substantially more boilerplate code than an annotated class would be. But the pattern is simple and stupid enough to remain readable. And it doesn't even look too hard to be autogenerated from JSON schema input.

Objects may of course be nested:

```
struct Outer : public JXXON::Serializable {

	Outer(const JXXON::Json &json) :
		innerObject(json.get<SampleObject>("inner_object_prop_name")) {
	}

	virtual JXXON::Json toJson() const override {
		JXXON::Json json;
		json.set("inner_object_prop_name", innerObject);
		return json;
	}

	SampleObject innerObject;

};
```

### Arrays and maps

JXXON provides container template classes derived from most commonly used STL containers. While the base classes are doing the container work, JXXON derivates are adding the ingredients from [How to use](#How-to-use).

JXXON container          | Base class
-------------------------|--------------------------------------------------------
`JXXON::Vector<T>`       | `std::vector<T>>`
`JXXON::List<T>`         | `std::list<T>`
`JXXON::Map<T>`          | `std::map<std::string, T>`
`JXXON::UnorderedMap<T>` | `std::unordered_map<std::string, T>`

These JXXON container derivates are adding only behaviour, but no data. They should therefore be safe to destroy via base class pointers or references, despite lacking virtual destructors, as their base classes do.

JXXON containers can be used as member types of objects, or directly as top level serializable data types. Type `T` can be any from [supported basic data types](#supported-basic-data-types), as well as serializable types like objects or other JXXON containers.

### How to use `JXXON::Json` objects

 * Read from `std::istream`, using operator `>>`.
 * Write to `std::ostream`, using operator `<<`.
 * Convert to `std::string` using meber function `toString()`.
 * Construct from `std::string` argument.
 * Use to construct `JXXON::Serializable` objects.
 
## Dependencies

JXXON code is focussing on object mapping. Processing of JSON documents is delegated to either [JsonCpp](https://github.com/open-source-parsers/jsoncpp) or [Poco](https://pocoproject.org), depending on your choice when building the JXXON library:

 * **either** Poco >= 1.6.0
 * **or** JsonCpp >= 1.7.4

## How to build

Building the JXXON library requires **CMake** >= 3.0.0 and the **Boost unit_test_framework**.

Building a static library is as of now tested with g++ on Linux x86_64 only. In the long run it's *supposed* to be portable to any standard conformant C++11 environment also supported by Poco.

Inside the project root directory run

```
make clean
./configure --jxxon-impl=jsoncpp
make
make install
```

to build the JXXON JsonCpp implementation, or

```
./configure --jxxon-impl=poco
make
make install
```

to build the JXXON Poco implementation. Use the environment variable `Poco_DIR`, if you want to use a Poco installation in a non-default location, e.g.

```
Poco_DIR=/path-to-poco ./configure --jxxon-impl=poco
``` 

## License

Free Software, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).

## Why is it named "JXXON"?

Phonetical overlay of "CXX", the make utility macro for C++, and "Jackson".
