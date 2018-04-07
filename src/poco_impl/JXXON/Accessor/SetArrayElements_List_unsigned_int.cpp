//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetArrayElements.tcc"
#include <cstdint>
#include <Polymorphic/List.h>

namespace JXXON { namespace Accessor {

template SetArrayElements<unsigned int, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int, Polymorphic::List>::operator()(const Polymorphic::List<unsigned int>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t, Polymorphic::List>::operator()(const Polymorphic::List<std::uint64_t>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t, Polymorphic::List>::operator()(const Polymorphic::List<std::uintmax_t>& array);
#endif

}} // namespace JXXON::Accessor
