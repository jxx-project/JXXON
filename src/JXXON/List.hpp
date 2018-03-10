//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_List_INCLUDED
#define JXXON_List_INCLUDED

#include "JXXON/Json.hpp"
#include <list>

namespace JXXON {
  
template <class T>
using List = Json::Array<T, std::list>;

} // namespace JXXON

#endif // JXXON_List_INCLUDED
