//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {


#if (_SIZEOF_INT8_T + 0)
template SetArrayElements<std::int8_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::int8_t>::operator()(const Json::ArrayType<std::int8_t>& array);
#endif

#if (_SIZEOF_INT16_T + 0)
template SetArrayElements<std::int16_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::int16_t>::operator()(const Json::ArrayType<std::int16_t>& array);
#endif

#if (_SIZEOF_INT32_T + 0)
template SetArrayElements<std::int32_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::int32_t>::operator()(const Json::ArrayType<std::int32_t>& array);
#endif

#if (_SIZEOF_INT64_T + 0)
template SetArrayElements<std::int64_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::int64_t>::operator()(const Json::ArrayType<std::int64_t>& array);
#endif

#if (_SIZEOF_INTMAX_T + 0) && !((_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT8_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT16_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT32_T + 0) || (_SIZEOF_INTMAX_T + 0) == (_SIZEOF_INT64_T + 0))
template SetArrayElements<std::intmax_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::intmax_t>::operator()(const Json::ArrayType<std::intmax_t>& array);
#endif

}} // namespace JXXON::Accessor
