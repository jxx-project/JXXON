//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_UnorderedMap_INCLUDED
#define JXXON_Base_UnorderedMap_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator> implementing JXXON::Json::MapType<T>.
template<
	typename T,
	typename Hash = std::hash<std::string>,
	typename Predicate = std::equal_to<std::string>,
	typename Allocator = std::allocator<std::pair<const std::string, T>>>
class UnorderedMap : public Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>, public JXXON::Json::MapType<T>
{
public:
	/// Construct empty unordered map.
	UnorderedMap()
	{
	}

	/// Construct unordered map with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	UnorderedMap(InputIterator first, InputIterator last) :
		Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(first, last)
	{
	}

	/// Copy construct unordered map.
	UnorderedMap(const UnorderedMap& other) : Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct unordered map.
	UnorderedMap(UnorderedMap&& other) : Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	UnorderedMap(std::initializer_list<T> initializerList) :
		Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(initializerList)
	{
	}

	/// Copy construct unordered map from delegate type.
	UnorderedMap(const typename UnorderedMap::DelegateType& other) :
		Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct unordered map from delegate type.
	UnorderedMap(typename UnorderedMap::DelegateType&& other) :
		Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~UnorderedMap()
	{
	}

	/// Copy assign unordered map.
	UnorderedMap& operator=(const UnorderedMap& other)
	{
		return static_cast<UnorderedMap&>(Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign unordered map.
	UnorderedMap& operator=(UnorderedMap&& other)
	{
		return static_cast<UnorderedMap&>(
			Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	UnorderedMap& operator=(std::initializer_list<T> initializerList)
	{
		return static_cast<UnorderedMap&>(
			Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>::operator=(initializerList));
	}

	/// Copy assign delegate type unordered map.
	UnorderedMap& operator=(const typename UnorderedMap::DelegateType& other)
	{
		return static_cast<UnorderedMap&>(Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign delegate type unordered map.
	UnorderedMap& operator=(typename UnorderedMap::DelegateType&& other)
	{
		return static_cast<UnorderedMap&>(
			Polymorphic::UnorderedMap<std::string, T, Hash, Predicate, Allocator>::operator=(std::move(other)));
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
