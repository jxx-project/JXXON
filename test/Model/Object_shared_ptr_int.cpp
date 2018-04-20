//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include <cstdint>
#include <memory>
#include "Model/Object.tcc"

namespace Model {

#if (_SIZEOF_INT8_T + 0)
template struct Object<std::shared_ptr<std::int8_t>>;
#endif

#if (_SIZEOF_INT16_T + 0)
template struct Object<std::shared_ptr<std::int16_t>>;
#endif

#if (_SIZEOF_INT32_T + 0)
template struct Object<std::shared_ptr<std::int32_t>>;
#endif

#if (_SIZEOF_INT64_T + 0)
template struct Object<std::shared_ptr<std::int64_t>>;
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template struct Object<std::shared_ptr<std::intmax_t>>;
#endif

} // namespace Model
