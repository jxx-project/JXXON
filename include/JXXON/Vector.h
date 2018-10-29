//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXON_Vector_INCLUDED
#define JXXON_Vector_INCLUDED

#include "JXXON/Base/Vector.h"
#include "JXXON/Json.h"

namespace JXXON {

/// Alias template composing std::vector<T, Allocator> and implementing JXXON::Serializable.
template<typename T, typename Allocator = std::allocator<T>>
using Vector = Json::Array<T, Base::Vector, Allocator>;

} // namespace JXXON

#endif // JXXON_Vector_INCLUDED
