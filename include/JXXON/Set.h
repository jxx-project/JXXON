//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Set_INCLUDED
#define JXXON_Set_INCLUDED

#include "JXXON/Base/Set.h"
#include "JXXON/Json.h"
#include "JXXON/Less.h"

namespace JXXON {

/// Alias template composing std::set<Key, Compare, Allocator> and implementing JXXON::Serializable.
template<typename Key, typename Compare = Less<Key>, typename Allocator = std::allocator<Key>>
using Set = Json::Array<Key, Base::Set, Compare>;

} // namespace JXXON

#endif // JXXON_Set_INCLUDED
