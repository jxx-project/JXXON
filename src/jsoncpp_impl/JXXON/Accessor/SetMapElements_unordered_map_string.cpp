//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/SetMapElements.tcc"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::string, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::string, std::unordered_map>::operator()(const Json::MapBase<std::string, std::unordered_map>& map);

} // namespace Accessor
} // namespace JXXON
