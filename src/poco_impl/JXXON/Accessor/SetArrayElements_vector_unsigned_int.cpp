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
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<unsigned int, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int, std::vector>::operator()(const Json::ArrayBase<unsigned int, std::vector>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t, std::vector>::operator()(const Json::ArrayBase<std::uint64_t, std::vector>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t, std::vector>::operator()(const Json::ArrayBase<std::uintmax_t, std::vector>& array);
#endif

} // namespace Accessor
} // namespace JXXON
