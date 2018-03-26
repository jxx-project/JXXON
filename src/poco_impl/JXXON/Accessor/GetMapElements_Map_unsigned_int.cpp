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
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template GetMapElements<unsigned int, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<unsigned int, Polymorphic::Map>::operator()(Json::MapBase<unsigned int, Polymorphic::Map>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::uint64_t, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::uint64_t, Polymorphic::Map>::operator()(Json::MapBase<std::uint64_t, Polymorphic::Map>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::uintmax_t, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::uintmax_t, Polymorphic::Map>::operator()(Json::MapBase<std::uintmax_t, Polymorphic::Map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON