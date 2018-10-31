//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_UnorderedMultiset_INCLUDED
#define JXXON_UnorderedMultiset_INCLUDED

#include "JXXON/Base/UnorderedMultiset.h"
#include "JXXON/EqualTo.h"
#include "JXXON/Hash.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::set<Key, Hash, Predicate, Allocator> and implementing JXXON::Serializable.
template<typename Key, typename Hash = Hash<Key>, typename Predicate = EqualTo<Key>, typename Allocator = std::allocator<Key>>
using UnorderedMultiset = Json::Array<Key, Base::UnorderedMultiset, Hash, Predicate, Allocator>;

} // namespace JXXON

#endif // JXXON_UnorderedMultiset_INCLUDED
