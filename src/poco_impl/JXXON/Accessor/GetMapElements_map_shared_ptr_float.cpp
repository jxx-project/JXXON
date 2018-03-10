//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements_shared_ptr.hpp"
#include <map>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<float>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, std::map>::operator()(Json::MapBase<std::shared_ptr<float>, std::map>& map) const;

template GetMapElements<std::shared_ptr<double>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, std::map>::operator()(Json::MapBase<std::shared_ptr<double>, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
