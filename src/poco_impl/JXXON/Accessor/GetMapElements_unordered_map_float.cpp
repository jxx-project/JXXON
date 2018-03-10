//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements.hpp"
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template GetMapElements<float, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<float, std::unordered_map>::operator()(Json::MapBase<float, std::unordered_map>& map) const;

template GetMapElements<double, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<double, std::unordered_map>::operator()(Json::MapBase<double, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
