//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<float, std::map>::SetMapElements(Json& json);
template void SetMapElements<float, std::map>::operator()(const Json::MapBase<float, std::map>& map);

template SetMapElements<double, std::map>::SetMapElements(Json& json);
template void SetMapElements<double, std::map>::operator()(const Json::MapBase<double, std::map>& map);

} // namespace Accessor
} // namespace JXXON
