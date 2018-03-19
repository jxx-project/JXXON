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
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<float>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<float>, Polymorphic::Map>& map) const;

template GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<double>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<double>, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON
