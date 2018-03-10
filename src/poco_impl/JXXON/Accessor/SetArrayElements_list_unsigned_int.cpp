//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements.hpp"
#include <list>

namespace JXXON {
namespace Accessor {

template SetArrayElements<unsigned int, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<unsigned int, std::list>::operator()(const Json::ArrayBase<unsigned int, std::list>& array);

#if _SIZEOF_UINT64_T != _SIZEOF_UNSIGNED_INT
template SetArrayElements<std::uint64_t, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::uint64_t, std::list>::operator()(const Json::ArrayBase<std::uint64_t, std::list>& array);
#endif

#if _SIZEOF_UINTMAX_T != _SIZEOF_UNSIGNED_INT && _SIZEOF_UINTMAX_T != _SIZEOF_UINT64_T
template SetArrayElements<std::uintmax_t, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::uintmax_t, std::list>::operator()(const Json::ArrayBase<std::uintmax_t, std::list>& array);
#endif

} // namespace Accessor
} // namespace JXXON
