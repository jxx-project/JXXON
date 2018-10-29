//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_List_INCLUDED
#define JXXON_Base_List_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/List.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::List<T, Allocator> implementing JXXON::Json::ArrayType<T>.
template<typename T, typename Allocator = std::allocator<T>>
class List : public Polymorphic::List<T, Allocator>, public JXXON::Json::ArrayType<T>
{
public:
	/// Construct empty list.
	List()
	{
	}

	/// Construct list of size n of default constructed elements.
	explicit List(typename List::size_type n) : Polymorphic::List<T, Allocator>(n)
	{
	}

	/// Construct list of size n of copy of value constructed elements.
	List(typename List::size_type n, const T& value) : Polymorphic::List<T, Allocator>(n, value)
	{
	}

	/// Construct list with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	List(InputIterator first, InputIterator last) : Polymorphic::List<T, Allocator>(first, last)
	{
	}

	/// Copy construct list.
	List(const List& other) : Polymorphic::List<T, Allocator>(other)
	{
	}

	/// Move construct list.
	List(List&& other) : Polymorphic::List<T, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	List(std::initializer_list<T> initializerList) : Polymorphic::List<T, Allocator>(initializerList)
	{
	}

	/// Copy construct list from delegate type.
	List(const typename List::DelegateType& other) : Polymorphic::List<T, Allocator>(other)
	{
	}

	/// Move construct list from delegate type.
	List(typename List::DelegateType&& other) : Polymorphic::List<T, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~List()
	{
	}

	/// Copy assign list.
	List& operator=(const List& other)
	{
		return static_cast<List&>(Polymorphic::List<T, Allocator>::operator=(other));
	}

	/// Move assign list.
	List& operator=(List&& other)
	{
		return static_cast<List&>(Polymorphic::List<T, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	List& operator=(std::initializer_list<T> initializerList)
	{
		return static_cast<List&>(Polymorphic::List<T, Allocator>::operator=(initializerList));
	}

	/// Copy assign delegate type list.
	List& operator=(const typename List::DelegateType& other)
	{
		return static_cast<List&>(Polymorphic::List<T, Allocator>::operator=(other));
	}

	/// Move assign delegate type list.
	List& operator=(typename List::DelegateType&& other)
	{
		return static_cast<List&>(Polymorphic::List<T, Allocator>::operator=(std::move(other)));
	}

	virtual void addElement(const T& element) override
	{
		this->emplace_back(element);
	}

	virtual void forEach(const std::function<void(const T& element)>& f) const override
	{
		for (const auto& i : *this) {
			f(i);
		}
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_List_INCLUDED
