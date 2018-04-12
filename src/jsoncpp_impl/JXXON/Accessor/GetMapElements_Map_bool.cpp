//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//

#include "JXXON/Base/Map.h"
#include "JXXON/Error.h"
#include "JXXON/Json.h"
#include "JXXON/Json/Impl.h"
#include "JXXON/Accessor/GetMapElements.tcc"
#include <cstdint>

namespace JXXON { namespace Accessor {

template<>
GetMapElements<bool, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<bool, Base::Map>::operator()(Base::Map<bool>& map) const
{
	populateMap<bool, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asBool();});
}

template GetMapElements<bool, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<bool, Base::Map>::operator()(Base::Map<bool>& map) const;

}} // namespace JXXON::Accessor
