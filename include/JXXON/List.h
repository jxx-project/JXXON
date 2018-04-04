//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_List_INCLUDED
#define JXXON_List_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/List.h>

namespace JXXON {

/// Alias template composing std::list<T> and implementing JXXON::Serializable.
template <class T>
using List = Json::Array<T, Polymorphic::List>;

} // namespace JXXON

#endif // JXXON_List_INCLUDED
