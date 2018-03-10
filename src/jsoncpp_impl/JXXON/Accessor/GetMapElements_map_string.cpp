//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Accessor/GetMapElements.hpp"
#include <map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::string, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::string, std::map>::operator()(Json::MapBase<std::string, std::map>& map) const
{
	populateMap<std::string, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::string, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::string, std::map>::operator()(Json::MapBase<std::string, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
