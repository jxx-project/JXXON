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
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<float, std::unordered_map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float, std::unordered_map>::operator()(Json::MapBase<float, std::unordered_map>& map) const
{
	populateMap<float, std::unordered_map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<float, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<float, std::unordered_map>::operator()(Json::MapBase<float, std::unordered_map>& map) const;

template<>
GetMapElements<double, std::unordered_map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double, std::unordered_map>::operator()(Json::MapBase<double, std::unordered_map>& map) const
{
	populateMap<double, std::unordered_map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<double, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<double, std::unordered_map>::operator()(Json::MapBase<double, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
