//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_Map_INCLUDED
#define JXXON_Base_Map_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/Map.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Map<std::string, T, Compare, Allocator> implementing JXXON::Json::MapType<T>.
template<
	typename T,
	typename Compare = std::less<std::string>,
	typename Allocator = std::allocator<std::pair<const std::string, T>>>
class Map : public Polymorphic::Map<std::string, T, Compare, Allocator>, public JXXON::Json::MapType<T>
{
public:
	/// Construct empty map.
	Map()
	{
	}

	/// Construct map with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Map(InputIterator first, InputIterator last) : Polymorphic::Map<std::string, T, Compare, Allocator>(first, last)
	{
	}

	/// Copy construct map.
	Map(const Map& other) : Polymorphic::Map<std::string, T, Compare, Allocator>(other)
	{
	}

	/// Move construct map.
	Map(Map&& other) : Polymorphic::Map<std::string, T, Compare, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Map(std::initializer_list<T> initializerList) : Polymorphic::Map<std::string, T, Compare, Allocator>(initializerList)
	{
	}

	/// Copy construct map from delegate type.
	Map(const typename Map::DelegateType& other) : Polymorphic::Map<std::string, T, Compare, Allocator>(other)
	{
	}

	/// Move construct map from delegate type.
	Map(typename Map::DelegateType&& other) : Polymorphic::Map<std::string, T, Compare, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~Map()
	{
	}

	/// Copy assign map.
	Map& operator=(const Map& other)
	{
		return static_cast<Map&>(Polymorphic::Map<std::string, T, Compare, Allocator>::operator=(other));
	}

	/// Move assign map.
	Map& operator=(Map&& other)
	{
		return static_cast<Map&>(Polymorphic::Map<std::string, T, Compare, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	Map& operator=(std::initializer_list<T> initializerList)
	{
		return static_cast<Map&>(Polymorphic::Map<std::string, T, Compare, Allocator>::operator=(initializerList));
	}

	/// Copy assign delegate type map.
	Map& operator=(const typename Map::DelegateType& other)
	{
		return static_cast<Map&>(Polymorphic::Map<std::string, T, Compare, Allocator>::operator=(other));
	}

	/// Move assign delegate type map.
	Map& operator=(typename Map::DelegateType&& other)
	{
		return static_cast<Map&>(Polymorphic::Map<std::string, T, Compare, Allocator>::operator=(std::move(other)));
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

#endif // JXXON_Base_Map_INCLUDED
