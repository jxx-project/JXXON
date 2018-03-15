//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<bool, std::unordered_map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, std::unordered_map>::operator()(Json::MapBase<bool, std::unordered_map>& map) const
{
	populateMap<bool, std::unordered_map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<bool, std::unordered_map>::operator()(Json::MapBase<bool, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
