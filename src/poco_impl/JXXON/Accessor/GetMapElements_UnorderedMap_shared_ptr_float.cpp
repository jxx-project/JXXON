//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<float>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::shared_ptr<float>, Polymorphic::UnorderedMap>& map) const;

template GetMapElements<std::shared_ptr<double>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::shared_ptr<double>, Polymorphic::UnorderedMap>& map) const;

} // namespace Accessor
} // namespace JXXON
