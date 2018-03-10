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

namespace JXXON {
namespace Accessor {
	
template<typename T, typename Enable = void>
struct GetProperty;
  
template<typename T, typename Enable = void>
struct SetProperty;

template<typename T, template<typename...> class Base, typename Enable = void>
struct GetArrayElements;
  
template<typename T, template<typename...> class Base, typename Enable = void>
struct SetArrayElements;

template<typename T, template<typename...> class Base, typename Enable = void>
struct GetMapElements;
  
template<typename T, template<typename...> class Base, typename Enable = void>
struct SetMapElements;
	
} // namespace Accessor

struct Json
{
	struct Serializable
	{
		virtual Json toJson() const = 0;
		virtual ~Serializable() {}
	};

	template < typename T, template<typename...> class Base >
	using ArrayBase = Base<T>;

	template< typename T, template<typename...> class Base >
	struct Array : public ArrayBase<T, Base>, public Serializable
	{
		Array()
		{
		}

		Array(const Json& json)
		{
			Accessor::GetArrayElements<T, Base> get(json);
			get(*this);
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetArrayElements<T, Base> set(json);
			set(*this);
			return json;
		}
	};
  
	template <typename T, template<typename...> class Base >
	using MapBase = Base<std::string, T>;

	template <typename T, template<typename...> class Base >
	struct Map : public MapBase<T, Base>, public Serializable
	{
		Map()
		{
		}

		Map(const Json& json)
		{
			Accessor::GetMapElements<T, Base> get(json);
			get(*this);
		}

		virtual Json toJson() const override
		{
			JXXON::Json json;
			Accessor::SetMapElements<T, Base> set(json);
			set(*this);
			return json;
		}
	};
  
	Json();
	Json(const Json& other) = delete;
	Json(Json&& other);
	Json(const std::string& document);
	Json& operator=(const Json& other) = delete;
	Json& operator=(Json&& other);
	~Json();
	
	bool isNull() const;
	std::string toString() const;

	template<typename T>
	T get(const std::string& name) const
	{
		return Accessor::GetProperty<T>(*this, name)();
	}

	template<typename T>
	void set(const std::string& name, const T& value)
	{
		Accessor::SetProperty<T>(*this, name)(value);
	}

	template<typename T, typename Enable>
	friend struct Accessor::GetProperty;
	
	template<typename T, typename Enable>
	friend struct Accessor::SetProperty;
	
	template<typename T, template<typename...> class Base, typename Enable>
	friend struct Accessor::GetArrayElements;
	
	template<typename T, template<typename...> class Base, typename Enable>
	friend struct Accessor::SetArrayElements;
	
	template<typename T, template<typename...> class Base, typename Enable>
	friend struct Accessor::GetMapElements;
	
	template<typename T, template<typename...> class Base, typename Enable>
	friend struct Accessor::SetMapElements;
	
	friend std::istream& operator>>(std::istream& in, Json& json);
	friend std::ostream& operator<<(std::ostream& out, const Json& json);

private:
	
	struct Impl;
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
struct GetProperty<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
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
struct GetProperty<T, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
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
struct SetProperty<T, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
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
struct SetProperty<T, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
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
struct GetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
		
	GetProperty(const Json& json, const std::string& name);
	T operator()() const;

private:
	  
	const Json& json;
	const std::string& name;

};

template<typename T>
struct SetProperty<T, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	SetProperty(Json& json, const std::string& name);
	void operator()(const T& value);

private:
	  
	Json& json;
	const std::string& name;
};
		
template<typename T, template<typename...> class Base>
struct GetArrayElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::ArrayBase<T, Base>& array) const
	{
		array.clear();
		json.append([&array](const Json& element){array.emplace_back(element.isNull() ? T() : T(element));});
	}

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct GetArrayElements<T, Base, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	GetArrayElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::ArrayBase<T, Base>& array) const
	{
		array.clear();
		json.append([&array](const Json& element){array.emplace_back(element.isNull() ? T() : std::make_shared<typename T::element_type>(element));});
	}

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct SetArrayElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Json::ArrayBase<T, Base>& array) {
		for (typename Json::ArrayBase<T, Base>::const_iterator i = array.begin(); i != array.end(); i++)
			{
			json.append(i->toJson());
		}
	}

private:
		
	Json& json;
};

template<typename T, template<typename...> class Base>
struct SetArrayElements<T, Base, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	SetArrayElements(Json& json) : json(json)
	{
		json.setTypeArray();
	}

	void operator()(const Json::ArrayBase<T, Base>& array) {
		for (typename Json::ArrayBase<T, Base>::const_iterator i = array.begin(); i != array.end(); i++)
			{
			json.append(*i ? (*i)->toJson() : Json());
		}
	}

private:
		
	Json& json;
};

template<typename T, template<typename...> class Base>
struct GetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	GetArrayElements(const Json& json);
	void operator()(Json::ArrayBase<T, Base>& array) const;

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct SetArrayElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	SetArrayElements(Json& json);
	void operator()(const Json::ArrayBase<T, Base>& array);

private:
	  
	Json& json;
};

template<typename T, template<typename...> class Base>
struct GetMapElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::MapBase<T, Base>& map) const
	{
		map.clear();
		json.insert([&map](const std::string& key, const Json& element){map.emplace(key, element.isNull() ? T() : T(element));});
	}

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct GetMapElements<T, Base, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	GetMapElements(const Json& json) : json(json)
	{
	}

	void operator()(Json::MapBase<T, Base>& map) const
	{
		map.clear();
		json.insert([&map](const std::string& key, const Json& element){map.emplace(key, element.isNull() ? T() : std::make_shared<typename T::element_type>(element));});
	}

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct SetMapElements<T, Base, typename std::enable_if<std::is_base_of<Json::Serializable, T>::value>::type>
{
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Json::MapBase<T, Base>& map)
	{
		for (typename Json::MapBase<T, Base>::const_iterator i = map.begin(); i != map.end(); i++) {
			json.insert(i->first, i->second.toJson());
		}
	}

private:
		
	Json& json;
};

template<typename T, template<typename...> class Base>
struct SetMapElements<T, Base, typename std::enable_if<std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	SetMapElements(Json& json) : json(json)
	{
		json.setTypeObject();
	}

	void operator()(const Json::MapBase<T, Base>& map)
	{
		for (typename Json::MapBase<T, Base>::const_iterator i = map.begin(); i != map.end(); i++) {
			json.insert(i->first, i->second ? i->second->toJson() : Json());
		}
	}

private:
		
	Json& json;
};

template<typename T, template<typename...> class Base>
struct GetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	GetMapElements(const Json& json);
	void operator()(Json::MapBase<T, Base>& map) const;

private:
	  
	const Json& json;
};

template<typename T, template<typename...> class Base>
struct SetMapElements<T, Base, typename std::enable_if<!std::is_base_of<Json::Serializable, T>::value && !std::is_convertible< T, std::shared_ptr<Json::Serializable> >::value>::type>
{
	SetMapElements(Json& json);
	void operator()(const Json::MapBase<T, Base>& map);

private:
	  
	Json& json;
};

} // namespace Accessor
} // namespace JXXON

#endif // JXXON_Json_INCLUDED */
