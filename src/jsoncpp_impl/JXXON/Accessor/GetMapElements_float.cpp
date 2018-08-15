//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<float>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float>::operator()(Json::MapType<float>& map) const
{
	populateMap<float>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i) { return i->asFloat(); });
}

template GetMapElements<float>::GetMapElements(const Json& json);
template void GetMapElements<float>::operator()(Json::MapType<float>& map) const;

template<>
GetMapElements<double>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double>::operator()(Json::MapType<double>& map) const
{
	populateMap<double>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i) { return i->asDouble(); });
}

template GetMapElements<double>::GetMapElements(const Json& json);
template void GetMapElements<double>::operator()(Json::MapType<double>& map) const;

}} // namespace JXXON::Accessor
