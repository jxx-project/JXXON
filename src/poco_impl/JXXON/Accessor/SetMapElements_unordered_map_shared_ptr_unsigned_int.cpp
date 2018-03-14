//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetMapElements_shared_ptr.hpp"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<unsigned int>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<unsigned int>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<unsigned int>, std::unordered_map>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::shared_ptr<std::uint64_t>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint64_t>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<std::uint64_t>, std::unordered_map>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::shared_ptr<std::uintmax_t>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uintmax_t>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<std::uintmax_t>, std::unordered_map>& map);
#endif

} // namespace Accessor
} // namespace JXXON
