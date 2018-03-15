//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/SetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<bool>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<bool>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<bool>, std::unordered_map>& map);

} // namespace Accessor
} // namespace JXXON
