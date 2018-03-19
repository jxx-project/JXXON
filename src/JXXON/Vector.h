//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_Vector_INCLUDED
#define JXXON_Vector_INCLUDED

#include "JXXON/Json.h"
#include <Polymorphic/Vector.h>

namespace JXXON {

/// Alias template extending std::vector<T> and implementing JXXON::Serializable.
template <class T>
using Vector = Json::Array<T, Polymorphic::Vector>;

} // namespace JXXON

#endif // JXXON_Vector_INCLUDED
