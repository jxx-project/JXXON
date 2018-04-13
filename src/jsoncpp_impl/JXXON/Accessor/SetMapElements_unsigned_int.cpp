//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<unsigned int>::SetMapElements(Json& json);
template void SetMapElements<unsigned int>::operator()(const Json::MapType<unsigned int>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::uint64_t>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t>::operator()(const Json::MapType<std::uint64_t>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::uintmax_t>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t>::operator()(const Json::MapType<std::uintmax_t>& map);
#endif

}} // namespace JXXON::Accessor
