//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<bool, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, Polymorphic::Map>::operator()(Json::MapBase<bool, Polymorphic::Map>& map) const
{
	populateMap<bool, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<bool, Polymorphic::Map>::operator()(Json::MapBase<bool, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON
