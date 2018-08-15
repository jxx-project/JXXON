//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<std::shared_ptr<std::string>>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::string>>::operator()(Json::MapType<std::shared_ptr<std::string>>& map) const
{
	populateMap<std::shared_ptr<std::string>>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i) { return i->asString(); });
}

template GetMapElements<std::shared_ptr<std::string>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::string>>::operator()(Json::MapType<std::shared_ptr<std::string>>& map) const;

}} // namespace JXXON::Accessor
