//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements.hpp"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<float, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float, std::map>::operator()(Json::MapBase<float, std::map>& map) const
{
	populateMap<float, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<float, std::map>::GetMapElements(const Json& json);
template void GetMapElements<float, std::map>::operator()(Json::MapBase<float, std::map>& map) const;

template<>
GetMapElements<double, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double, std::map>::operator()(Json::MapBase<double, std::map>& map) const
{
	populateMap<double, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<double, std::map>::GetMapElements(const Json& json);
template void GetMapElements<double, std::map>::operator()(Json::MapBase<double, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
