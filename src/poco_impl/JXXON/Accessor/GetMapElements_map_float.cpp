//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template GetMapElements<float, std::map>::GetMapElements(const Json& json);
template void GetMapElements<float, std::map>::operator()(Json::MapBase<float, std::map>& map) const;

template GetMapElements<double, std::map>::GetMapElements(const Json& json);
template void GetMapElements<double, std::map>::operator()(Json::MapBase<double, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
