//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_UnorderedMap_INCLUDED
#define JXXON_Base_UnorderedMap_INCLUDED

#include "JXXON/Base/MapType.h"
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::UnorderedMap<std::string, T> implementing MapType<T>.
template<class T>
class UnorderedMap : public Polymorphic::UnorderedMap<std::string, T>, public MapType<T>
{
public:
	/// Construct empty unordered map.
	UnorderedMap()
	{
	}

	/// Construct unordered map of size n of default constructed elements.
	explicit UnorderedMap(typename Polymorphic::UnorderedMap<std::string, T>::size_type n) : Polymorphic::UnorderedMap<std::string, T>(n)
	{
	}

	/// Construct unordered map of size n of copy of value constructed elements.
	UnorderedMap(typename Polymorphic::UnorderedMap<std::string, T>::size_type n, const T& value) : Polymorphic::UnorderedMap<std::string, T>(n, value)
	{
	}

	/// Construct unordered map with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	UnorderedMap(InputIterator first, InputIterator last) : Polymorphic::UnorderedMap<std::string, T>(first, last)
	{
	}

	/// Copy construct unordered map.
	UnorderedMap(const Polymorphic::UnorderedMap<std::string, T>& other) : Polymorphic::UnorderedMap<std::string, T>(other)
	{
	}

	/// Move construct unordered map.
	UnorderedMap(Polymorphic::UnorderedMap<std::string, T>&& other) : Polymorphic::UnorderedMap<std::string, T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	UnorderedMap(std::initializer_list<T> initializerList) : Polymorphic::UnorderedMap<std::string, T>(initializerList)
	{
	}

	/// Copy construct unordered map from delegate type.
	UnorderedMap(const typename Polymorphic::UnorderedMap<std::string, T>::DelegateType& other) : Polymorphic::UnorderedMap<std::string, T>(other)
	{
	}

	/// Move construct unordered map from delegate type.
	UnorderedMap(typename Polymorphic::UnorderedMap<std::string, T>::DelegateType&& other) : Polymorphic::UnorderedMap<std::string, T>(std::move(other))
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
};

}} // namespace JXXON::Base

#endif // JXXON_Base_UnorderedMap_INCLUDED
