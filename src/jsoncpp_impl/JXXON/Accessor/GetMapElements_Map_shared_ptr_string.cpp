//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Json.h"
#include "JXXON/Error.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements_shared_ptr.tcc"
#include <cstdint>
#include <Polymorphic/Map.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<std::string>, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::string>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<std::string>, Polymorphic::Map>& map) const
{
	populateMap<std::shared_ptr<std::string>, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::shared_ptr<std::string>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::string>, Polymorphic::Map>::operator()(Json::MapBase<std::shared_ptr<std::string>, Polymorphic::Map>& map) const;

} // namespace Accessor
} // namespace JXXON
