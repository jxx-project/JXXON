//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_Set_INCLUDED
#define JXXON_Base_Set_INCLUDED

#include "JXXON/Json.h"
#include "JXXON/Less.h"
#include <Polymorphic/Set.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Set<Key, Compare, Allocator> implementing JXXON::Json::ArrayType<Key>.
template<typename Key, typename Compare = JXXON::Less<Key>, typename Allocator = std::allocator<Key>>
class Set : public Polymorphic::Set<Key, Compare, Allocator>, public JXXON::Json::ArrayType<Key>
{
public:
	/// Construct empty set.
	Set()
	{
	}

	/// Construct set with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Set(InputIterator first, InputIterator last) : Polymorphic::Set<Key, Compare, Allocator>(first, last)
	{
	}

	/// Copy construct set.
	Set(const Set& other) : Polymorphic::Set<Key, Compare, Allocator>(other)
	{
	}

	/// Move construct set.
	Set(Set&& other) : Polymorphic::Set<Key, Compare, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Set(std::initializer_list<Key> initializerSet) : Polymorphic::Set<Key, Compare, Allocator>(initializerSet)
	{
	}

	/// Copy construct set from delegate type.
	Set(const typename Set::DelegateType& other) : Polymorphic::Set<Key, Compare, Allocator>(other)
	{
	}

	/// Move construct set from delegate type.
	Set(typename Set::DelegateType&& other) : Polymorphic::Set<Key, Compare, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~Set()
	{
	}

	/// Copy assign set.
	Set& operator=(const Set& other)
	{
		return static_cast<Set&>(Polymorphic::Set<Key, Compare, Allocator>::operator=(other));
	}

	/// Move assign set.
	Set& operator=(Set&& other)
	{
		return static_cast<Set&>(Polymorphic::Set<Key, Compare, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	Set& operator=(std::initializer_list<Key> initializerSet)
	{
		return static_cast<Set&>(Polymorphic::Set<Key, Compare, Allocator>::operator=(initializerSet));
	}

	/// Copy assign delegate type set.
	Set& operator=(const typename Set::DelegateType& other)
	{
		return static_cast<Set&>(Polymorphic::Set<Key, Compare, Allocator>::operator=(other));
	}

	/// Move assign delegate type set.
	Set& operator=(typename Set::DelegateType&& other)
	{
		return static_cast<Set&>(Polymorphic::Set<Key, Compare, Allocator>::operator=(std::move(other)));
	}

	virtual void addElement(const Key& element) override
	{
		this->emplace(element);
	}

	virtual void forEach(const std::function<void(const Key& element)>& f) const override
	{
		for (const auto& i : *this) {
			f(i);
		}
	}
};

}} // namespace JXXON::Base

#endif // JXXON_Base_Set_INCLUDED
