//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/SetMapElements_shared_ptr.hpp"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template SetMapElements<std::shared_ptr<float>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<float>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<float>, std::unordered_map>& map);

template SetMapElements<std::shared_ptr<double>, std::unordered_map>::SetMapElements(Json& json);
template void SetMapElements<std::shared_ptr<double>, std::unordered_map>::operator()(const Json::MapBase<std::shared_ptr<double>, std::unordered_map>& map);

} // namespace Accessor
} // namespace JXXON
