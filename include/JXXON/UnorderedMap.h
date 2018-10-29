//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_UnorderedMap_INCLUDED
#define JXXON_UnorderedMap_INCLUDED

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::unordered_map<std::string, T, Hash, Predicate, Allocator> and implementing JXXON::Serializable.
template<
	typename T,
	typename Hash = std::hash<std::string>,
	typename Predicate = std::equal_to<std::string>,
	typename Allocator = std::allocator<std::pair<const std::string, T>>>
using UnorderedMap = Json::Map<T, Base::UnorderedMap, Hash, Predicate, Allocator>;

} // namespace JXXON

#endif // JXXON_UnorderedMap_INCLUDED
