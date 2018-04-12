//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template GetMapElements<unsigned int, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<unsigned int, Base::Map>::operator()(Base::Map<unsigned int>& map) const;

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template GetMapElements<std::uint64_t, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::uint64_t, Base::Map>::operator()(Base::Map<std::uint64_t>& map) const;
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template GetMapElements<std::uintmax_t, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::uintmax_t, Base::Map>::operator()(Base::Map<std::uintmax_t>& map) const;
#endif

}} // namespace JXXON::Accessor
