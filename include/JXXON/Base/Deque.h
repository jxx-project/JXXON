//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_Deque_INCLUDED
#define JXXON_Base_Deque_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/Deque.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Deque<T, Allocator> implementing JXXON::Json::ArrayType<T>.
template<typename T, typename Allocator = std::allocator<T>>
class Deque : public Polymorphic::Deque<T, Allocator>, public JXXON::Json::ArrayType<T>
{
public:
	/// Construct empty deque.
	Deque()
	{
	}

	/// Construct deque of size n of default constructed elements.
	explicit Deque(typename Deque::size_type n) : Polymorphic::Deque<T, Allocator>(n)
	{
	}

	/// Construct deque of size n of copy of value constructed elements.
	Deque(typename Deque::size_type n, const T& value) : Polymorphic::Deque<T, Allocator>(n, value)
	{
	}

	/// Construct deque with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Deque(InputIterator first, InputIterator last) : Polymorphic::Deque<T, Allocator>(first, last)
	{
	}

	/// Copy construct deque.
	Deque(const Deque& other) : Polymorphic::Deque<T, Allocator>(other)
	{
	}

	/// Move construct deque.
	Deque(Deque&& other) : Polymorphic::Deque<T, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Deque(std::initializer_list<T> initializerList) : Polymorphic::Deque<T, Allocator>(initializerList)
	{
	}

	/// Copy construct deque from delegate type.
	Deque(const typename Deque::DelegateType& other) : Polymorphic::Deque<T, Allocator>(other)
	{
	}

	/// Move construct deque from delegate type.
	Deque(typename Deque::DelegateType&& other) : Polymorphic::Deque<T, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~Deque()
	{
	}

	/// Copy assign deque.
	Deque& operator=(const Deque& other)
	{
		return static_cast<Deque&>(Polymorphic::Deque<T, Allocator>::operator=(other));
	}

	/// Move assign deque.
	Deque& operator=(Deque&& other)
	{
		return static_cast<Deque&>(Polymorphic::Deque<T, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	Deque& operator=(std::initializer_list<T> initializerList)
	{
		return static_cast<Deque&>(Polymorphic::Deque<T, Allocator>::operator=(initializerList));
	}

	/// Copy assign delegate type deque.
	Deque& operator=(const typename Deque::DelegateType& other)
	{
		return static_cast<Deque&>(Polymorphic::Deque<T, Allocator>::operator=(other));
	}

	/// Move assign delegate type deque.
	Deque& operator=(typename Deque::DelegateType&& other)
	{
		return static_cast<Deque&>(Polymorphic::Deque<T, Allocator>::operator=(std::move(other)));
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

#endif // JXXON_Base_Deque_INCLUDED
