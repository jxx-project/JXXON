//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
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

template<typename T, template<typename...> class Base, typename Enable = void>
class GetArrayElements;

template<typename T, template<typename...> class Base, typename Enable = void>
class SetArrayElements;

template<typename T, template<typename...> class Base, typename Enable = void>
class GetMapElements;

template<typename T, template<typename...> class Base, typename Enable = void>
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

	/// Extension of Base<T> implementing JXXON::Serializable. Use alias templates JXXON::Vector and JXXON::List for referring actual instantiations.
	template<typename T, template<typename...> class Base>
	class Array : public Base<T>, public Serializable
	{
	public:
		/// Construct empty array.
		Array()
		{
		}

		/// Construct array of size n of default constructed elements.
		explicit Array(typename Base<T>::size_type n) : Base<T>(n)
		{
		}

		/// Construct array of size n of copy of value constructed elements.
		Array(typename Base<T>::size_type n, const T& value) : Base<T>(n, value)
		{
		}

		/// Construct array with emplace constructed elements of range [first, last).
		template<typename InputIterator>
		Array(InputIterator first, InputIterator last) : Base<T>(first, last)
		{
		}

		/// Copy construct array.
		Array(const Base<T>& other) : Base<T>(other)
		{
		}

		/// Move construct array.
		Array(Base<T>&& other) : Base<T>(std::move(other))
		{
		}

		/// Initializer list constructor.
		Array(std::initializer_list<T> initializerList) : Base<T>(initializerList)
		{
		}

		/// Copy construct array from delegate type.
		Array(const typename Base<T>::DelegateType& other) : Base<T>(other)
		{
		}

		/// Move construct array from delegate type.
		Array(typename Base<T>::DelegateType&& other) : Base<T>(std::move(other))
		{
		}

		/// Construct array from Json object.
		Array(const Json& json)
		{
			Accessor::GetArrayElements<T, Base> get(json);
			get(*this);
		}

		/// Virtual destructor.
		~Array()
		{
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetArrayElements<T, Base> set(json);
			set(*this);
			return json;
		}
	};

	/// Extension of Base<T> implementing JXXON::Serializable. Use alias templates JXXON::Map and JXXON::UnorderedMap for referring actual instantiations.
	template<typename T, template<typename...> class Base>
	class Map : public Base<T>, public Serializable
	{
	public:
		/// Construct empty map
		Map()
		{
		}

		/// Construct map with emplace constructed elements of range [first, last).
		template<typename InputIterator>
		Map(InputIterator first, InputIterator last) : Base<T>(first, last)
		{
		}

		/// Copy construct map.
		Map(const Base<T>& other) : Base<T>(other)
		{
		}

		/// Move construct map.
		Map(Base<T>&& other) : Base<T>(std::move(other))
		{
		}

		/// Initializer list constructor.
		Map(std::initializer_list<std::pair<const std::string, T>> initializerList) : Base<T>(initializerList)
		{
		}

		/// Copy construct map from delegate type.
		Map(const typename Base<T>::DelegateType& other) : Base<T>(other)
		{
		}

		/// Move construct map from delegate type.
		Map(typename Base<T>::DelegateType&& other) : Base<T>(std::move(other))
		{
		}

		/// Construct map from Json object.
		Map(const Json& json)
		{
			Accessor::GetMapElements<T, Base> get(json);
			get(*this);
		}

		/// Virtual destructor.
		~Map()
		{
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetMapElements<T, Base> set(json);
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

	template<typename T, template<typename...> class Base, typename Enable>
	friend class Accessor::GetArrayElements;

	template<typename T, template<typename...> class Base, typename Enable>
	friend class Accessor::SetArrayElements;

	template<typename T, template<typename...> class Base, typename Enable>
	friend class Accessor::GetMapElements;

	template<typename T, template<typename...> class Base, typename Enable>
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
class GetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetProperty(const Json& json, const std::string& name);
	T operator()() const;

private:
	const Json& json;
	const std::string& name;

};

template<typename T>
class SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetProperty(Json& json, const std::string& name);
	void operator()(const T& value);

private:
	Json& json;
	const std::string& name;
};

template<typename T, template<typename...> class Base>
class GetArrayElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Base<T>& array) const
	{
		array.clear();
		json.append([&array](const Json& element){array.emplace_back(element.isNull() ? T() : T(element));});
	}

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class GetArrayElements<T, Base, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Base<T>& array) const
	{
		array.clear();
		json.append([&array](const Json& element){array.emplace_back(element.isNull() ? T() : std::make_shared<typename T::element_type>(element));});
	}

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class SetArrayElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Base<T>& array) {
		for (auto& i : array) {
			json.append(i.toJson());
		}
	}

private:
	Json& json;
};

template<typename T, template<typename...> class Base>
class SetArrayElements<T, Base, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Base<T>& array) {
		for (auto& i : array) {
			json.append(i ? i->toJson() : Json());
		}
	}

private:
	Json& json;
};

template<typename T, template<typename...> class Base>
class GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetArrayElements(const Json& json);
	void operator()(Base<T>& array) const;

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetArrayElements(Json& json);
	void operator()(const Base<T>& array);

private:
	Json& json;
};

template<typename T, template<typename...> class Base>
class GetMapElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Base<T>& map) const
	{
		map.clear();
		json.insert([&map](const std::string& key, const Json& element){map.emplace(key, element.isNull() ? T() : T(element));});
	}

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class GetMapElements<T, Base, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Base<T>& map) const
	{
		map.clear();
		json.insert([&map](const std::string& key, const Json& element){map.emplace(key, element.isNull() ? T() : std::make_shared<typename T::element_type>(element));});
	}

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class SetMapElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
public:
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Base<T>& map)
	{
		for (auto& i : map) {
			json.insert(i.first, i.second.toJson());
		}
	}

private:
	Json& json;
};

template<typename T, template<typename...> class Base>
class SetMapElements<T, Base, typename std::enable_if<std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Base<T>& map)
	{
		for (auto& i : map) {
			json.insert(i.first, i.second ? i.second->toJson() : Json());
		}
	}

private:
	Json& json;
};

template<typename T, template<typename...> class Base>
class GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	GetMapElements(const Json& json);
	void operator()(Base<T>& map) const;

private:
	const Json& json;
};

template<typename T, template<typename...> class Base>
class SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible<T, std::shared_ptr<Json::Serializable>>::value>::type>
{
public:
	SetMapElements(Json& json);
	void operator()(const Base<T>& map);

private:
	Json& json;
};

} // namespace Accessor

} // namespace JXXON

#endif // JXXON_Json_INCLUDED */
