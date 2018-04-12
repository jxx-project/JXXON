//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/List.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetArrayElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetArrayElements<int, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<int, Base::List>::operator()(Base::List<int>& array) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetArrayElements<std::int64_t, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::int64_t, Base::List>::operator()(Base::List<std::int64_t>& array) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetArrayElements<std::intmax_t, Base::List>::GetArrayElements(const Json& json);
template void GetArrayElements<std::intmax_t, Base::List>::operator()(Base::List<std::intmax_t>& array) const;
#endif

}} // namespace JXXON::Accessor
