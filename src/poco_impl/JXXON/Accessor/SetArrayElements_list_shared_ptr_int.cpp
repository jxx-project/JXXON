//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetArrayElements_shared_ptr.hpp"
#include <cstdint>
#include <list>

namespace JXXON {
namespace Accessor {

template SetArrayElements<std::shared_ptr<int>, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<int>, std::list>::operator()(const Json::ArrayBase<std::shared_ptr<int>, std::list>& array);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetArrayElements<std::shared_ptr<std::int64_t>, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::int64_t>, std::list>::operator()(const Json::ArrayBase<std::shared_ptr<std::int64_t>, std::list>& array);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::SetArrayElements(Json& json);
template void SetArrayElements<std::shared_ptr<std::intmax_t>, std::list>::operator()(const Json::ArrayBase<std::shared_ptr<std::intmax_t>, std::list>& array);
#endif

} // namespace Accessor
} // namespace JXXON
