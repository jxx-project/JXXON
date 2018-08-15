//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.tcc"
#include <cstdint>
#include <memory>

namespace Model {

#if (_SIZEOF_UINT8_T + 0)
template struct Object<std::uint8_t>;
#endif

#if (_SIZEOF_UINT16_T + 0)
template struct Object<std::uint16_t>;
#endif

#if (_SIZEOF_UINT32_T + 0)
template struct Object<std::uint32_t>;
#endif

#if (_SIZEOF_UINT64_T + 0)
template struct Object<std::uint64_t>;
#endif

#if (_SIZEOF_UINTMAX_T + 0) && \
	!((_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT8_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT16_T + 0) || \
	  (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT32_T + 0) || (_SIZEOF_UINTMAX_T + 0) == (_SIZEOF_UINT64_T + 0))
template struct Object<std::uintmax_t>;
#endif

} // namespace Model
