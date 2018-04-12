//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/UnorderedMap.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<bool, Base::UnorderedMap>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, Base::UnorderedMap>::operator()(Base::UnorderedMap<bool>& map) const
{
	populateMap<bool, Base::UnorderedMap>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, Base::UnorderedMap>::GetMapElements(const Json& json);
template void GetMapElements<bool, Base::UnorderedMap>::operator()(Base::UnorderedMap<bool>& map) const;

}} // namespace JXXON::Accessor
