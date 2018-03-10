//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements_shared_ptr.hpp"
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<float>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<float>, std::unordered_map>& map) const;

template GetMapElements<std::shared_ptr<double>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<double>, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
