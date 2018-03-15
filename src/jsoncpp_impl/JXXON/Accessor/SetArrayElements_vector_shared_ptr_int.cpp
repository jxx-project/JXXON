//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/SetArrayElements_shared_ptr.tcc"
#include <cstdint>
#include <vector>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<int>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<int>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<int>, std::vector>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::int64_t>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<std::int64_t>, std::vector>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::intmax_t>, std::vector>::operator()(const Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::vector>& array);
#endif

} // namespace Accessor
} // namespace JXXON
