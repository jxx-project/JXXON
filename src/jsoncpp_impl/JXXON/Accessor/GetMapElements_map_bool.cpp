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
GetMapElements<bool, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, std::map>::operator()(Json::MapBase<bool, std::map>& map) const
{
	populateMap<bool, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, std::map>::GetMapElements(const Json& json);
template void GetMapElements<bool, std::map>::operator()(Json::MapBase<bool, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
