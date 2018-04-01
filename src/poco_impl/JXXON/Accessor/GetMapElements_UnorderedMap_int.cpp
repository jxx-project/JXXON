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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template GetMapElements<int, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<int, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, int>& map) const;

#if _SIZEOF_INT64_T != _SIZEOF_INT
template GetMapElements<std::int64_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::int64_t, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::int64_t>& map) const;
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template GetMapElements<std::intmax_t, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::intmax_t, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, std::intmax_t>& map) const;
#endif

} // namespace Accessor
} // namespace JXXON
