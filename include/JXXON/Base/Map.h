//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_Map_INCLUDED
#define JXXON_Base_Map_INCLUDED

#include <Polymorphic/Map.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Map<std::string, T> adding addElement(T&& element).
template<class T>
class Map : public Polymorphic::Map<std::string, T>
{
public:
	/// Construct empty map.
	Map()
	{
	}

	/// Construct map of size n of default constructed elements.
	explicit Map(typename Polymorphic::Map<std::string, T>::size_type n) : Polymorphic::Map<std::string, T>(n)
	{
	}

	/// Construct map of size n of copy of value constructed elements.
	Map(typename Polymorphic::Map<std::string, T>::size_type n, const T& value) : Polymorphic::Map<std::string, T>(n, value)
	{
	}

	/// Construct map with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Map(InputIterator first, InputIterator last) : Polymorphic::Map<std::string, T>(first, last)
	{
	}

	/// Copy construct map.
	Map(const Polymorphic::Map<std::string, T>& other) : Polymorphic::Map<std::string, T>(other)
	{
	}

	/// Move construct map.
	Map(Polymorphic::Map<std::string, T>&& other) : Polymorphic::Map<std::string, T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Map(std::initializer_list<T> initializerList) : Polymorphic::Map<std::string, T>(initializerList)
	{
	}

	/// Copy construct map from delegate type.
	Map(const typename Polymorphic::Map<std::string, T>::DelegateType& other) : Polymorphic::Map<std::string, T>(other)
	{
	}

	/// Move construct map from delegate type.
	Map(typename Polymorphic::Map<std::string, T>::DelegateType&& other) : Polymorphic::Map<std::string, T>(std::move(other))
	{
	}

	/// Virtual destructor .
	~Map()
	{
	}

	virtual void addElement(std::pair<std::string, T>&& element)
	{
		this->emplace(std::move(element));
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_Map_INCLUDED
