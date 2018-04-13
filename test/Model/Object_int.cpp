//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.tcc"
#include <cstdint>

namespace Model {

template struct Object<int>;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template struct Object<std::int64_t>;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template struct Object<std::intmax_t>;
#endif

} // namespace Model
