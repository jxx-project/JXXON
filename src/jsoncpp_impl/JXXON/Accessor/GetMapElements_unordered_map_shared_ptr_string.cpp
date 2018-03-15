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
#include <unordered_map>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::string>, std::unordered_map>& map) const
{
	populateMap<std::shared_ptr<std::string>, std::unordered_map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::string>, std::unordered_map>::operator()(Json::MapBase<std::shared_ptr<std::string>, std::unordered_map>& map) const;

} // namespace Accessor
} // namespace JXXON
