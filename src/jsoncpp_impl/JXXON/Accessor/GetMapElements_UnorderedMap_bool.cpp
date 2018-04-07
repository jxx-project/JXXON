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
#include <Polymorphic/UnorderedMap.h>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<bool, Polymorphic::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, bool>& map) const
{
	populateMap<bool, Polymorphic::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, Polymorphic::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<bool, Polymorphic::UnorderedMap>::operator()(Polymorphic::UnorderedMap<std::string, bool>& map) const;

}} // namespace JXXON::Accessor
