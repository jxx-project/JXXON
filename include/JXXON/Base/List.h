//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_List_INCLUDED
#define JXXON_Base_List_INCLUDED

#include <Polymorphic/List.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::List<T> adding addElement(T&& element).
template<class T>
class List : public Polymorphic::List<T>
{
public:
	/// Construct empty list.
	List()
	{
	}

	/// Construct list of size n of default constructed elements.
	explicit List(typename Polymorphic::List<T>::size_type n) : Polymorphic::List<T>(n)
	{
	}

	/// Construct list of size n of copy of value constructed elements.
	List(typename Polymorphic::List<T>::size_type n, const T& value) : Polymorphic::List<T>(n, value)
	{
	}

	/// Construct list with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	List(InputIterator first, InputIterator last) : Polymorphic::List<T>(first, last)
	{
	}

	/// Copy construct list.
	List(const Polymorphic::List<T>& other) : Polymorphic::List<T>(other)
	{
	}

	/// Move construct list.
	List(Polymorphic::List<T>&& other) : Polymorphic::List<T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	List(std::initializer_list<T> initializerList) : Polymorphic::List<T>(initializerList)
	{
	}

	/// Copy construct list from delegate type.
	List(const typename Polymorphic::List<T>::DelegateType& other) : Polymorphic::List<T>(other)
	{
	}

	/// Move construct list from delegate type.
	List(typename Polymorphic::List<T>::DelegateType&& other) : Polymorphic::List<T>(std::move(other))
	{
	}

	/// Virtual destructor .
	~List()
	{
	}

	virtual void addElement(T&& element)
	{
		this->emplace_back(std::move(element));
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_List_INCLUDED
