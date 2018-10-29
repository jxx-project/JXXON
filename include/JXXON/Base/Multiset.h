//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_Multiset_INCLUDED
#define JXXON_Base_Multiset_INCLUDED

#include "JXXON/Json.h"
#include "JXXON/Less.h"
#include <Polymorphic/Multiset.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::Multiset<Key, Compare, Allocator> implementing JXXON::Json::ArrayType<Key>.
template<typename Key, typename Compare = JXXON::Less<Key>, typename Allocator = std::allocator<Key>>
class Multiset : public Polymorphic::Multiset<Key, Compare, Allocator>, public JXXON::Json::ArrayType<Key>
{
public:
	/// Construct empty set.
	Multiset()
	{
	}

	/// Construct set with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	Multiset(InputIterator first, InputIterator last) : Polymorphic::Multiset<Key, Compare, Allocator>(first, last)
	{
	}

	/// Copy construct set.
	Multiset(const Multiset& other) : Polymorphic::Multiset<Key, Compare, Allocator>(other)
	{
	}

	/// Move construct set.
	Multiset(Multiset&& other) : Polymorphic::Multiset<Key, Compare, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	Multiset(std::initializer_list<Key> initializerMultiset) : Polymorphic::Multiset<Key, Compare, Allocator>(initializerMultiset)
	{
	}

	/// Copy construct set from delegate type.
	Multiset(const typename Multiset::DelegateType& other) : Polymorphic::Multiset<Key, Compare, Allocator>(other)
	{
	}

	/// Move construct set from delegate type.
	Multiset(typename Multiset::DelegateType&& other) : Polymorphic::Multiset<Key, Compare, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~Multiset()
	{
	}

	/// Copy assign set.
	Multiset& operator=(const Multiset& other)
	{
		return static_cast<Multiset&>(Polymorphic::Multiset<Key, Compare, Allocator>::operator=(other));
	}

	/// Move assign set.
	Multiset& operator=(Multiset&& other)
	{
		return static_cast<Multiset&>(Polymorphic::Multiset<Key, Compare, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	Multiset& operator=(std::initializer_list<Key> initializerMultiset)
	{
		return static_cast<Multiset&>(Polymorphic::Multiset<Key, Compare, Allocator>::operator=(initializerMultiset));
	}

	/// Copy assign delegate type set.
	Multiset& operator=(const typename Multiset::DelegateType& other)
	{
		return static_cast<Multiset&>(Polymorphic::Multiset<Key, Compare, Allocator>::operator=(other));
	}

	/// Move assign delegate type set.
	Multiset& operator=(typename Multiset::DelegateType&& other)
	{
		return static_cast<Multiset&>(Polymorphic::Multiset<Key, Compare, Allocator>::operator=(std::move(other)));
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

#endif // JXXON_Base_Multiset_INCLUDED
