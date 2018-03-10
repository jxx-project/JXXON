//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetMapElements_shared_ptr.hpp"
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<int>, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<int>, std::map>::operator()(const Json::MapBase<std::shared_ptr<int>, std::map>& map);

#if _SIZEOF_INT64_T != _SIZEOF_INT
template SetMapElements<std::shared_ptr<std::int64_t>, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::int64_t>, std::map>::operator()(const Json::MapBase<std::shared_ptr<std::int64_t>, std::map>& map);
#endif

#if _SIZEOF_INTMAX_T != _SIZEOF_INT && _SIZEOF_INTMAX_T != _SIZEOF_INT64_T
template SetMapElements<std::shared_ptr<std::intmax_t>, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<std::intmax_t>, std::map>::operator()(const Json::MapBase<std::shared_ptr<std::intmax_t>, std::map>& map);
#endif

} // namespace Accessor
} // namespace JXXON
