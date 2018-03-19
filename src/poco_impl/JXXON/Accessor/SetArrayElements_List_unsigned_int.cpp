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

namespace JXXON {
namespace Accessor {

template SetArrayElements<unsigned int, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int, Polymorphic::List>::operator()(const Json::ArrayBase<unsigned int, Polymorphic::List>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t, Polymorphic::List>::operator()(const Json::ArrayBase<std::uint64_t, Polymorphic::List>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t, Polymorphic::List>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t, Polymorphic::List>::operator()(const Json::ArrayBase<std::uintmax_t, Polymorphic::List>& array);
#endif

} // namespace Accessor
} // namespace JXXON
