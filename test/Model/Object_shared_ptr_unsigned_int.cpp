//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include <cstdint>
#include <memory>
#include "Model/Object.tcc"

namespace Model {

template struct Object<std::shared_ptr<unsigned int>>;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template struct Object<std::shared_ptr<std::uint64_t>>;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template struct Object<std::shared_ptr<std::uintmax_t>>;
#endif

} // namespace Model
