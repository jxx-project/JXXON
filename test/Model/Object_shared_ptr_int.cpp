//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include <cstdint>
#include <memory>
#include "Model/Object.tcc"

namespace Model {

template struct Object<std::shared_ptr<int>>;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template struct Object<std::shared_ptr<std::int64_t>>;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template struct Object<std::shared_ptr<std::intmax_t>>;
#endif

} // namespace Model
