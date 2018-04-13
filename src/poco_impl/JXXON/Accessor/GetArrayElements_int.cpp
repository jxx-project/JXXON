//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<int>::GetArrayElements(const Json& json);
template void GetArrayElements<int>::operator()(Json::ArrayType<int>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetArrayElements<std::int64_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t>::operator()(Json::ArrayType<std::int64_t>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetArrayElements<std::intmax_t>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t>::operator()(Json::ArrayType<std::intmax_t>& array) const;
#endif

}} // namespace JXXON::Accessor
