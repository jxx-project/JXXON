//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_UnorderedMap_INCLUDED
#define JXXON_UnorderedMap_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {

/// Alias template extending std::unordered_map<std::string, T> and implementing JXXON::Serializable.
template <class T>
using UnorderedMap = Json::Map<T, Polymorphic::UnorderedMap>;

} // namespace JXXON

#endif // JXXON_UnorderedMap_INCLUDED
