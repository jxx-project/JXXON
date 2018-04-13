//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetArrayElements<unsigned int>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int>::operator()(const Json::ArrayType<unsigned int>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t>::operator()(const Json::ArrayType<std::uint64_t>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t>::operator()(const Json::ArrayType<std::uintmax_t>& array);
#endif

}} // namespace JXXON::Accessor
