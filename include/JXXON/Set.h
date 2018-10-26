//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Set_INCLUDED
#define JXXON_Set_INCLUDED

#include "JXXON/Base/Set.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::set<T> and implementing JXXON::Serializable.
template<typename T>
using Set = Json::Array<T, Base::Set>;

} // namespace JXXON

#endif // JXXON_Set_INCLUDED
