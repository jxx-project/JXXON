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
GetMapElements<std::string, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<std::string, Base::Map>::operator()(Base::Map<std::string>& map) const
{
	populateMap<std::string, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asString();});
}

template GetMapElements<std::string, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<std::string, Base::Map>::operator()(Base::Map<std::string>& map) const;

}} // namespace JXXON::Accessor
