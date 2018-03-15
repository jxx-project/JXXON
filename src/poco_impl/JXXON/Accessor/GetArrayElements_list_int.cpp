//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template GetArrayElements<int, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<int, std::list>::operator()(Json::ArrayBase<int, std::list>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetArrayElements<std::int64_t, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t, std::list>::operator()(Json::ArrayBase<std::int64_t, std::list>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetArrayElements<std::intmax_t, std::list>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t, std::list>::operator()(Json::ArrayBase<std::intmax_t, std::list>& array) const;
#endif

} // namespace Accessor
} // namespace JXXON
