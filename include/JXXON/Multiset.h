//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Multiset_INCLUDED
#define JXXON_Multiset_INCLUDED

#include "JXXON/Base/Multiset.h"
#include "JXXON/Json.h"
#include "JXXON/Less.h"

namespace JXXON {

/// Alias template composing std::set<Key, Compare, Allocator> and implementing JXXON::Serializable.
template<typename Key, typename Compare = Less<Key>, typename Allocator = std::allocator<Key>>
using Multiset = Json::Array<Key, Base::Multiset, Compare>;

} // namespace JXXON

#endif // JXXON_Multiset_INCLUDED
