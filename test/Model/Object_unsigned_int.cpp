//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "Model/Object.tcc"
#include <cstdint>
#include <memory>

namespace Model {

template class Object<unsigned int>;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template class Object<std::uint64_t>;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template class Object<std::uintmax_t>;
#endif

} // namespace Model
