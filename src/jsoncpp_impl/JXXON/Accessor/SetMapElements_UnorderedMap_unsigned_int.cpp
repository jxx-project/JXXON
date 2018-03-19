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

template SetMapElements<unsigned int, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<unsigned int, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<unsigned int, Polymorphic::UnorderedMap>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<std::uint64_t, Polymorphic::UnorderedMap>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t, Polymorphic::UnorderedMap>::operator()(const Json::MapBase<std::uintmax_t, Polymorphic::UnorderedMap>& map);
#endif

} // namespace Accessor
} // namespace JXXON
