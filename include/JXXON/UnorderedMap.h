//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_UnorderedMap_INCLUDED
#define JXXON_UnorderedMap_INCLUDED

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::unordered_map<std::string, T> and implementing JXXON::Serializable.
template <class T>
using UnorderedMap = Json::Map<T, Base::UnorderedMap>;

} // namespace JXXON

#endif // JXXON_UnorderedMap_INCLUDED
