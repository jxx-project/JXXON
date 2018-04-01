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
GetMapElements<std::shared_ptr<bool>, Polymorphic::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::shared_ptr<bool>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<bool> >& map) const
{
	populateMap<std::shared_ptr<bool>, Polymorphic::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<std::shared_ptr<bool>, Polymorphic::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::shared_ptr<bool>, Polymorphic::Map>::operator()(Polymorphic::Map< std::string, std::shared_ptr<bool> >& map) const;

} // namespace Accessor
} // namespace JXXON
