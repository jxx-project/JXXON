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
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<int, std::map>::SetMapElements(Json& json);
template void SetMapElements<int, std::map>::operator()(const Json::MapBase<int, std::map>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::int64_t, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::int64_t, std::map>::operator()(const Json::MapBase<std::int64_t, std::map>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::intmax_t, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::intmax_t, std::map>::operator()(const Json::MapBase<std::intmax_t, std::map>& map);
#endif

} // namespace Accessor
} // namespace JXXON
