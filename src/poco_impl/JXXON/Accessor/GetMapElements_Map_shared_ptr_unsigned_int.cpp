//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<unsigned int>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<unsigned int>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<unsigned int>, Polymorphic::Map>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::shared_ptr<std::uint64_t>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uint64_t>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<std::uint64_t>, Polymorphic::Map>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::shared_ptr<std::uintmax_t>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::uintmax_t>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<std::uintmax_t>, Polymorphic::Map>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
