//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<int, Base::Map>::SetMapElements(Json& json);
template void SetMapElements<int, Base::Map>::operator()(const Base::Map<int>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::int64_t, Base::Map>::SetMapElements(Json& json);
template void SetMapElements<std::int64_t, Base::Map>::operator()(const Base::Map<std::int64_t>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::intmax_t, Base::Map>::SetMapElements(Json& json);
template void SetMapElements<std::intmax_t, Base::Map>::operator()(const Base::Map<std::intmax_t>& map);
#endif

}} // namespace JXXON::Accessor
