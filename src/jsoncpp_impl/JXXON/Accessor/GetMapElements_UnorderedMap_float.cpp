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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<float, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, float>& map) const
{
	populateMap<float, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<float, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<float, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, float>& map) const;

template<>
GetMapElements<double, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, double>& map) const
{
	populateMap<double, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<double, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<double, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, double>& map) const;

}} // namespace JXXON::Accessor