//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_UnorderedMap_INCLUDED
#define JXXON_Base_UnorderedMap_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::UnorderedMap<std::string, T> implementing JXXON::Json::MapType<T>.
template<class T>
class UnorderedMap : public Polymorphic::UnorderedMap<std::string, T>, public JXXON::Json::MapType<T>
{
public:
	/// Construct empty unordered map.
	UnorderedMap()
	{
	}

	/// Construct unordered map of size n of default constructed elements.
	explicit UnorderedMap(typename UnorderedMap::size_type n) : Polymorphic::UnorderedMap<std::string, T>(n)
	{
	}

	/// Construct unordered map of size n of copy of value constructed elements.
	UnorderedMap(typename UnorderedMap::size_type n, const T& value) : Polymorphic::UnorderedMap<std::string, T>(n, value)
	{
	}

	/// Construct unordered map with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	UnorderedMap(InputIterator first, InputIterator last) : Polymorphic::UnorderedMap<std::string, T>(first, last)
	{
	}

	/// Copy construct unordered map.
	UnorderedMap(const UnorderedMap& other) : Polymorphic::UnorderedMap<std::string, T>(other)
	{
	}

	/// Move construct unordered map.
	UnorderedMap(UnorderedMap&& other) : Polymorphic::UnorderedMap<std::string, T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	UnorderedMap(std::initializer_list<T> initializerList) : Polymorphic::UnorderedMap<std::string, T>(initializerList)
	{
	}

	/// Copy construct unordered map from delegate type.
	UnorderedMap(const typename UnorderedMap::DelegateType& other) : Polymorphic::UnorderedMap<std::string, T>(other)
	{
	}

	/// Move construct unordered map from delegate type.
	UnorderedMap(typename UnorderedMap::DelegateType&& other) : Polymorphic::UnorderedMap<std::string, T>(std::move(other))
	{
	}

	/// Virtual destructor.
	~UnorderedMap()
	{
	}

	virtual void addElement(const std::string& key, const T& value) override
	{
		this->emplace(key, value);
	}

	virtual void forEach(const std::function<void(const std::string& key, const T& value)>& f) const override
	{
		for (const auto& i : *this) {
			f(i.first, i.second);
		}
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_UnorderedMap_INCLUDED
