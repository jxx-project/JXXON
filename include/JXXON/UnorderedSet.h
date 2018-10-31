//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_UnorderedSet_INCLUDED
#define JXXON_UnorderedSet_INCLUDED

#include "JXXON/Base/UnorderedSet.h"
#include "JXXON/EqualTo.h"
#include "JXXON/Hash.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::set<Key, Hash, Predicate, Allocator> and implementing JXXON::Serializable.
template<typename Key, typename Hash = Hash<Key>, typename Predicate = EqualTo<Key>, typename Allocator = std::allocator<Key>>
using UnorderedSet = Json::Array<Key, Base::UnorderedSet, Hash, Predicate, Allocator>;

} // namespace JXXON

#endif // JXXON_UnorderedSet_INCLUDED
