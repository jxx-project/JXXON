//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_List_INCLUDED
#define JXXON_List_INCLUDED

#include "JXXON/Base/List.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::list<T> and implementing JXXON::Serializable.
template<typename T, typename Allocator = std::allocator<T>>
using List = Json::Array<T, Base::List, Allocator>;

} // namespace JXXON

#endif // JXXON_List_INCLUDED
