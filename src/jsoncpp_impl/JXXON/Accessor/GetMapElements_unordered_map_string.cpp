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
GetMapElements<std::string, std::unordered_map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::string, std::unordered_map>::operator()(Json::MapBase<std::string, std::unordered_map>& map) const
{
	populateMap<std::string, std::unordered_map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::string, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::string, std::unordered_map>::operator()(Json::MapBase<std::string, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
