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

/// Alias template composing std::vector<T> and implementing JXXON::Serializable.
template<class T>
using Vector = Json::Array<T, Base::Vector>;

} // namespace JXXON

#endif // JXXON_Vector_INCLUDED
