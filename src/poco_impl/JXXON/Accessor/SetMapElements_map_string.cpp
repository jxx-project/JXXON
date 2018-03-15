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
#include <map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::string, std::map>::SetMapElements(Json& json);
template void SetMapElements<std::string, std::map>::operator()(const Json::MapBase<std::string, std::map>& map);

} // namespace Accessor
} // namespace JXXON
