//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_UnorderedMap_INCLUDED
#define JXXON_UnorderedMap_INCLUDED

#include "JXXON/Json.hpp"
#include <unordered_map>

namespace JXXON {
  
template <class T>
using UnorderedMap = Json::Map<T, std::unordered_map>;

} // namespace JXXON

#endif // JXXON_UnorderedMap_INCLUDED
