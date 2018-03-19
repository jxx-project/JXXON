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
GetMapElements<float, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float, Polymorphic::Map>::operator()(Json::MapBase<float, Polymorphic::Map>& map) const
{
	populateMap<float, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<float, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<float, Polymorphic::Map>::operator()(Json::MapBase<float, Polymorphic::Map>& map) const;

template<>
GetMapElements<double, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double, Polymorphic::Map>::operator()(Json::MapBase<double, Polymorphic::Map>& map) const
{
	populateMap<double, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<double, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<double, Polymorphic::Map>::operator()(Json::MapBase<double, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON
