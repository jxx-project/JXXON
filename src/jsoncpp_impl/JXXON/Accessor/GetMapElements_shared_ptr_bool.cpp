//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<std::shared_ptr<bool>>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<bool>>::operator()(Json::MapType<std::shared_ptr<bool>>& map) const
{
	populateMap<std::shared_ptr<bool>>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<std::shared_ptr<bool>>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<bool>>::operator()(Json::MapType<std::shared_ptr<bool>>& map) const;

}} // namespace JXXON::Accessor
