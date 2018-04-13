//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<std::shared_ptr<unsigned int>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<unsigned int>>::operator()(const Json::MapType<std::shared_ptr<unsigned int>>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::shared_ptr<std::uint64_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uint64_t>>::operator()(const Json::MapType<std::shared_ptr<std::uint64_t>>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::shared_ptr<std::uintmax_t>>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::uintmax_t>>::operator()(const Json::MapType<std::shared_ptr<std::uintmax_t>>& map);
#endif

}} // namespace JXXON::Accessor
