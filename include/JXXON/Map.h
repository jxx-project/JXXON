//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Map_INCLUDED
#define JXXON_Map_INCLUDED

#include "JXXON/Base/Map.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::map<std::string, T, Compare, Allocator> and implementing JXXON::Serializable.
template<
	typename T,
	typename Compare = std::less<std::string>,
	typename Allocator = std::allocator<std::pair<const std::string, T>>>
using Map = Json::Map<T, Base::Map, Compare, Allocator>;

} // namespace JXXON

#endif // JXXON_Map_INCLUDED
