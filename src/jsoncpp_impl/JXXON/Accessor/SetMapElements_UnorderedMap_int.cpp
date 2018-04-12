//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<int, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<int, Base::UnorderedMap>::operator()(const Base::UnorderedMap<int>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::int64_t, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::int64_t, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::int64_t>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::intmax_t, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::intmax_t, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::intmax_t>& map);
#endif

}} // namespace JXXON::Accessor
