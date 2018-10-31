//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_UnorderedSet_INCLUDED
#define JXXON_Base_UnorderedSet_INCLUDED

#include "JXXON/EqualTo.h"
#include "JXXON/Hash.h"
#include "JXXON/Json.h"
#include <Polymorphic/UnorderedSet.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator> implementing JXXON::Json::ArrayType<Key>.
template<
	typename Key,
	typename Hash = JXXON::Hash<Key>,
	typename Predicate = JXXON::EqualTo<Key>,
	typename Allocator = std::allocator<Key>>
class UnorderedSet : public Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>, public JXXON::Json::ArrayType<Key>
{
public:
	/// Construct empty set.
	UnorderedSet()
	{
	}

	/// Construct set with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	UnorderedSet(InputIterator first, InputIterator last) : Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(first, last)
	{
	}

	/// Copy construct set.
	UnorderedSet(const UnorderedSet& other) : Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct set.
	UnorderedSet(UnorderedSet&& other) : Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	UnorderedSet(std::initializer_list<Key> initializerSet) :
		Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(initializerSet)
	{
	}

	/// Copy construct set from delegate type.
	UnorderedSet(const typename UnorderedSet::DelegateType& other) :
		Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct set from delegate type.
	UnorderedSet(typename UnorderedSet::DelegateType&& other) :
		Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~UnorderedSet()
	{
	}

	/// Copy assign set.
	UnorderedSet& operator=(const UnorderedSet& other)
	{
		return static_cast<UnorderedSet&>(Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign set.
	UnorderedSet& operator=(UnorderedSet&& other)
	{
		return static_cast<UnorderedSet&>(Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	UnorderedSet& operator=(std::initializer_list<Key> initializerSet)
	{
		return static_cast<UnorderedSet&>(Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>::operator=(initializerSet));
	}

	/// Copy assign delegate type set.
	UnorderedSet& operator=(const typename UnorderedSet::DelegateType& other)
	{
		return static_cast<UnorderedSet&>(Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign delegate type set.
	UnorderedSet& operator=(typename UnorderedSet::DelegateType&& other)
	{
		return static_cast<UnorderedSet&>(Polymorphic::UnorderedSet<Key, Hash, Predicate, Allocator>::operator=(std::move(other)));
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

#endif // JXXON_Base_UnorderedSet_INCLUDED
