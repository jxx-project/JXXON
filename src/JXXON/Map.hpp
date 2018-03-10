//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_Map_INCLUDED
#define JXXON_Map_INCLUDED

#include "JXXON/Json.hpp"
#include <map>

namespace JXXON {
  
template <class T>
using Map = Json::Map<T, std::map>;

} // namespace JXXON

#endif // JXXON_Map_INCLUDED
