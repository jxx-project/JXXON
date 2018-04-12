//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template SetMapElements<unsigned int, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<unsigned int, Base::UnorderedMap>::operator()(const Base::UnorderedMap<unsigned int>& map);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetMapElements<std::uint64_t, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::uint64_t, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::uint64_t>& map);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetMapElements<std::uintmax_t, Base::UnorderedMap>::SetMapElements(Json& json);
template void SetMapElements<std::uintmax_t, Base::UnorderedMap>::operator()(const Base::UnorderedMap<std::uintmax_t>& map);
#endif

}} // namespace JXXON::Accessor
