//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template GetMapElements<unsigned int, std::map>::GetMapElements(const Json& json);
template void GetMapElements<unsigned int, std::map>::operator()(Json::MapBase<unsigned int, std::map>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::uint64_t, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::uint64_t, std::map>::operator()(Json::MapBase<std::uint64_t, std::map>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::uintmax_t, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::uintmax_t, std::map>::operator()(Json::MapBase<std::uintmax_t, std::map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
