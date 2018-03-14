//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements_shared_ptr.hpp"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<unsigned int>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<unsigned int>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<unsigned int>, std::unordered_map>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::shared_ptr<std::uint64_t>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uint64_t>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::uint64_t>, std::unordered_map>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::shared_ptr<std::uintmax_t>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uintmax_t>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::uintmax_t>, std::unordered_map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
