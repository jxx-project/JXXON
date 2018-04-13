//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXON_Base_List_INCLUDED
#define JXXON_Base_List_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/List.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::List<T> implementing JXXON::Json::ArrayType<T>.
template<class T>
class List : public Polymorphic::List<T>, public JXXON::Json::ArrayType<T>
{
public:
	/// Construct empty list.
	List()
	{
	}

	/// Construct list of size n of default constructed elements.
	explicit List(typename List::size_type n) : Polymorphic::List<T>(n)
	{
	}

	/// Construct list of size n of copy of value constructed elements.
	List(typename List::size_type n, const T& value) : Polymorphic::List<T>(n, value)
	{
	}

	/// Construct list with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	List(InputIterator first, InputIterator last) : Polymorphic::List<T>(first, last)
	{
	}

	/// Copy construct list.
	List(const List& other) : Polymorphic::List<T>(other)
	{
	}

	/// Move construct list.
	List(List&& other) : Polymorphic::List<T>(std::move(other))
	{
	}

	/// Initializer list constructor.
	List(std::initializer_list<T> initializerList) : Polymorphic::List<T>(initializerList)
	{
	}

	/// Copy construct list from delegate type.
	List(const typename List::DelegateType& other) : Polymorphic::List<T>(other)
	{
	}

	/// Move construct list from delegate type.
	List(typename List::DelegateType&& other) : Polymorphic::List<T>(std::move(other))
	{
	}

	/// Virtual destructor.
	~List()
	{
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
