//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.hpp"
#include "JXXON/Error.hpp"
#include "JXXON/Json/Impl.hpp"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<bool>, std::map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<bool>, std::map>::operator()(Json::MapBase<std::shared_ptr<bool>, std::map>& map) const
{
	populateMap<std::shared_ptr<bool>, std::map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<std::shared_ptr<bool>, std::map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<bool>, std::map>::operator()(Json::MapBase<std::shared_ptr<bool>, std::map>& map) const;

} // namespace Accessor
} // namespace JXXON
