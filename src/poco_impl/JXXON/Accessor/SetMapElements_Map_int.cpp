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
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template SetMapElements<int, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<int, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, int>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::int64_t, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<std::int64_t, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, std::int64_t>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::intmax_t, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<std::intmax_t, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, std::intmax_t>& map);
#endif

} // namespace Accessor
} // namespace JXXON
