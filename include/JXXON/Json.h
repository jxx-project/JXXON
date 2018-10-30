//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Json_INCLUDED
#define JXXON_Json_INCLUDED

#include <functional>
#include <memory>
#include <string>

/// JXXON root namespace.
namespace JXXON {

namespace Accessor {

template<typename T, typename Enable = void>
class GetProperty;

template<typename T, typename Enable = void>
class SetProperty;

template<typename T, typename Enable = void>
class GetArrayElements;

template<typename T, typename Enable = void>
class SetArrayElements;

template<typename T, typename Enable = void>
class GetMapElements;

template<typename T, typename Enable = void>
class SetMapElements;

} // namespace Accessor

/// Main object mapper class.
///
/// Produced as output of toJson() on serialization.
/// Consumed as constructor parameter for serializable classes on deserilization.
///
/// Example:
///
/// \code
/// struct Sample : public JXXON::Serializable
/// {
///     Sample()
///     {
///     }
///
///     Sample(const JXXON::Json &json) : property(json.get<decltype(property)>("property_name"))
///     {
///     }
///
///     virtual JXXON::Json toJson() const override
///     {
///         JXXON::Json json;
///         json.set("property_name", property);
///         return json;
///     }
///
///     std::string property;
/// };
/// \endcode
class Json
{
public:
	/// Interface implemented by (de)serializable classes. Preferrably use the type alias JXXON::Serializable for implementations.
	class Serializable
	{
	public:
		/// Return Json object.
		virtual Json toJson() const = 0;
		virtual ~Serializable()
		{
		}
	};

	/// Interface implemented by JSON array type containers.
	template<typename T>
	class ArrayType
	{
	public:
		/// Virtual destructor.
		~ArrayType()
		{
		}

		/// Add element to array. Ordered containers like vector or list must append element at the end.
		virtual void addElement(const T& element) = 0;

		/// Iterate through array.
		virtual void forEach(const std::function<void(const T& element)>& f) const = 0;
	};

	/// Extension of Base<T, Args...> implementing JXXON::Serializable. Use alias templates JXXON::Vector, JXXON::Deque,
	/// JXXON::List, JXXON::Set, JXXON::Multiset, JXXON::UnorderedSet, JXXON::UnorderedMultiset for referring actual instantiations.
	template<typename T, template<typename, typename...> class Base, typename... Args>
	class Array : public Base<T, Args...>, public Serializable
	{
	public:
		/// Construct empty array.
		Array()
		{
		}

		/// Construct array of size n of default constructed elements.
		explicit Array(typename Base<T, Args...>::size_type n) : Base<T, Args...>(n)
		{
		}

		/// Construct array of size n of copy of value constructed elements.
		Array(typename Base<T, Args...>::size_type n, const T& value) : Base<T, Args...>(n, value)
		{
		}

		/// Construct array with emplace constructed elements of range [first, last).
		template<typename InputIterator>
		Array(InputIterator first, InputIterator last) : Base<T, Args...>(first, last)
		{
		}

		/// Copy construct array.
		Array(const Array& other) : Base<T, Args...>(other)
		{
		}

		/// Move construct array.
		Array(Array&& other) : Base<T, Args...>(std::move(other))
		{
		}

		/// Initializer list constructor.
		Array(std::initializer_list<T> initializerList) : Base<T, Args...>(initializerList)
		{
		}

		/// Copy construct array from delegate type.
		Array(const typename Base<T, Args...>::DelegateType& other) : Base<T, Args...>(other)
		{
		}

		/// Move construct array from delegate type.
		Array(typename Base<T, Args...>::DelegateType&& other) : Base<T, Args...>(std::move(other))
		{
		}

		/// Construct array from Json object.
		Array(const Json& json)
		{
			this->clear();
			Accessor::GetArrayElements<T> get(json);
			get(*this);
		}

		/// Virtual destructor.
		~Array()
		{
		}

		/// Copy assign array.
		Array& operator=(const Array& other)
		{
			return static_cast<Array&>(Base<T, Args...>::operator=(other));
		}

		/// Move assign array.
		Array& operator=(Array&& other)
		{
			return static_cast<Array&>(Base<T, Args...>::operator=(std::move(other)));
		}

		/// Initializer list assignment.
		Array& operator=(std::initializer_list<T> initializerList)
		{
			return static_cast<Array&>(Base<T, Args...>::operator=(initializerList));
		}

		/// Copy assign delegate type array.
		Array& operator=(const typename Base<T, Args...>::DelegateType& other)
		{
			return static_cast<Array&>(Base<T, Args...>::operator=(other));
		}

		/// Move assign delegate type array.
		Array& operator=(typename Base<T, Args...>::DelegateType&& other)
		{
			return static_cast<Array&>(Base<T, Args...>::operator=(std::move(other)));
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetArrayElements<T> set(json);
			set(*this);
			return json;
		}
	};

	/// Interface implemented by JSON map type containers.
	template<typename T>
	class MapType
	{
	public:
		/// Virtual destructor.
		~MapType()
		{
		}

		/// Add element to map.
		virtual void addElement(const std::string& key, const T& value) = 0;

		/// Iterate through map.
		virtual void forEach(const std::function<void(const std::string& key, const T& value)>& f) const = 0;
	};

	/// Extension of Base<T, Args...> implementing JXXON::Serializable. Use alias templates JXXON::Map and JXXON::UnorderedMap for
	/// referring actual instantiations.
	template<typename T, template<typename, typename...> class Base, typename... Args>
	class Map : public Base<T, Args...>, public Serializable
	{
	public:
		/// Construct empty map
		Map()
		{
		}

		/// Construct map with emplace constructed elements of range [first, last).
		template<typename InputIterator>
		Map(InputIterator first, InputIterator last) : Base<T, Args...>(first, last)
		{
		}

		/// Copy construct map.
		Map(const Map& other) : Base<T, Args...>(other)
		{
		}

		/// Move construct map.
		Map(Map&& other) : Base<T, Args...>(std::move(other))
		{
		}

		/// Initializer list constructor.
		Map(std::initializer_list<std::pair<const std::string, T>> initializerList) : Base<T, Args...>(initializerList)
		{
		}

		/// Copy construct map from delegate type.
		Map(const typename Base<T, Args...>::DelegateType& other) : Base<T, Args...>(other)
		{
		}

		/// Move construct map from delegate type.
		Map(typename Base<T, Args...>::DelegateType&& other) : Base<T, Args...>(std::move(other))
		{
		}

		/// Construct map from Json object.
		Map(const Json& json)
		{
			this->clear();
			Accessor::GetMapElements<T> get(json);
			get(*this);
		}

		/// Virtual destructor.
		~Map()
		{
		}

		/// Copy assign map.
		Map& operator=(const Map& other)
		{
			return static_cast<Map&>(Base<T, Args...>::operator=(other));
		}

		/// Move assign map.
		Map& operator=(Map&& other)
		{
			return static_cast<Map&>(Base<T, Args...>::operator=(std::move(other)));
		}

		/// Initializer list assignment.
		Map& operator=(std::initializer_list<std::pair<const std::string, T>> initializerList)
		{
			return static_cast<Map&>(Base<T, Args...>::operator=(initializerList));
		}

		/// Copy assign delegate type map.
		Map& operator=(const typename Base<T, Args...>::DelegateType& other)
		{
			return static_cast<Map&>(Base<T, Args...>::operator=(other));
		}

		/// Move assign delegate type map.
		Map& operator=(typename Base<T, Args...>::DelegateType&& other)
		{
			return static_cast<Map&>(Base<T, Args...>::operator=(std::move(other)));
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetMapElements<T> set(json);
			set(*this);
			return json;
		}
	};

	/// Default constructor. Creates a Json object representing the null value.
	Json();

	Json(const Json& other) = delete;
	Json& operator=(const Json& other) = delete;

	/// Move constructor.
	Json(Json&& other);

	/// Constructor parsing Json value from string document.
	Json(const std::string& document);

	/// Move assignment operator.
	Json& operator=(Json&& other);

	~Json();

	/// Return true if object is representing a null value.
	bool isNull() const;

	/// Return Json value as string.
	std::string toString() const;

	/// Return property of type T with name from Json object.
	template<typename T>
	T get(const std::string& name) const
	{
		return Accessor::GetProperty<T>(*this, name)();
	}

	/// Set property of type T with name in Json object.
	template<typename T>
	void set(const std::string& name, const T& value)
	{
		Accessor::SetProperty<T>(*this, name)(value);
	}

	template<typename T, typename Enable>
	friend class Accessor::GetProperty;

	template<typename T, typename Enable>
	friend class Accessor::SetProperty;

	template<typename T, typename Enable>
	friend class Accessor::GetArrayElements;

	template<typename T, typename Enable>
	friend class Accessor::SetArrayElements;

	template<typename T, typename Enable>
	friend class Accessor::GetMapElements;

	template<typename T, typename Enable>
	friend class Accessor::SetMapElements;

	/// Stream operator overload reading Json objects.
	friend std::istream& operator>>(std::istream& in, Json& json);

	/// Stream operator overload writing Json objects.
	friend std::ostream& operator<<(std::ostream& out, const Json& json);

private:
	class Impl;
	std::unique_ptr<Impl> pimpl;

	Json(std::unique_ptr<Impl>&& pimpl);

	void setTypeObject();
	Json getChild(const std::string& name) const;
	void setChild(const std::string& name, const Json& child);
	void setTypeArray();
	void append(const Json& element);
	void append(const std::function<void(const Json& element)>& append) const;
	void insert(const std::string& key, const Json& element);
	void insert(const std::function<void(const std::string& key, const Json& element)>& insert) const;
};

namespace Accessor {

template<typename T>
class GetProperty<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	GetProperty(const Json& json, const std::string& name) : json(json), name(name)
	{
	}

	T operator()() const
	{
		auto child(json.getChild(name));
		return child.isNull() ? T() : T(child);
	}

private:
	const Json& json;
	const std::string& name;
};

template<typename T>
class GetProperty<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetProperty(const Json& json, const std::string& name) : json(json), name(name)
	{
	}

	T operator()() const
	{
		auto child(json.getChild(name));
		return child.isNull() ? T() : std::make_shared<typename T::element_type>(child);
	}

private:
	const Json& json;
	const std::string& name;
};

template<typename T>
class SetProperty<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	SetProperty(Json& json, const std::string& name) : json(json), name(name)
	{
		json.setTypeObject();
	}

	void operator()(const T& value)
	{
		json.setChild(name, value.toJson());
	}

private:
	Json& json;
	const std::string& name;
};

template<typename T>
class SetProperty<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetProperty(Json& json, const std::string& name) : json(json), name(name)
	{
		json.setTypeObject();
	}

	void operator()(const T& value)
	{
		if (value) {
			json.setChild(name, value->toJson());
		}
	}

private:
	Json& json;
	const std::string& name;
};

template<typename T>
class GetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetProperty(const Json& json, const std::string& name);
	T operator()() const;

private:
	const Json& json;
	const std::string& name;
};

template<typename T>
class SetProperty<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetProperty(Json& json, const std::string& name);
	void operator()(const T& value);

private:
	Json& json;
	const std::string& name;
};

template<typename T>
class GetArrayElements<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::ArrayType<T>& array) const
	{
		json.append([&array](const Json& element) { array.addElement(element.isNull() ? T() : T(element)); });
	}

private:
	const Json& json;
};

template<typename T>
class GetArrayElements<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::ArrayType<T>& array) const
	{
		json.append([&array](const Json& element) {
			array.addElement(element.isNull() ? T() : std::make_shared<typename T::element_type>(element));
		});
	}

private:
	const Json& json;
};

template<typename T>
class SetArrayElements<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Json::ArrayType<T>& array)
	{
		array.forEach([&](const T& element) { json.append(element.toJson()); });
	}

private:
	Json& json;
};

template<typename T>
class SetArrayElements<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Json::ArrayType<T>& array)
	{
		array.forEach([&](const T& element) { json.append(element ? element->toJson() : Json()); });
	}

private:
	Json& json;
};

template<typename T>
class GetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetArrayElements(const Json& json);
	void operator()(Json::ArrayType<T>& array) const;

private:
	const Json& json;
};

template<typename T>
class SetArrayElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetArrayElements(Json& json);
	void operator()(const Json::ArrayType<T>& array);

private:
	Json& json;
};

template<typename T>
class GetMapElements<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::MapType<T>& map) const
	{
		json.insert(
			[&map](const std::string& key, const Json& element) { map.addElement(key, element.isNull() ? T() : T(element)); });
	}

private:
	const Json& json;
};

template<typename T>
class GetMapElements<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::MapType<T>& map) const
	{
		json.insert([&map](const std::string& key, const Json& element) {
			map.addElement(key, element.isNull() ? T() : std::make_shared<typename T::element_type>(element));
		});
	}

private:
	const Json& json;
};

template<typename T>
class SetMapElements<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Json::MapType<T>& map)
	{
		map.forEach([&](const std::string& key, const T& value) { json.insert(key, value.toJson()); });
	}

private:
	Json& json;
};

template<typename T>
class SetMapElements<T, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Json::MapType<T>& map)
	{
		map.forEach([&](const std::string& key, const T& value) { json.insert(key, value ? value->toJson() : Json()); });
	}

private:
	Json& json;
};

template<typename T>
class GetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetMapElements(const Json& json);
	void operator()(Json::MapType<T>& map) const;

private:
	const Json& json;
};

template<typename T>
class SetMapElements<
	T,
	typename std::enable_if<
		!std::is_base_of<Json::Serializable, T>::value &&
		!std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetMapElements(Json& json);
	void operator()(const Json::MapType<T>& map);

private:
	Json& json;
};

} // namespace Accessor

} // namespace JXXON

#endif // JXXON_Json_INCLUDED */
