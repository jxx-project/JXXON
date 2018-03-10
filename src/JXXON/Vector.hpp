//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:     BSL-1.0
//


#ifndef JXXON_Vector_INCLUDED
#define JXXON_Vector_INCLUDED

#include "JXXON/Json.hpp"
#include <vector>

namespace JXXON {
  
template <class T>
using Vector = Json::Array<T, std::vector>;

} // namespace JXXON

#endif // JXXON_Vector_INCLUDED
