//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template SetMapElements<int, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<int, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<int, Polymorphic::UnorderedMap>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::int64_t, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::int64_t, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<std::int64_t, Polymorphic::UnorderedMap>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::intmax_t, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::intmax_t, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<std::intmax_t, Polymorphic::UnorderedMap>& map);
#endif

} // namespace Accessor
} // namespace JXXON
