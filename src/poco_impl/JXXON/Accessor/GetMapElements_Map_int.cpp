//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<int, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<int, Base::Map>::operator()(Base::Map<int>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetMapElements<std::int64_t, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t, Base::Map>::operator()(Base::Map<std::int64_t>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetMapElements<std::intmax_t, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t, Base::Map>::operator()(Base::Map<std::intmax_t>& map) const;
#endif

}} // namespace JXXON::Accessor
