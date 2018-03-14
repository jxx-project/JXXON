//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetMapElements.hpp"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<unsigned int, std::map>::SetMapElements(Json& json);
template void SetMapElements<unsigned int, std::map>::operator()(const Json::MapBase<unsigned int, std::map>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::uint64_t, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t, std::map>::operator()(const Json::MapBase<std::uint64_t, std::map>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::uintmax_t, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t, std::map>::operator()(const Json::MapBase<std::uintmax_t, std::map>& map);
#endif

} // namespace Accessor
} // namespace JXXON
