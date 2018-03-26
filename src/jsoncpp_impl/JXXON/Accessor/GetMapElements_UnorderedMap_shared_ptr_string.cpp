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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON {
namespace Accessor {

template<>
GetMapElements<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>& map) const
{
	populateMap<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>::operator()(Json::MapBase<std::shared_ptr<std::string>, Polymorphic::UnorderedMap>& map) const;

} // namespace Accessor
} // namespace JXXON