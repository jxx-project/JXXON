//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Model/Object.tcc"
#include <cstdint>

namespace Model {

#if (_SIZEOF_INT8_T + 0)
template struct Object<std::int8_t>;
#endif

#if (_SIZEOF_INT16_T + 0)
template struct Object<std::int16_t>;
#endif

#if (_SIZEOF_INT32_T + 0)
template struct Object<std::int32_t>;
#endif

#if (_SIZEOF_INT64_T + 0)
template struct Object<std::int64_t>;
#endif

#if (_SIZEOF_INTMAX_T + 0) && \
	!((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || \
	  (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template struct Object<std::intmax_t>;
#endif

} // namespace Model
