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

template SetArrayElements<int>::SetArrayElements(Json& json);
template void SetArrayElements<int>::operator()(const Json::ArrayType<int>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::int64_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::int64_t>::operator()(const Json::ArrayType<std::int64_t>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::intmax_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::intmax_t>::operator()(const Json::ArrayType<std::intmax_t>& array);
#endif

}} // namespace JXXON::Accessor
