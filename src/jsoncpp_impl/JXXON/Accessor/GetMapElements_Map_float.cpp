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
GetMapElements<float, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<float, Base::Map>::operator()(Base::Map<float>& map) const
{
	populateMap<float, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asFloat();});
}

template GetMapElements<float, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<float, Base::Map>::operator()(Base::Map<float>& map) const;

template<>
GetMapElements<double, Base::Map>::GetMapElements(const Json& json) : json(json)
{
}

template<>
void GetMapElements<double, Base::Map>::operator()(Base::Map<double>& map) const
{
	populateMap<double, Base::Map>(map, json.pimpl->value, [](const ::Json::Value::const_iterator& i){return i->asDouble();});
}

template GetMapElements<double, Base::Map>::GetMapElements(const Json& json);
template void GetMapElements<double, Base::Map>::operator()(Base::Map<double>& map) const;

}} // namespace JXXON::Accessor
