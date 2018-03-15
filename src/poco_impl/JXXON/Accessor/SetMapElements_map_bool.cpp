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

template SetMapElements<bool, std::map>::SetMapElements(Json& json);
template void SetMapElements<bool, std::map>::operator()(const Json::MapBase<bool, std::map>& map);

} // namespace Accessor
} // namespace JXXON
