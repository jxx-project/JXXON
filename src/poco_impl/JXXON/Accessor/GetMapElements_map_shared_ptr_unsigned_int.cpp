//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements_shared_ptr.hpp"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<unsigned int>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<unsigned int>, std::map>::operator()(Json::MapBase<std::shared_ptr<unsigned int>, std::map>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::shared_ptr<std::uint64_t>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uint64_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::uint64_t>, std::map>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::shared_ptr<std::uintmax_t>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uintmax_t>, std::map>::operator()(Json::MapBase<std::shared_ptr<std::uintmax_t>, std::map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
