//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Base_UnorderedMultiset_INCLUDED
#define JXXON_Base_UnorderedMultiset_INCLUDED

#include "JXXON/EqualTo.h"
#include "JXXON/Hash.h"
#include "JXXON/Json.h"
#include <Polymorphic/UnorderedMultiset.h>

namespace JXXON { namespace Base {

/// Extension of Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator> implementing JXXON::Json::ArrayType<Key>.
template<
	typename Key,
	typename Hash = JXXON::Hash<Key>,
	typename Predicate = JXXON::EqualTo<Key>,
	typename Allocator = std::allocator<Key>>
class UnorderedMultiset : public Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>, public JXXON::Json::ArrayType<Key>
{
public:
	/// Construct empty set.
	UnorderedMultiset()
	{
	}

	/// Construct set with emplace constructed elements of range [first, last).
	template<typename InputIterator>
	UnorderedMultiset(InputIterator first, InputIterator last) :
		Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(first, last)
	{
	}

	/// Copy construct set.
	UnorderedMultiset(const UnorderedMultiset& other) : Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct set.
	UnorderedMultiset(UnorderedMultiset&& other) : Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Initializer list constructor.
	UnorderedMultiset(std::initializer_list<Key> initializerSet) :
		Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(initializerSet)
	{
	}

	/// Copy construct set from delegate type.
	UnorderedMultiset(const typename UnorderedMultiset::DelegateType& other) :
		Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(other)
	{
	}

	/// Move construct set from delegate type.
	UnorderedMultiset(typename UnorderedMultiset::DelegateType&& other) :
		Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>(std::move(other))
	{
	}

	/// Virtual destructor.
	virtual ~UnorderedMultiset()
	{
	}

	/// Copy assign set.
	UnorderedMultiset& operator=(const UnorderedMultiset& other)
	{
		return static_cast<UnorderedMultiset&>(Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign set.
	UnorderedMultiset& operator=(UnorderedMultiset&& other)
	{
		return static_cast<UnorderedMultiset&>(
			Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>::operator=(std::move(other)));
	}

	/// Initializer list assignment.
	UnorderedMultiset& operator=(std::initializer_list<Key> initializerSet)
	{
		return static_cast<UnorderedMultiset&>(
			Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>::operator=(initializerSet));
	}

	/// Copy assign delegate type set.
	UnorderedMultiset& operator=(const typename UnorderedMultiset::DelegateType& other)
	{
		return static_cast<UnorderedMultiset&>(Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>::operator=(other));
	}

	/// Move assign delegate type set.
	UnorderedMultiset& operator=(typename UnorderedMultiset::DelegateType&& other)
	{
		return static_cast<UnorderedMultiset&>(
			Polymorphic::UnorderedMultiset<Key, Hash, Predicate, Allocator>::operator=(std::move(other)));
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

#endif // JXXON_Base_UnorderedMultiset_INCLUDED
