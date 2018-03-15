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

template SetArrayElements<int, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<int, std::vector>::operator()(const Json::ArrayBase<int, std::vector>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::int64_t, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::int64_t, std::vector>::operator()(const Json::ArrayBase<std::int64_t, std::vector>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::intmax_t, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::intmax_t, std::vector>::operator()(const Json::ArrayBase<std::intmax_t, std::vector>& array);
#endif

} // namespace Accessor
} // namespace JXXON
