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

namespace JXXON { namespace Accessor {

template SetMapElements<unsigned int, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<unsigned int, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, unsigned int>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::uint64_t, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, std::uint64_t>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::uintmax_t, Polymorphic::Map>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t, Polymorphic::Map>::operator()(const Polymorphic::Map<std::string, std::uintmax_t>& map);
#endif

}} // namespace JXXON::Accessor